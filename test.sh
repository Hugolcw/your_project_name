#!/bin/bash

echo "=== RoboMaster 视觉组入选题目测试 ==="
echo ""

echo "1. 测试指令分析器 (任务3)..."
cd task3_commands
./command_analyzer commands.log
cd ..

echo ""
echo "2. 测试路径搜索 (任务4)..."
cd task4_navigation
./path_finder map.txt 0 0 2 0
cd ..

echo ""
echo "3. 测试视觉任务 (任务5)..."
echo "请手动运行以下命令："
echo "cd task5_vision/task5_1_color_detection && ./red_armor_detector ../test_images/test_red_armor.jpg"
echo "cd task5_vision/task5_2_rune_detection && ./rune_detector ../test_images/test_rune.png"

echo ""
echo "=== 测试完成 ==="
echo "注：任务1（理论题）请在 task1_theory/README.md 中回答"
echo "注：任务2（Hello World）程序在 task2_tools/ 目录中"
