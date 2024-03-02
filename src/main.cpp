#include <Interact.h>

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>

#include <opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>

void out_csv(const char *file_name, cv::Mat mat) {
    std::ofstream file;
    file.open(file_name);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            if (j == mat.cols - 1) {
                file << mat.at<float>(i, j);
            } else {
                file << mat.at<float>(i, j) << ",";
            }
        }
        file << std::endl;
    }
    file.close();
}

void iterate_through_template_matching(std::vector<cv::Mat> images, cv::Rect cropped_roi,
                                       cv::Rect templ_roi) {

    // This crops so the images are smaller and hopefully speed things up
    // Also sets up an "original image" which the template is derived from
    cv::Mat cropped_original_image = images[0](cropped_roi);

    // Set up the template
    cv::Mat templ = cropped_original_image(templ_roi);

    // initialize the result. Weird sizes are specific to the algorithm
    cv::Mat result(cropped_original_image.rows - templ.rows + 1,
                   cropped_original_image.cols - templ.cols + 1, CV_32FC1);

    int i = 0;
    char file_name[96];
    // Finally initialize the variables that match template gives
    double minval, maxval;
    cv::Point minloc, maxloc;
    cv::Mat temp_img;
    for (auto image : images) {
        image(cropped_roi).copyTo(temp_img);
        cv::matchTemplate(image(cropped_roi), templ, result, cv::TM_CCORR_NORMED);
        cv::minMaxLoc(result, &minval, &maxval, &minloc, &maxloc);

        std::cout << maxloc.x << " " << maxloc.y << " " << maxval << ";" << std::endl;
        std::sprintf(file_name, "./analysis/linear_movement_result_%i.csv", i);
        out_csv(file_name, result);

        cv::Rect templ_placement(maxloc.x, maxloc.y, templ_roi.width, templ_roi.height);
        cv::rectangle(temp_img, templ_placement, cv::Scalar(255, 0, 0), 20, cv::LINE_AA);
        cv::namedWindow("hello", cv::WINDOW_NORMAL);
        cv::imshow("hello", temp_img);
        cv::waitKey(0);
        cv::destroyWindow("hello");

        cv::Mat result8bit;
        normalize(result, result, 0, 255, cv::NORM_MINMAX, -1, cv::Mat());
        result.convertTo(result8bit, CV_8UC3);
        cv::namedWindow("h", cv::WINDOW_NORMAL);
        cv::imshow("h", result8bit);
        cv::waitKey(0);
        cv::destroyWindow("h");

        i++;
    }
}

int main() {
    // std::vector<cv::Mat> images = getImagesInDirectory(
    //     "/home/augustus/Projects/ImageAnalysis/calibration/ms_50/cycle/auto1_2/");

    // Linear movement stuff
    // cv::Rect cropped_roi(cv::Point(0, 1600), cv::Point(3200, 4100));
    // cv::Rect templ_roi(cv::Point(550, 1000), cv::Point(1250, 1650));
    //

    std::string const dir =
        "/home/augustus/Projects/ImageAnalysis/calibration/ms_50/cycle/auto1_2/";

    std::vector<cv::Mat> images = read_all_images_in_directory(dir);

    for (auto i : images) {
        std::cout << i.empty() << std::endl;
    }

    return 0;
}
