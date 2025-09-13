#!/bin/bash

echo "Building command analyzer..."
cd ~/your_project_name

# 编译程序
g++ -o command_analyzer command_analyzer.cpp -Wall

echo "Running command analyzer with commands.log..."
echo "--------------------------------------------"

# 运行程序，传入commands.log作为参数
./command_analyzer commands.log

echo "--------------------------------------------"
echo "Test completed."
