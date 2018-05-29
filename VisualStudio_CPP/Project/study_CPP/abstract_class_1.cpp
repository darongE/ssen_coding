

//추상 클래스 개체를 생성하려고 할 때의 오류
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
        cout << name <<" 음악가: 안녕"<<endl;
    }    
    string GetName()const
    {
        return name;
    }
};

int main()
{
    //Musician *musician = new Musician("음악가"); //추상 클래스의 개체를 생성할 수 없음(오류)
    //delete musician;
    
	
	return 0;
}
