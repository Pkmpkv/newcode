#include <iostream>
#include <functional>

// 函数类型
int add(int a, int b) {
    return a + b;
}

// 函数对象类型
struct Multiply {
    int operator()(int a, int b) const {
        return a * b;
    }
};

int main() {
    // 使用std::function包装函数
    std::function<int(int, int)> addFunction = add;
    std::cout << "addFunction(2, 3): " << addFunction(2, 3) << std::endl;

    // 使用std::function包装函数对象
    Multiply multiplyObj;
    std::function<int(int, int)> multiplyFunction = multiplyObj;
    std::cout << "multiplyFunction(2, 3): " << multiplyFunction(2, 3) << std::endl;

    // 使用std::function包装lambda函数
    std::function<int(int, int)> lambdaFunction = [](int a, int b) {
        return a - b;
    };
    std::cout << "lambdaFunction(5, 3): " << lambdaFunction(5, 3) << std::endl;

    return 0;
}
