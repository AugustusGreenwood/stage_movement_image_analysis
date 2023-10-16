#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <future>
#include <filesystem>

cv::Mat loadImage(const std::string& image_path);

void displayImage(const cv::Mat& image, const std::string& windowName = "Image");

void saveImage(const cv::Mat& image, const std::string& outputPath = "output_image.jpg");

std::vector<cv::Mat> getImagesInDirectory(std::string directory);

void mouseCallback(int event, int x, int y, int flags, void* param);