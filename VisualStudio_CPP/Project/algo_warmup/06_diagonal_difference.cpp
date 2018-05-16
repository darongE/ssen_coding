/**
 *
 * Diagonal difference = 대각선 의 차 구하기
 *
 *
 * Constraints
 * -100 <= x <= 100
 *
 * Input
 *
 * 3
 * 11 2 4
 * 4 5 6
 * 10 8 -12
 *
 *
 * a[0][0] + a[1][1] + a[2][2] = sum1
 * a[0][2] + a[1][1] + a[2][0] = sum2
 *
 * Output
 * 15
 *
 *  First diagonal : 11+ 5 - 12 = 4
 *  Second diagonal : 4 + 5+ 10 = 19
 *
 *  Difference: |4 - 19| = 15
 */


#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
 * Complete the diagonalDifference function below.
 */
int diagonalDifference(vector<vector<int>> a) {

// loop  and find elements from cross way
// N * N
    int i = 0, j = 0;
    int nSize = a.size();
    int sum1 = 0, sum2 = 0;

    for(i = 0; i < nSize; ++i)
    {
        for(j = 0; j < nSize; ++j)
        {
            if(i == j)
            {
             sum1 += a[i][j];
             sum2 += a[i][ nSize - 1 -j];
            }


        }

    }

   cout << "SUM 1: " << sum1 << endl;
   cout << "SUM 2: " << sum2 << endl;


    return abs(sum1 - sum2);
}

int main()
{

    vector<vector<int>> a(3);
    a[0] = { 11, 2, 4};
    a[1] = { 4,  5, 6};
    a[2] = { 10, 8, -12};



    int result = diagonalDifference(a);

    cout << "difference " << result <<endl;

    return 0;
}
