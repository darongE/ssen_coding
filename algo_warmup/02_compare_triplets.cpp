//https://www.hackerrank.com/challenges/compare-the-triplets/problem


// Input

//Alice's triplet
//5 6 7   --> a0 , a1, a2

// Bob's triplet
//3 6 10  --> b0, b1b  b2


//a0 > b0   Alice get point 1
//a1 = b1   no point
//a2 < b2   Bob get point 1


// Input
//5 6 7         1 <= a[i] <= 100
//3 6 10        1 <= b[i] <= 100

// Output

// 1  1
#include <iostream>
#include <vector>
#include <fstream>
#include <string>     // std::string, std::stoi

using namespace std;

vector<string> split_string(string);

/*
 * Complete the solve function below.
 */
vector<int> solve(int a0, int a1, int a2, int b0, int b1, int b2)
{
    vector<int> temp;
    int Alivevalue = 0, Bobvalue = 0;

    Alivevalue =( (a0 > b0) ? 1: 0 )+ ((a1 > b1) ? 1: 0) + ((a2 > b2) ? 1: 0);
    Bobvalue   =( (b0 > a0) ? 1: 0 )+ ((b1 > a1) ? 1: 0) + ((b2 > a2) ? 1: 0);

    temp.push_back(Alivevalue);
    temp.push_back(Bobvalue);


    return temp;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

//    string a0A1A2_temp;
//    getline(cin, a0A1A2_temp);



    vector<string> a0A1A2 =  {"10","12","50" };


    int a0 = stoi(a0A1A2[0]);

    int a1 = stoi(a0A1A2[1]);

    int a2 = stoi(a0A1A2[2]);

    string b0B1B2_temp;
    //getline(cin, b0B1B2_temp);

    vector<string> b0B1B2 =  { "20","20","10" };

    int b0 = stoi(b0B1B2[0]);

    int b1 = stoi(b0B1B2[1]);

    int b2 = stoi(b0B1B2[2]);

    vector<int> result = solve(a0, a1, a2, b0, b1, b2);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        cout <<" " << result[result_itr] ;

        if (result_itr != result.size() - 1) {
            fout << " ";
        }
    }

    cout << "\n";
    fout << "\n";

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
