
//추상 클래스에서 파생한 클래스에서 순수 가상 메서드를 재정의하지 않고 개체를 생성할 때의 오류
//Program.cpp

#include <iostream>
#include <string>
using namespace std;

class Musician
{
    string name;
public:
    Musician(string name)
    {
        this->name = name;
    }
    virtual void Play()=0; //순수 가상 메서드(추상 메서드)
    void Introduce()
    {
        cout<<name<<" 음악가: 안녕"<<endl;
    }    
    string GetName()const
    {
        return name;
    }
};

class Pianist : public Musician
{
public:
    Pianist(string name):Musician(name)
    {
    }
};

int main()
{
    Pianist *pianist = new Pianist("피아노맨");   //추상 클래스의 개체를 생성할 수 없음(오류)
    delete pianist;
    return 0;
}
