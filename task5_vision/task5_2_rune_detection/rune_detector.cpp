#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    // 检查命令行参数
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <image_path>" << endl;
        return -1;
    }

    // 读取图像
    Mat image = imread(argv[1]);
    if (image.empty()) {
        cout << "Error: Could not open or find the image!" << endl;
        return -1;
    }

    // 转换为灰度图并二值化
    Mat grayImage, binaryImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    threshold(grayImage, binaryImage, 100, 255, THRESH_BINARY);

    // 查找轮廓
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(binaryImage, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // 寻找圆形轮廓
    int bestContourIndex = -1;
    double bestCircularity = 0;

    for (size_t i = 0; i < contours.size(); i++) {
        double area = contourArea(contours[i]);
        if (area < 1000) continue; // 过滤小面积轮廓

        double perimeter = arcLength(contours[i], true);
        double circularity = 4 * 3.1416 * area / (perimeter * perimeter);

        if (circularity > 0.7 && circularity > bestCircularity) {
            bestCircularity = circularity;
            bestContourIndex = i;
        }
    }

    // 绘制检测结果
    Mat resultImage = image.clone();
    
    if (bestContourIndex != -1) {
        Rect boundingBox = boundingRect(contours[bestContourIndex]);
        rectangle(resultImage, boundingBox, Scalar(0, 255, 0), 3);
        cout << "Found circular object!" << endl;
    } else {
        cout << "No circular object found!" << endl;
    }

    // 显示结果
    namedWindow("Detection Result", WINDOW_NORMAL);
    imshow("Detection Result", resultImage);

    cout << "Press any key to exit..." << endl;
    waitKey(0);

    return 0;
}
