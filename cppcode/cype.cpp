#include <iostream>
#include <string>
using namespace std;

class cype
{
private:
    int age;
    int* hight;
public:
    void print();
    void chang_age(int new_age);
    void chang_hight(int new_hight);

    cype(int age,int hight);
    cype(const cype& pe);
    ~cype();
};

cype::cype(int age,int hight)
{
    this->age=age;
    this->hight=new int(hight);
}

cype::cype(const cype& pe)
{
    this->age=pe.age;
    this->hight=new int(*pe.hight);
}

cype::~cype()
{
    if(this->hight!=NULL)
    {
        delete this->hight;
        this->hight=NULL;
    }
}

void cype::print()
{
    cout << "age: " << this->age <<"\t" << "hight:" <<  *this->hight << endl;
}

void cype::chang_age(int new_age)
{
    this->age=new_age;
    return;
}

void cype::chang_hight(int new_hight)
{
    *this->hight=new_hight;
    return;
}


int main(int argc, char const *argv[])
{
    cype pe1(20,100);
    cype pe2=pe1;
    pe1.chang_hight(80);
    pe1.print();
    pe2.print();
    return 0;
}
