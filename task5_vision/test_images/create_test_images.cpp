#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 创建红色测试图片（100x100像素，纯红色）
    Mat redImage(100, 100, CV_8UC3, Scalar(0, 0, 255)); // BGR格式：蓝色=0, 绿色=0, 红色=255
    imwrite("test_red_armor.jpg", redImage);
    cout << "Created test_red_armor.jpg" << endl;

    // 创建能量机关测试图片（白色背景，黑色圆形）
    Mat circleImage(100, 100, CV_8UC3, Scalar(255, 255, 255)); // 白色背景
    circle(circleImage, Point(50, 50), 20, Scalar(0, 0, 0), -1); // 黑色实心圆形
    imwrite("test_rune.png", circleImage);
    cout << "Created test_rune.png" << endl;

    // 验证图片是否创建成功
    Mat testRead1 = imread("test_red_armor.jpg");
    Mat testRead2 = imread("test_rune.png");
    
    if (testRead1.empty() || testRead2.empty()) {
        cout << "Error: Failed to create test images!" << endl;
        return -1;
    }

    cout << "Test images created successfully!" << endl;
    cout << "Red image size: " << testRead1.cols << "x" << testRead1.rows << endl;
    cout << "Circle image size: " << testRead2.cols << "x" << testRead2.rows << endl;

    return 0;
}
