#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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

void findReachable(const vector<vector<int>>& map, int startX, int startY) {
    int rows = map.size();
    int cols = map[0].size();
    
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<int, int>> q;
    
    q.push({startX, startY});
    visited[startX][startY] = true;
    
    cout << "Positions reachable from (" << startX << "," << startY << "):" << endl;
    
    int count = 0;
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        
        cout << "(" << current.first << "," << current.second << ") ";
        count++;
        if (count % 5 == 0) cout << endl;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                !visited[nx][ny] && map[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    cout << endl << "Total reachable positions: " << count << endl;
}

int main() {
    vector<vector<int>> map = readMap("map.txt");
    findReachable(map, 0, 0);
    return 0;
}
