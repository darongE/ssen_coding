#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
/*
 *
 * 7
 * 0 0 1 0 0 1 0
 *
 */

//int jumpingOnClouds(vector<int> c)
//{
//    int count = -1;
//    size_t n = c.size();
//    for (int i = 0; i < n; i++, count++)
//    {
//        // range : i < n -2
//        if (i<n-2 && c[i+2]==0)
//            i++;
//    }
//    return count;
//}

int jumpingOnClouds(vector<int> c)
{
    const int inf = 555;
    int A[111], dp[111];

    size_t n = c.size();

    for(int i=2; i<=n; i++)
    {
       if(c[i] == 0) dp[i] = min(dp[i-1], dp[i-2]) + 1;
       else dp[i] = inf;
    }

    cout << dp[n] << "\n";

    return dp[n];
}

int main()
{
    ofstream fout(getenv("/Users/yoshimi/Downloads/jumping-on-the-clouds-testcases/output/output00.txt"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    cout << result << "\n";
    fout << result << "\n";

    fout.close();

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
