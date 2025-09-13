#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>  // 添加这一行
using namespace std;

// 定义坐标点结构体
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// 定义移动方向：上、右、下、左
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// 读取地图文件
vector<vector<int>> readMap(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error: Could not open map file");
    }

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
    
    file.close();
    return map;
}

// 打印地图和路径
void printMapWithPath(const vector<vector<int>>& map, 
                     const vector<Point>& path, 
                     const Point& start, 
                     const Point& goal) {
    // 创建地图副本
    vector<vector<char>> displayMap(map.size(), vector<char>(map[0].size()));
    
    // 初始化显示地图
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            displayMap[i][j] = map[i][j] == 1 ? '1' : '0';
        }
    }
    
    // 标记路径（跳过起点和终点，后面会特殊标记）
    for (size_t i = 1; i < path.size() - 1; i++) {
        displayMap[path[i].x][path[i].y] = '*';
    }
    
    // 标记起点和终点
    displayMap[start.x][start.y] = 'S';
    displayMap[goal.x][goal.y] = 'G';
    
    // 打印地图
    cout << "Map with path:" << endl;
    for (const auto& row : displayMap) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// BFS寻路算法
vector<Point> findPathBFS(const vector<vector<int>>& map, 
                         const Point& start, 
                         const Point& goal) {
    int rows = map.size();
    int cols = map[0].size();
    
    // 检查起点和终点是否有效
    if (start.x < 0 || start.x >= rows || start.y < 0 || start.y >= cols ||
        goal.x < 0 || goal.x >= rows || goal.y < 0 || goal.y >= cols) {
        throw out_of_range("Error: Start or goal position out of map bounds");
    }
    
    if (map[start.x][start.y] == 1) {
        throw runtime_error("Error: Start position is obstacle");
    }
    
    if (map[goal.x][goal.y] == 1) {
        throw runtime_error("I can't go to the position (" + 
                           to_string(goal.x) + "," + to_string(goal.y) + ").");
    }
    
    // BFS数据结构
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<Point>> parent(rows, vector<Point>(cols, Point(-1, -1)));
    queue<Point> q;
    
    q.push(start);
    visited[start.x][start.y] = true;
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        // 如果找到目标，回溯路径
        if (current == goal) {
            vector<Point> path;
            Point p = goal;
            
            while (!(p == start)) {
                path.push_back(p);
                p = parent[p.x][p.y];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }
        
        // 尝试四个方向
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                !visited[nx][ny] && map[nx][ny] == 0) {
                visited[nx][ny] = true;
                parent[nx][ny] = current;
                q.push(Point(nx, ny));
            }
        }
    }
    
    // 如果没有找到路径
    throw runtime_error("I can't go to the position (" + 
                       to_string(goal.x) + "," + to_string(goal.y) + ").");
}

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "Usage: " << argv[0] << " <map_file> <start_x> <start_y> <goal_x> <goal_y>" << endl;
        return 1;
    }
    
    try {
        // 解析参数
        string mapFile = argv[1];
        Point start(stoi(argv[2]), stoi(argv[3]));
        Point goal(stoi(argv[4]), stoi(argv[5]));
        
        // 读取地图
        vector<vector<int>> map = readMap(mapFile);
        
        // 寻找路径
        vector<Point> path = findPathBFS(map, start, goal);
        
        // 输出结果
        cout << "Path found from (" << start.x << "," << start.y << ") to (" 
             << goal.x << "," << goal.y << "):" << endl;
        printMapWithPath(map, path, start, goal);
        
        // 打印路径坐标
        cout << "\nPath coordinates:" << endl;
        for (size_t i = 0; i < path.size(); i++) {
            cout << "(" << path[i].x << "," << path[i].y << ")";
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
        
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    
    return 0;
}
