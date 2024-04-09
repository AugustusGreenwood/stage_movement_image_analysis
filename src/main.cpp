#include "ImageIO.hpp"
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

int main() {
    cv::Rect cropped_roi(cv::Point(0, 1800), cv::Point(6335, 5000));
    cv::Mat image, cropped, gauss, sobel, abs_sobel;
    image = cv::imread("/home/augustus/Projects/stage_movement_image_analysis/"
                       "calibration/ms_50/cycle/auto1_2/DSC07231.JPG",
                       cv::IMREAD_GRAYSCALE | cv::IMREAD_ANYDEPTH);

    cropped = image(cropped_roi);
    cv::imwrite("cropped.bmp", cropped);

    cv::GaussianBlur(cropped, gauss, cv::Size(5, 5), 0);
    cv::imwrite("gauss.bmp", gauss);

    cv::Sobel(gauss, sobel, CV_8UC1, 0, 1);
    cv::convertScaleAbs(sobel, abs_sobel);
    cv::imwrite("sobel.bmp", sobel);
    cv::imwrite("sobel_abs.bmp", abs_sobel);

    cv::Mat a, b, c, d, e;

    cv::threshold(abs_sobel, a, 254, 255, cv::THRESH_BINARY);
    cv::imwrite("try.bmp", a);

    display_image(a, "HELLO");
    cv::waitKey(0);

    //     write_csv_uchar("./analysis/ruler_calibration/abs_sobel_4000.csv", abs_sobel.col(4000),
    //     ',');
    // write_csv_uchar("./analysis/ruler_calibration/abs_sobel_thresh_4000.csv",
    // abs_sobel.col(4000) == 255, ',');

    cv::destroyAllWindows();
    return 0;
}

// abs_sobel_4000.csv  abs_sobel.csv  abs_sobel_thresh_4000.csv  abs_sobel_thresh.csv  blurr.bmp
// cropped.bmp  sobel.bmp  sobel.csv  sobel_thres.bmp  sobel_thresh.csv
