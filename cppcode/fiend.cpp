#include <iostream>
#include <string>
using namespace std;

class base
{
    friend void show(base&);
private:
    string name;
    int age;
public:
    base
(string my_name,int my_age);
    ~base
();
};

base::base(string my_name,int my_age)
{
    this->name=my_name;
    this->age = my_age;
}

base::~base()
{
}

void show(base& ba)
{
    cout << "姓名：" << ba.name << "\t" << "年龄：" << ba.age << endl;
    return;
}

int main(int argc, char const *argv[])
{
    base ba("小哈",100);
    show(ba);
    return 0;
}