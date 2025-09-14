#!/bin/bash

echo "=== Vision Tasks Test ==="
echo ""

# 创建测试图片
echo "1. Creating test images..."
cd test_images
g++ -o create_test_images create_test_images.cpp `pkg-config --cflags --libs opencv4`
./create_test_images
cd ..

echo ""
echo "2. Testing color detection..."
cd task5_vision/task5_1_color_detection
./red_armor_detector ../../test_images/test_red_armor.jpg

echo ""
echo "3. Testing rune detection..."
cd ../task5_2_rune_detection
./rune_detector ../../test_images/test_rune.png

echo ""
echo "=== Test Completed ==="
