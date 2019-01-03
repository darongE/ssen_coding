#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> split_string(string);

// Complete the nonDivisibleSubset function below.


//4 3
//1 7 2 4

/*
 *
 * 15 7
 * 278 576 496 727 410 124 338 149 209 702 282 718 771 575 436
 *
 */
int nonDivisibleSubset(int k, vector<int> S)
{

    int c[100] = {0};

    int i;

    // compare number divided k and count
    for (i = 0; i < S.size(); i++) {
        int j = S[i] % k;
        c[j]++;
    }


    if (c[0] > 0) c[0] = 1;

    // if k divided 2
    if (k % 2 == 0) {
        if (c[k / 2] > 0) c[k / 2] = 1;
    }

    int sum = c[0];
    // run loop and get count
    for (i = 1; i <= k / 2; i++) {
        if (c[i] >= c[k - i]) {
            sum += c[i];
        } else {
            sum += c[k - i];
        }
    }
    return sum;

}

int main()
{
    ofstream fout(getenv("/Users/Shared/non-divisible-subset-testcases/output/output00.txt"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string S_temp_temp;
    getline(cin, S_temp_temp);

    vector<string> S_temp = split_string(S_temp_temp);

    vector<int> S(n);

    for (int i = 0; i < n; i++) {
        int S_item = stoi(S_temp[i]);

        S[i] = S_item;
    }

    int result = nonDivisibleSubset(k, S);

    std::cout << result << "\n";
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
