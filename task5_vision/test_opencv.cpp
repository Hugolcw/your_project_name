#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    
    // 测试基本的OpenCV功能
    cv::Mat testImage(100, 100, CV_8UC3, cv::Scalar(255, 0, 0));
    std::cout << "Created test image with size: " << testImage.cols << "x" << testImage.rows << std::endl;
    
    std::cout << "OpenCV test successful!" << std::endl;
    return 0;
}
