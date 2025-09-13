#!/bin/bash

echo "Building programs..."
cd ~/your_project_name

# 编译指令分析器
echo "1. Building command analyzer..."
g++ -o command_analyzer command_analyzer.cpp -Wall

# 编译路径搜索器
echo "2. Building path finder..."
g++ -o path_finder path_finder.cpp -Wall

echo "--------------------------------------------"
echo "Testing command analyzer:"
echo "--------------------------------------------"
./command_analyzer commands.log

echo ""
echo "--------------------------------------------"
echo "Testing path finder (from (0,0) to (2,0)):"
echo "--------------------------------------------"
./path_finder map.txt 0 0 2 0

echo ""
echo "--------------------------------------------"
echo "Testing path finder (impossible path from (0,0) to (0,2)):"
echo "--------------------------------------------"
./path_finder map.txt 0 0 0 2

echo "--------------------------------------------"
echo "All tests completed."
echo ""
echo "============================================"
echo "视觉任务需要手动运行（涉及图像显示窗口）"
echo "请先安装OpenCV: sudo apt install libopencv-dev"
echo "然后进入对应目录编译和运行："
echo ""
echo "颜色识别:"
echo "  cd task5_vision/task5_1_color_detection"
echo "  ./compile.sh"
echo "  ./red_armor_detector <图片路径>"
echo ""
echo "能量机关检测:"
echo "  cd task5_vision/task5_2_rune_detection"
echo "  ./compile.sh"
echo "  ./rune_detector <图片路径>"
echo "============================================"
