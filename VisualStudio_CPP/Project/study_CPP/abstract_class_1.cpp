

//�߻� Ŭ���� ��ü�� �����Ϸ��� �� ���� ����
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
    virtual void Play()=0; //���� ���� �޼���(�߻� �޼���)
   
	void Introduce()
    {
        cout << name <<" ���ǰ�: �ȳ�"<<endl;
    }    
    string GetName()const
    {
        return name;
    }
};

int main()
{
    //Musician *musician = new Musician("���ǰ�"); //�߻� Ŭ������ ��ü�� ������ �� ����(����)
    //delete musician;
    
	
	return 0;
}
