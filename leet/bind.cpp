#include <iostream>
#include <functional>

int add(int a, int b) {
    return a + b;
}

int main() {
    auto addFunction = std::bind(add, std::placeholders::_1, std::placeholders::_2);
    std::cout << "addFunction(2, 3): " << addFunction(2, 3) << std::endl;

    return 0;
}
