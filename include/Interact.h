#pragma once
#include <opencv4/opencv2/core.hpp>

void display_image(cv::Mat const &image, std::string const &window_name);

bool string_ends_with(std::string const &value, std::string const &ending);

std::vector<std::string> get_image_paths_in_directory(std::string const &dir_path);

int extract_first_integer_from_string(std::string const &str);

int extract_last_integer_from_string(std::string const &str);

std::vector<cv::Mat> read_all_images_in_directory(const std::string &dir_path, int nthreads = 4);

template <typename T> std::vector<std::vector<T>> split_vector(std::vector<T> vec, int splits) {
    int split_size = vec.size() / splits;

    std::vector<std::vector<T>> out;
    for (int i = 0; i < splits; i++) {
        if (i != splits - 1) {
            out.emplace_back(std::vector<T>(vec.begin() + i * split_size,
                                            vec.begin() + i * split_size + split_size));
        } else {
            out.emplace_back(std::vector<T>(vec.begin() + i * split_size, vec.end()));
        }
    }

    return out;
}

template <typename T> std::vector<T> collect_vector(std::vector<std::vector<T>> nested_vec) {
    int nested_size = nested_vec.size();

    std::vector<T> out;
    for (int i = 0; i < nested_size; i++) {
        for (int j = 0; j < nested_vec[i].size(); j++) {
            out.push_back(nested_vec[i][j]);
        }
    }

    return out;
}
