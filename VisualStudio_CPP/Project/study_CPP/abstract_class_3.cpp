
//�߻� Ŭ�������� �Ļ��� Ŭ�������� ���� ���� �޼��带 ���������� �ʰ� ��ü�� ������ ���� ����
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
        cout<<name<<" ���ǰ�: �ȳ�"<<endl;
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
    Pianist *pianist = new Pianist("�ǾƳ��");   //�߻� Ŭ������ ��ü�� ������ �� ����(����)
    delete pianist;
    return 0;
}
