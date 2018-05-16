


#include <iostream>

using namespace std;




//Sample Input

//6

//Sample Output

//     #
//    ##
//   ###
//  ####
// #####
//######


/*
 * Complete the staircase function below.
 */
void staircase(int n) {


    int i = 0, j = 0;
    // 공백 확보하기

    for( i= 1; i <= n ; ++i)
    {
        for( j = 0; j < n ; ++j )
        {
            // 별 찍을 공간 차감하고 구성
            if(j < n - i)
                cout << " " ;
            else
                cout << "#";

        }

        cout << "\n";
    }


}

int main()
{
    int n = 6;

    staircase(n);

    return 0;
}
