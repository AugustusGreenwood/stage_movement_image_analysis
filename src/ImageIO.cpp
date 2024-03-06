#include "ImageIO.hpp"
#include <filesystem>
#include <fstream>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <thread>

void display_image(cv::Mat const &image,
                   std::string const &window_name) {
    cv::namedWindow(window_name, cv::WINDOW_NORMAL);
    cv::imshow(window_name, image);
}

bool string_ends_with(std::string const &str,
                      std::string const &end) {
    if (end.size() > str.size()) {
        return false;
    } else {
        return std::equal(end.rbegin(), end.rend(), str.rbegin());
    }
}

// I probably won't need this but it was easy to implement after
// extract_last*
int extract_first_integer_from_string(std::string const &str) {
    std::string out;
    std::string::const_iterator it;
    for (it = str.begin(); it != str.end(); it++) {
        if (out.empty() == false && std::isdigit(*it) == false) {
            break;
        } else if (std::isdigit(*it)) {
            out.push_back(*it);
        }
    }
    return std::stoi(out);
}

int extract_last_integer_from_string(std::string const &str) {
    std::string out;
    std::string::const_iterator it;
    for (it = str.end(); it != str.begin(); it--) {
        if (out.empty() == false && std::isdigit(*it) == false) {
            break;
        } else if (std::isdigit(*it)) {
            out.insert(out.begin(), *it);
        }
    }
    return std::stoi(out);
}

void _sort_image_paths(std::vector<std::string> &img_paths) {
    std::sort(img_paths.begin(), img_paths.end(),
              [](std::string a, std::string b) {
                  return extract_last_integer_from_string(a) <
                         extract_last_integer_from_string(b);
              });
}

std::vector<std::string>
get_image_paths_in_directory(std::string const &dir_path) {
    std::vector<std::string> img_files;
    for (const std::filesystem::directory_entry &entry :
         std::filesystem::directory_iterator(dir_path)) {
        if (string_ends_with(entry.path(), ".JPG")) {
            img_files.push_back(entry.path());
        }
    }
    return img_files;
}

// Used exclusively in read_all_images_in_directory
void _read_images_into_mat(std::vector<std::string> const &img_paths,
                           std::vector<cv::Mat> *image) {
    for (int i = 0; i < img_paths.size(); i++) {
        image->push_back(
            cv::imread(img_paths[i],
                       cv::IMREAD_ANYDEPTH | cv::IMREAD_GRAYSCALE));
    }
}

// Reading all 100 images can take like ~20 second. So I start a
// thread pool with nthreads and read in threads. Tested and 4 was
// about the fastest. Wish I could find a way to not use push_bakc in
// _read_images_into_mat for better speed, but cant seem to get that
// to work
std::vector<cv::Mat>
read_all_images_in_directory(const std::string &dir_path,
                             int nthreads) {
    std::vector<std::string> img_paths =
        get_image_paths_in_directory(dir_path);
    _sort_image_paths(img_paths);
    std::vector<std::vector<std::string>> split_img_paths =
        split_vector(img_paths, nthreads);

    std::vector<std::vector<cv::Mat>> split_imgs(nthreads);

    std::vector<std::thread> threads(nthreads);
    for (int i = 0; i < nthreads; i++) {
        threads[i] = std::thread(_read_images_into_mat,
                                 split_img_paths[i], &split_imgs[i]);
    }

    for (int i = 0; i < nthreads; i++) {
        threads[i].join();
    }

    return collect_vector(split_imgs);
}

// Chose to just tke a psudo-functional approach to outputting floats
// and integers. The alternative is to using mat.type but this would
// require a couple of if-else blocks and this is just easier.
void write_float_csv(std::string const file_name, cv::Mat const mat,
                     char const delim) {
    std::ofstream file;
    file.open(file_name);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            if (j == mat.cols - 1) {
                file << mat.at<float>(i, j);
            } else {
                file << mat.at<float>(i, j) << delim;
            }
        }
        file << std::endl;
    }
    file.close();
}
