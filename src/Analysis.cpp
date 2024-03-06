#include <ImageIO.hpp>
#include <fstream>
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>

void iterate_through_template_matching(std::vector<cv::Mat> images,
                                       cv::Rect cropped_roi,
                                       cv::Rect templ_roi) {
    cv::Mat cropped_original_image = images[0](cropped_roi);

    cv::Mat templ = cropped_original_image(templ_roi);

    cv::Mat result(cropped_original_image.rows - templ.rows + 1,
                   cropped_original_image.cols - templ.cols + 1,
                   CV_32FC1);

    std::ofstream file;
    file.open("./analysis/cycle/cycle_pixels.csv");
    double minval, maxval;
    cv::Point minloc, maxloc;
    cv::Mat temp_img;
    int i = 1;
    for (auto image : images) {
        image(cropped_roi).copyTo(temp_img);
        cv::matchTemplate(image(cropped_roi), templ, result,
                          cv::TM_CCORR_NORMED);
        cv::minMaxLoc(result, &minval, &maxval, &minloc, &maxloc);

        if (i == 1 || i == 2) {
            cv::Rect rect(maxloc.x, maxloc.y, templ.cols, templ.rows);
            cv::rectangle(temp_img, rect, cv::Scalar(255, 0, 0), 30,
                          cv::LINE_AA);
            display_image(temp_img, "HELLO");
            cv::waitKey(0);
            cv::destroyWindow("HELLO");

            char filename[64];
            sprintf(filename, "./analysis/cycle/cycle_%i.csv", i);
            /* write_float_csv(filename, result, ','); */
        }

        file << maxloc.x << ',' << maxloc.y << ',' << maxval
             << std::endl;

        std::cout << maxloc.x << ',' << maxloc.y << ',' << maxval
                  << std::endl;
        i++;
    }
    file.close();
}

void perform_linear_cycle_template_match() {
    // Directory for 100 images in a cycle
    std::string const cycle_dir =
        "/home/augustus/Projects/stage_movement_image_analysis/"
        "calibration/ms_50/"
        "cycle/auto1_2/";

    // Directory for linear movement
    std::string const linear_dir = "/home/augustus/Projects/"
                                   "stage_movement_image_analysis/"
                                   "calibration/ms_50/large/trail4/";

    std::vector<cv::Mat> cycle_imgs =
        read_all_images_in_directory(cycle_dir);
    std::vector<cv::Mat> linear_imgs =
        read_all_images_in_directory(linear_dir);

    // A roi which is cropped for all images
    cv::Rect cropped_roi(cv::Point(0, 1800), cv::Point(6335, 5000));

    // Linear movemnt template
    cv::Rect linear_templ(cv::Point(600, 800), cv::Point(1200, 1400));
    // Cycle movement template
    cv::Rect cycle_templ(cv::Point(4050, 1900),
                         cv::Point(5900, 2600));

    // Actually do the template matching
    iterate_through_template_matching(cycle_imgs, cropped_roi,
                                      cycle_templ);
    /* iterate_through_template_matching(linear_imgs, cropped_roi, */
    /*                                   linear_templ); */
}
