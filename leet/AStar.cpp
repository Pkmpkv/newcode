#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

// 定义迷宫大小
const int rows = 5;
const int cols = 5;

// 定义节点类型
struct Node {
    int x, y;     // 节点坐标
    int cost;     // 从起始节点到当前节点的代价
    int heuristic; // 启发式值
    Node* parent;  // 指向父节点的指针

    // 构造函数
    Node(int x, int y, int cost, int heuristic, Node* parent = nullptr)
        : x(x), y(y), cost(cost), heuristic(heuristic), parent(parent) {}

    // 获取总代价
    int getCost() const {
        return cost + heuristic;
    }

    // 重载比较操作符
    bool operator>(const Node& other) const {
        // 在这里定义节点之间的比较规则
        return getCost() > other.getCost();
    }
};

// A*算法解决迷宫问题
void AStar(const vector<vector<int>>& maze, const Node& start, const Node& goal) {
    // 定义一个优先队列，使用std::greater进行从小到大的排序
    priority_queue<Node, vector<Node>, greater<Node>> openSet;

    // 初始化起始节点
    openSet.push(start);

    // 定义一个二维数组来记录节点是否已经访问过
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // A*算法主循环
    while (!openSet.empty()) {
        // 从优先队列中取出当前代价最小的节点
        Node current = openSet.top();
        openSet.pop();

        // 判断是否到达目标节点
        if (current.x == goal.x && current.y == goal.y) {
            cout << "Reached the goal!" << endl;

            // 输出路径
            stack<Node> path;
            while (current.parent != nullptr) {
                path.push(current);
                current = *current.parent;
            }

            cout << "Path: ";
            while (!path.empty()) {
                Node node = path.top();
                path.pop();
                cout << "(" << node.x << "," << node.y << ") ";
            }
            cout << "(" << goal.x << "," << goal.y << ")" << endl;

            return;
        }

        // 标记当前节点为已访问
        visited[current.x][current.y] = true;

        // 遍历当前节点的邻居节点
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                // 忽略对角线方向
                if (i != 0 && j != 0)
                    continue;

                // 计算邻居节点的坐标
                int neighborX = current.x + i;
                int neighborY = current.y + j;

                // 检查邻居节点是否在迷宫内且没有被访问过
                if (neighborX >= 0 && neighborX < rows && neighborY >= 0 && neighborY < cols &&
                    maze[neighborX][neighborY] == 0 && !visited[neighborX][neighborY]) {
                    // 计算邻居节点的代价和启发式值
                    int neighborCost = current.cost + 1;
                    int neighborHeuristic = abs(neighborX - goal.x) + abs(neighborY - goal.y);

                    // 创建邻居节点对象，并将当前节点设置为其父节点
                    Node neighbor(neighborX, neighborY, neighborCost, neighborHeuristic, &current);

                    // 将邻居节点加入优先队列
                    openSet.push(neighbor);
                }
            }
        }
    }

    // 如果优先队列为空，说明无法到达目标节点
    cout << "Cannot reach the goal!" << endl;
}

int main() {
    // 定义迷宫地图
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    // 定义起始节点和目标节点
    Node start(0, 0, 0, 0);
    Node goal(4, 4, 0, 0);

    // 调用A*算法解决迷宫问题
    AStar(maze, start, goal);

    return 0;
}
