#include <opencv2/opencv.hpp>
#include <iostream>

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

    // 转换到HSV色彩空间
    Mat hsvImage;
    cvtColor(image, hsvImage, COLOR_BGR2HSV);

    // 定义红色的HSV范围（通常需要根据实际情况调整）
    // 红色在HSV中有两个范围（因为红色在色相环的两端）
    Scalar lower_red1(0, 100, 100);
    Scalar upper_red1(10, 255, 255);
    Scalar lower_red2(160, 100, 100);
    Scalar upper_red2(180, 255, 255);

    // 创建掩码
    Mat mask1, mask2, redMask;
    inRange(hsvImage, lower_red1, upper_red1, mask1);
    inRange(hsvImage, lower_red2, upper_red2, mask2);
    bitwise_or(mask1, mask2, redMask);

    // 显示结果
    namedWindow("Original Image", WINDOW_NORMAL);
    namedWindow("Red Mask", WINDOW_NORMAL);
    
    imshow("Original Image", image);
    imshow("Red Mask", redMask);

    cout << "Press any key to exit..." << endl;
    waitKey(0);

    return 0;
}
