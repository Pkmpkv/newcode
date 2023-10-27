#include <iostream>
#include <string>
using namespace std;

class person
{
private:
    string name;
    int age;
public:
    person(string m_name,int age);
    person operator+(person per)
    {
        //this->name.append("+").append(per.name);
        //this->age+=per.age;
        return person(this->name.append("+").append(per.name),this->age+per.age);
    }

    person operator<<(person per)
    {
        cout << "name:" << this->name << "\t" << "age:" << this->age <<endl; 
        return person("lal",0);
    }

    void show()
    {
        cout << "name:" << this->name << "\t" << "age:" << this->age <<endl; 
    }

    ~person();
};

person::person(string m_name,int age)
{
    this->name=m_name;
    this->age=age;
}

person::~person()
{
}

ostream& operator<<(ostream &cout,person &per)
{
    cout << "你上当拉！！！！";
    return cout; 
}

int main(int argc, char const *argv[])
{
    person per1("张三",18);
    person per2("王五",100);
    person per3=per1+per2+per1;    
    //per3.show()
    person per4=per1;
    // cout<<per3;
    // cout<<per4;
    per4.show();
    return 0;
}