

#include <iostream>
#include <limits>

using namespace std;


//If N is odd, print Weird
//If N is even and in the inclusive range of 2 to 5, print Not Weird
//If N is even and in the inclusive range of 6 to 20 , print Weird
//If N is even and greater than , print Not Weird


int main()
{
    int N = 18;
//    cin >> N;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if((N & 1) || (6 <= N && N <= 20))       //bitwise --> AND
        cout << "Weird";
    else
        cout << "Not Weird";

    return 0;
}


/**
 *
 * 7 =  0 1 1 1
 *     &0 0 0 1
 * ---------------
 *      0 0 0 1      --> 1  (odd )
 *
 *
 **/
