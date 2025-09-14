#!/bin/bash
# 编译能量机关检测程序
g++ -o rune_detector rune_detector.cpp `pkg-config --cflags --libs opencv4` -std=c++11
