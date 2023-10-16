#pragma once


#include <cmath>
#include <string>
#include <opencv2/opencv.hpp>
#include "Interact.h"


int findEdge(cv::Mat img, int col, std::pair<int, int> rows, std::string window_name);
int findEdge(cv::Mat img, int col, std::pair<int, int> rows);
std::vector<int> getDifference(std::vector<int> input);

template<typename T>
double getVectorAverage(std::vector<T> input) {
    double sum = 0;
    for (int i = 0; i < input.size(); i++) {
        sum = sum + input[i];
    }
    return sum / input.size();
}

template<typename T>
double getVectorStd(std::vector<T> input) {
    double mean = getVectorAverage(input);

    double sum_diff_squared = 0;
    for (int i = 0; i < input.size(); i++) {
        sum_diff_squared = sum_diff_squared + (mean - input[i]) * (mean - input[i]);
    }

    return std::sqrt(sum_diff_squared / (input.size() - 1));
}
