//6
//-4 3 -9 0 4 1


//Sample Output
// [+] 3 / [-] 2 / [0] 1
//0.500000   = 3 /6
//0.333333   = 2 /6
//0.166667   = 1 /6




#include <iostream>
#include <vector>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the plusMinus function below.
 */
void plusMinus(vector<int> arr) {

    int i = 0;
    int nSize = arr.size();
    vector<double>vec_cnt(3);



    for( i = 0; i < nSize ; ++i )
    {
        if(arr[i] > 0)
          ++vec_cnt[0];
        else if(arr[i] == 0)
          ++vec_cnt[2];
        else
          ++vec_cnt[1];

    }

    cout << "[+] division : " << double(vec_cnt[0]/nSize) << endl;
    cout << "[-] division : " << double(vec_cnt[1]/nSize)<< endl;
    cout << "0 division : "   <<  double(vec_cnt[2]/nSize)<< endl;
}


int main()
{

    vector<int> arr = { -4, 3, -9, 0, 4, 1};
    plusMinus(arr);

    return 0;
}
