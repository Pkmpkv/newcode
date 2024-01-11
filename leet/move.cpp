#include <iostream>
#include <string>
#include <cstring>

class MyString {
public:
    MyString(const char* str) : data(nullptr) {
        std::cout << "Constructor called." << std::endl;
        if (str != nullptr) {
            size = strlen(str);
            data = new char[size + 1];
            strcpy(data, str);
        }
    }

    // 移动构造函数
    MyString(MyString&& other) noexcept : data(nullptr), size(0) {
        std::cout << "Move constructor called." << std::endl;
        swap(*this, other);
    }

    // 移动赋值运算符
    MyString& operator=(MyString&& other) noexcept {
        std::cout << "Move assignment operator called." << std::endl;
        if (this != &other) {
            delete[] data;
            swap(*this, other);
        }
        return *this;
    }

    ~MyString() {
        std::cout << "Destructor called." << std::endl;
        delete[] data;
    }

    friend void swap(MyString& first, MyString& second) noexcept {
        using std::swap;
        swap(first.data, second.data);
        swap(first.size, second.size);
    }

private:
    char* data;
    std::size_t size;
};

int main() {
    MyString source("Hello, World!");

    // 使用 std::move 转移所有权
    MyString destination = std::move(source);
    //shared_ptr<MyString> destination = std::make_shared<MyString>(std::move(source));
    return 0;
}
