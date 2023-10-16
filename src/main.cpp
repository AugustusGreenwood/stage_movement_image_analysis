#include <opencv2/core/hal/interface.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include "Interact.h"
#include "Analysis.h"

std::vector<cv::Mat> convertToGrayScale(std::vector<cv::Mat> mat_vec) {
    std::vector<cv::Mat> out(mat_vec);
    for (int i = 0; i < mat_vec.size(); i++) {
        cv::cvtColor(mat_vec[i], out[i], cv::COLOR_BGR2GRAY);
    }
    return out;
}

int main() {
    std::vector<cv::Mat> images = getImagesInDirectory("/home/augustusg/Projects/ImageAnalysis/calibration/ms_0/cycle/auto1_2/");
    
    std::vector<int> edges(images.size(), 0);
    for (int i = 0; i < images.size(); i++) {
        edges[i] = findEdge(images[i], 2361, std::pair(4500, 4400));
    }

    std::vector<int> diff = getDifference(edges);

    for (auto d : diff) {
        std::cout << d << std::endl;
    }

    std::cout << getVectorAverage(diff) << '\t' <<  getVectorStd(diff) << std::endl;

    cv::Mat gray_mat, blurred_mat;
    cv::cvtColor(images[0], gray_mat, cv::COLOR_RGB2GRAY);
    cv::GaussianBlur(gray_mat, blurred_mat, cv::Size(15, 1), 0, 0);
    displayImage(blurred_mat, "NAME");
    cv::waitKey(0);

    return 0;
}
