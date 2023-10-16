#include "Interact.h"
#include <opencv2/imgcodecs.hpp>

cv::Mat loadImage(const std::string &image_path) {
    cv::Mat image = cv::imread(image_path);
    if (image.empty()) {
        std::cout << image_path << std::endl;
        std::cerr << "Error: Could not open or find the image" << std::endl;
    }
    return image;
}
void displayImage(const cv::Mat &image, const std::string &window_name) {
    namedWindow(window_name, cv::WINDOW_NORMAL);
    imshow(window_name, image);
}
void saveImage(const cv::Mat &image, const std::string &output_path) {
    imwrite(output_path, image);
    std::cout << "Image saved as: " << output_path << std::endl;
}
bool fileIsImage(std::string const &file) {
    return (0 == file.compare(file.length() - 4, 4, ".JPG"));
}
std::vector<cv::Mat> getImagesInDirectory(std::string directory) {
    std::vector<cv::Mat> out;
    std::vector<std::pair<std::string, std::future<cv::Mat>>> futures;
    std::string file;

    for (const auto &entry : std::filesystem::directory_iterator(directory)) {
        file = entry.path();
        if (file.compare(file.size() - 4, 4, ".JPG") == 0) {
            futures.emplace_back(file.substr(file.size() - 8, 4), std::async(std::launch::async, loadImage, entry.path()));
        }
    }
    
    std::sort(futures.begin(), futures.end(), 
            [](const auto &a, const auto &b) { return std::stoi(a.first) < std::stoi(b.first); });

    for (auto &pair : futures) {
        out.push_back(pair.second.get());
    }

    return out;
}
void mouseCallback(int event, int x, int y, int flags, void* param) {
    if (event == cv::EVENT_LBUTTONDOWN) {
        std::cout << x << ", " << y << std::endl;
    }
}

