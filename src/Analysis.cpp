#include "Analysis.hpp"

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>

void iterate_through_template_matching(std::vector<cv::Mat> images, cv::Rect cropped_roi,
                                       cv::Rect templ_roi) {
    cv::Mat cropped_original_image = images[0](cropped_roi);

    cv::Mat templ = cropped_original_image(templ_roi);

    cv::Mat result(cropped_original_image.rows - templ.rows + 1,
                   cropped_original_image.cols - templ.cols + 1, CV_32FC1);

    double minval, maxval;
    cv::Point minloc, maxloc;
    cv::Mat temp_img;
    for (auto image : images) {
        image(cropped_roi).copyTo(temp_img);
        cv::matchTemplate(image(cropped_roi), templ, result, cv::TM_CCORR_NORMED);
        cv::minMaxLoc(result, &minval, &maxval, &minloc, &maxloc);
    }
}
