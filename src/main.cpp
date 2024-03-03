#include "Analysis.hpp"
#include "ImageIO.hpp"
#include <iostream>

int main() {
    // Linear movement stuff
    // cv::Rect cropped_roi(cv::Point(0, 1600), cv::Point(3200, 4100));
    // cv::Rect templ_roi(cv::Point(550, 1000), cv::Point(1250, 1650));

    std::string const dir =
        "/home/augustus/Projects/stage_movement_image_analysis/calibration/ms_50/"
        "cycle/auto1_2/";

    std::vector<cv::Mat> images = read_all_images_in_directory(dir);

    return 0;
}
