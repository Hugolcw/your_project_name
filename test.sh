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
