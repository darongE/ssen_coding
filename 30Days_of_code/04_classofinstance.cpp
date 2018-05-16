

/***
 * Task
 * age == 0 / Age is not valid, setting age to 0 ..
 *
 * age < 13  , You are young ..
 * gage >- 13 && age < 18   , You are a teenager
 *
 * otherwise : You are old..
 * Condition
 *  1 <= X < = 4
 *  -5 <= age <= 30
 *
 *
 ***/

#include <iostream>

using namespace std;

class Person{

public:
    int age;
    Person(int initialAge);
    void amIOld();
    void yearPasses();

};


Person::Person(int initialAge){
    // Add some more code to run some checks on initialAge

    age = initialAge;
    if(age < 0)
    {
       age = 0;
       cout << "Age is not valid, setting age to 0.. " << endl;
    }

}

void Person::amIOld(){
    // Do some computations in here and print out the correct statement
    // to the console
    if(age < 13)
        cout << "You are young" << endl;
    else if(age < 18)
        cout << "You are a teenager" << endl;
    else
        cout << "You are old" << endl;

}

void Person::yearPasses(){
    // Increment the age of the person in here
    age++;


}

int main()
{

    int t[] = {-1,10,16,18 };
    int age;


    int array_size = sizeof(t)/sizeof(t[0]);

    for(int i=0; i < array_size; i++)
    {
        Person p(t[i]);
        p.amIOld();

        for(int j=0; j < 3; j++) {
            p.yearPasses();
        }
        p.amIOld();

        cout << '\n';
    }

    return 0;
}

























