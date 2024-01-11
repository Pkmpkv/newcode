#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "Constructor called. Data: " << data << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called. Data: " << data << std::endl;
    }

    void display() const {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

int main() {
    // 使用 std::unique_ptr
    std::cout << "Using std::unique_ptr:" << std::endl;
    std::unique_ptr<MyClass> uniquePtr(new MyClass(42));

    // unique_ptr 不能被拷贝，只能通过 std::move 转移所有权
    std::unique_ptr<MyClass> anotherUniquePtr = std::move(uniquePtr);

    // 使用 std::shared_ptr
    std::cout << "\nUsing std::shared_ptr:" << std::endl;
    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>(10);
    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;  // 共享所有权

    // 打印对象数据
    std::cout << "\nDisplaying sharedPtr1:" << std::endl;
    sharedPtr1->display();

    std::cout << "\nDisplaying sharedPtr2:" << std::endl;
    sharedPtr2->display();

    // shared_ptr 在所有权被释放时自动调用析构函数
    return 0;
}
