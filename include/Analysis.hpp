#pragma once

#include <opencv4/opencv2/core.hpp>
#include <utility>

void iterate_through_template_matching(std::vector<cv::Mat> images, cv::Rect cropped_roi,
                                       cv::Rect templ_roi);

template <typename T> std::vector<std::pair<int, T>> enumerate(std::vector<T> vec) {
    std::vector<std::pair<int, T>> out(vec.size());
    for (int i = 0; i < vec.size(); i++) {
        out[i] = std::pair<int, T>(i, vec[i]);
    }
    return out;
}
