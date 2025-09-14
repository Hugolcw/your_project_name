#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

int main(int argc, char* argv[]) {
    // 检查命令行参数
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log_file_path>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);
    
    // 检查文件是否成功打开
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return 1;
    }

    // 使用unordered_map来统计每种指令的出现次数
    std::unordered_map<std::string, int> command_count;
    std::string line;

    // 逐行读取文件并统计指令
    while (std::getline(file, line)) {
        // 跳过空行
        if (line.empty()) continue;
        
        // 统计指令出现次数
        command_count[line]++;
    }

    file.close();

    // 打印统计结果
    std::cout << "Command execution statistics:" << std::endl;
    std::cout << "============================" << std::endl;
    
    for (const auto& pair : command_count) {
        std::cout << pair.first << ": " << pair.second << " times" << std::endl;
    }

    return 0;
}
