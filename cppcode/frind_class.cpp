#include <iostream>
#include <string>
using namespace std;

class A
{
    friend class B;
private:
    string name;
    int age;
public:
    A(string name,int age);
    ~A();
};

A::A(string name,int age)
{      
    this->name=name;
    this->age=age;
}

A::~A()
{
}

class B
{
private:
    int val;
public:
    B(int m_val);
    ~B();
};

B::B(int m_val)
{
    this->val=m_val;
    A a("哈哈哈",90);
    cout << "B::val=" << m_val << "\t" << "A::name=" << a.name << "\t" << "A::age" << a.age << endl;
}

B::~B()
{
}

int main(int argc, char const *argv[])
{
    B(100);
    return 0;
}
