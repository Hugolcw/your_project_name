#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<vector<int>> readMap(const string& filename) {
    ifstream file(filename);
    vector<vector<int>> map;
    string line;
    
    while (getline(file, line)) {
        if (line.empty()) continue;
        vector<int> row;
        istringstream iss(line);
        int value;
        while (iss >> value) {
            row.push_back(value);
        }
        map.push_back(row);
    }
    return map;
}

int main() {
    vector<vector<int>> map = readMap("map.txt");
    cout << "Map size: " << map.size() << "x" << (map.empty() ? 0 : map[0].size()) << endl;
    
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            cout << "(" << i << "," << j << "): " << map[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}
