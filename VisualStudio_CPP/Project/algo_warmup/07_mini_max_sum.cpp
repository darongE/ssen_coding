#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> split_string(string);

/*
 * Complete the miniMaxSum function below.
 */


/**
 *  INPUT 1 2 3 4 5
 *
 *  OUTPUT 10 14
 *
 *   EXCEPT  ONE NO. 1, 2, 3, 4, 5
 *
 *   EXCEPT 1 : 2 + 3 + 4 + 5 = 14
 *   EXCEPT 2 : 1 + 3 + 4 + 5 = 13
 *   EXCEPT 3 : 1 + 2 + 4 + 5 = 12
 *   EXCEPT 4 : 1 + 2 + 3 + 5 = 11
 *   EXCEPT 5 : 1 + 2 + 3 + 4 = 10
 *
 *   MIN :10, MAX : 14
 */
void miniMaxSum(vector<int> arr) {

    // need temp vector container

    long long data[5];

     for(int i = 0; i < 5; ++i)
         data[i] = arr[i];

     std:sort(data,data + 5);

     long long min = data[0]+data[1]+data[2]+data[3];
     long long max = data[1]+data[2]+ data[3]+data[4];

     cout << min << " " << max << endl;
 }

int main()
{
    vector<int> arr = { 793810624, 895642170, 685903712, 623789054, 468592370};
    vector<int> arr_b = { 5, 5, 5, 5, 5};
    miniMaxSum(arr);

    return 0;
}


