#!/bin/bash
# 编译红色装甲板检测程序
g++ -o red_armor_detector red_armor_detector.cpp `pkg-config --cflags --libs opencv4` -std=c++11
