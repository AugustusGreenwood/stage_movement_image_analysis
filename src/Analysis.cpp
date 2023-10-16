#include "Analysis.h"

int findEdge(cv::Mat img, int col, std::pair<int, int> rows, std::string window_name) {
    cv::Mat gray_img, blurred_img;
    cv::cvtColor(img, gray_img, cv::COLOR_RGB2GRAY);
    cv::GaussianBlur(gray_img, blurred_img, cv::Size(15, 1), 0, 0);

    cv::Rect rect(2360, 0, 3, 3);
    cv::Scalar color(0, 0, 255);
    cv::Rect roi(2310, 4426, 100, 100);
    cv::Mat temp_img;
    for (int i = rows.first; i >= rows.second; --i) {
        img.copyTo(temp_img);
        rect.y = i-1;

        int pixel = (int)blurred_img.ptr<uchar>(i-1)[col-1];

        if (pixel <= 20) {
            std::cout << i << std::endl;
            cv::rectangle(temp_img, rect, cv::Scalar(0, 255, 0), 1);
            displayImage(temp_img(roi), window_name);
            cv::waitKey(100);
            return i;
        }

        cv::rectangle(temp_img, rect, color, 1);
        displayImage(temp_img(roi), window_name);
        cv::waitKey(50);
    }
    std::cout << "Couldn't find edge" << std::endl;
    return -1;
}

int findEdge(cv::Mat img, int col, std::pair<int, int> rows) {
    cv::Mat gray_img, blurred_img;
    cv::cvtColor(img, gray_img, cv::COLOR_RGB2GRAY);
    cv::GaussianBlur(gray_img, blurred_img, cv::Size(15, 1), 0, 0);

    cv::Rect rect(2360, 0, 3, 3);
    cv::Scalar color(0, 0, 255);
    cv::Rect roi(2310, 4426, 100, 100);
    cv::Mat temp_img;
    for (int i = rows.first; i >= rows.second; --i) {
        rect.y = i-1;
        int pixel = (int)blurred_img.ptr<uchar>(i-1)[col-1];
        if (pixel <= 20) {
            return i; 
        }
    }
    std::cout << "Edge not found" << std::endl;
    return -1;
}


std::vector<int> getDifference(std::vector<int> input) {
    std::vector<int> out(input.size() - 1, 0);
    for (int i = 1; i < input.size(); i++) {
        out[i-1] = abs(input[i] - input[i-1]);
    }
    return out;
}

