#include "Interact.h"
#include <filesystem>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <thread>

void display_image(cv::Mat const &image, std::string const &window_name) {
    cv::namedWindow(window_name, cv::WINDOW_NORMAL);
    cv::imshow(window_name, image);
}

bool string_ends_with(std::string const &str, std::string const &end) {
    if (end.size() > str.size()) {
        return false;
    } else {
        return std::equal(end.rbegin(), end.rend(), str.rbegin());
    }
}

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
    std::sort(img_paths.begin(), img_paths.end(), [](std::string a, std::string b) {
        return extract_last_integer_from_string(a) < extract_last_integer_from_string(b);
    });
}

std::vector<std::string> get_image_paths_in_directory(std::string const &dir_path) {
    std::vector<std::string> img_files;
    for (const std::filesystem::directory_entry &entry :
         std::filesystem::directory_iterator(dir_path)) {
        if (string_ends_with(entry.path(), ".JPG")) {
            img_files.push_back(entry.path());
        }
    }
    return img_files;
}

void _read_images_into_mat(std::vector<std::string> const &img_paths, std::vector<cv::Mat> *image) {
    for (int i = 0; i < img_paths.size(); i++) {
        image->push_back(cv::imread(img_paths[i], cv::IMREAD_ANYDEPTH | cv::IMREAD_GRAYSCALE));
    }
}

std::vector<cv::Mat> read_all_images_in_directory(const std::string &dir_path, int nthreads) {
    std::vector<std::string> img_paths = get_image_paths_in_directory(dir_path);
    _sort_image_paths(img_paths);
    std::vector<std::vector<std::string>> split_img_paths = split_vector(img_paths, nthreads);

    std::vector<std::vector<cv::Mat>> split_imgs(nthreads);

    std::vector<std::thread> threads(nthreads);
    for (int i = 0; i < nthreads; i++) {
        threads[i] = std::thread(_read_images_into_mat, split_img_paths[i], &split_imgs[i]);
    }

    for (int i = 0; i < nthreads; i++) {
        threads[i].join();
    }

    return collect_vector(split_imgs);
}
