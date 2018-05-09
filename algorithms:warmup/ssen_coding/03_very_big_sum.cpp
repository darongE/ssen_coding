#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>

//https://www.hackerrank.com/challenges/a-very-big-sum/problem

using namespace std;

vector<string> split_string(string);

/*
 * Complete the aVeryBigSum function below.
 */


/*
 * INPUT
 * 5
 * 1000000001 1000000002 1000000003 1000000004 1000000005
 *
 *
 * OUTPUT
 * 5000000015
 *
 * 32bit integer range -2^31 ~ 2^31 -1
 */
long aVeryBigSum(int n, vector<long> ar) {
    /*
     * Write your code here.
     */

    return std::accumulate(ar.begin(), ar.end(),0LL);

}

int main()
{
  //  ofstream fout(getenv("OUTPUT_PATH"));

    int n  = 5;
//    cin >> n;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //string ar_temp_temp;
    //getline(cin, ar_temp_temp);

    vector<string> ar_temp = {"1000000001","1000000002","1000000003","1000000004","1000000005"};

    vector<long> ar(n);

    for (int ar_itr = 0; ar_itr < n; ar_itr++) {
        long ar_item = std::stol(ar_temp[ar_itr]);

        ar[ar_itr] = ar_item;
    }

    long result = aVeryBigSum(n, ar);

    cout << result << "\n";

//    fout << result << "\n";

//    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
