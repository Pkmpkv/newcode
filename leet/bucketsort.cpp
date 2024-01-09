#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// 定义迷宫大小
const int rows = 5;
const int cols = 5;

// 定义节点结构
struct Node {
    int x, y;  // 节点的坐标
    int g, h;  // g: 从起点到当前节点的代价, h: 从当前节点到目标节点的估计代价
    Node* parent;  // 父节点指针

    Node(int x, int y) : x(x), y(y), g(0), h(0), parent(nullptr) {}

    // 计算总代价
    int getCost() const {
        return g + h;
    }
};

// A*算法函数
vector<Node*> astar(vector<vector<int>>& maze, Node* start, Node* goal) {
    // 定义优先队列用于节点排序
    priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>> openList([](Node* lhs, Node* rhs) {
        return lhs->getCost() > rhs->getCost();
    });

    // 定义已访问节点的集合
    vector<Node*> closedList;

    // 将起点加入openList
    openList.push(start);

    // A*算法主循环
    while (!openList.empty()) {
        // 取出openList中代价最小的节点
        Node* current = openList.top();
        openList.pop();

        // 如果当前节点是目标节点，返回路径
        if (current->x == goal->x && current->y == goal->y) {
            vector<Node*> path;
            while (current != nullptr) {
                path.push_back(current);
                current = current->parent;
            }
            return path;
        }

        // 将当前节点加入closedList
        closedList.push_back(current);

        // 遍历当前节点的邻居
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                // 跳过自身
                if (i == 0 && j == 0) continue;

                int newX = current->x + i;
                int newY = current->y + j;

                // 检查邻居是否在迷宫内
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    // 检查邻居是否可通行且未在closedList中
                    if (maze[newX][newY] == 0) {
                        Node* neighbor = new Node(newX, newY);
                        neighbor->g = current->g + 1;
                        neighbor->h = abs(newX - goal->x) + abs(newY - goal->y);
                        neighbor->parent = current;

                        // 如果邻居不在openList中，将其加入openList
                        if (find(openList.begin(), openList.end(), neighbor) == openList.end()) {
                            openList.push(neighbor);
                        }
                    }
                }
            }
        }
    }

    // 如果openList为空但仍未找到路径，返回空路径
    return vector<Node*>();
}

int main() {
    // 定义迷宫
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}
    };

    // 定义起点和目标点
    Node* start = new Node(0, 0);
    Node* goal = new Node(4, 4);

    // 使用A*算法求解路径
    vector<Node*> path = astar(maze, start, goal);

    // 输出路径
    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Path found:" << endl;
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << "(" << (*it)->x << ", " << (*it)->y << ")" << endl;
        }
    }

    // 释放内存
    delete start;
    delete goal;
    for (auto node : path) {
        delete node;
    }

    return 0;
}
