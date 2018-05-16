#include <iostream>

using namespace std;


int main()
{
    int n = 5;
//    cin >> n;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int i = 0;

    for(i = 1; i <= 10; ++i)
    {
        cout << n <<"*" << i << "=" << n * i;
        cout << "\n";
    }


    return 0;
}
