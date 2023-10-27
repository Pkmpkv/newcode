#include <iostream>
#include <string>
using namespace std;

class TC
{
private:
    double unlead,lead,total;
    int unprice,price;
public:
    TC
();
    ~TC
();
    void getdate();
    void allprince();
};

TC::TC()
{
    unprice=17;
    price=16;
}

TC::~TC()
{
}

void TC::getdate()
{
    cout << "无铅汽油总量：";
    cin >> unlead;
    cout << "有铅汽油总量：";
    cin >> lead;
    this->total=this->unlead*this->unprice+this->lead*this->price;
    return;
}

void TC::allprince()
{
    cout << "总收入：" << total << "元" << endl;
    return;
}

int main(int argc, char const *argv[])
{
    TC work;
    work.getdate();
    work.allprince();
    cout << "haha" <<endl;
    return 0;
}
