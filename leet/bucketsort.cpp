#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 桶排序函数
void bucketSort(vector<float>& arr) {
    int n = arr.size();

    // 创建桶并初始化为空
    vector<vector<float>> buckets(n);

    // 将元素分配到不同的桶中
    for (int i = 0; i < n; ++i) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 对每个非空桶进行排序
    for (int i = 0; i < n; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 合并桶中的元素到原始数组
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    // 测试桶排序
    vector<float> arr = {0.32, 0.15, 0.47, 0.81, 0.61, 0.23, 0.75, 0.18, 0.10};
    
    cout << "原始数组: ";
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // 调用桶排序函数
    bucketSort(arr);

    cout << "桶排序后数组: ";
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
