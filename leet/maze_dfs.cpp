#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

// 定义迷宫
int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

// 定义访问数组，用于标记已经访问过的位置
bool visited[ROWS][COLS] = {false};

// 定义方向数组，用于探索上、下、左、右四个方向
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 判断是否在迷宫范围内
bool isValid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

// 深度优先搜索函数
bool dfs(int row, int col) {
    // 如果当前位置是终点，返回true
    if (row == ROWS - 1 && col == COLS - 1) {
        return true;
    }

    // 标记当前位置为已访问
    visited[row][col] = true;

    // 探索四个方向
    for (int i = 0; i < 4; ++i) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        // 判断新位置是否合法，并且未被访问过
        if (isValid(newRow, newCol) && maze[newRow][newCol] == 0 && !visited[newRow][newCol]) {
            // 递归搜索下一个位置
            if (dfs(newRow, newCol)) {
                return true;
            }
        }
    }

    // 如果四个方向都无法找到路径，则回溯，将当前位置标记为未访问
    visited[row][col] = false;

    return false;
}

int main() {
    // 从起点(0,0)开始深度优先搜索
    if (dfs(0, 0)) {
        cout << "找到路径！" << endl;
    } else {
        cout << "未找到路径。" << endl;
    }

    return 0;
}
