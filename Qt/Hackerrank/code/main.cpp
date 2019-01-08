#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

#include <fstream>
using namespace std;



using namespace std;

vector<string> split_string(string);


//2
//3 9
//17 24
//2 0

//sqrt(a)<=sqrt(x)<=sqrt(b)
// Complete the squares function below.
int squares(int a, int b)
{
    int value1 = 0, value2 = 0;

    int result = 0;
    for(int i = a; i <= b; ++i)
    {
        int temp = sqrt(i);

        if(temp*temp == i)
        {
            result++;
            i += temp*2 ;    //why?

            //for example 4 ;(range=range+temp*2)
            // 4+2*2=8;up to 8 there will no perfect sqrts..5,6,7,8 are not perfect sqrts
        }


    }



    return result;
}

int main()
{
    ofstream fout(getenv("/Users/yoshimi/Downloads/append-and-delete-testcases/output/output00.txt"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string ab_temp;
        getline(cin, ab_temp);

        vector<string> ab = split_string(ab_temp);

        int a = stoi(ab[0]);
        int b = stoi(ab[1]);

        int result = squares(a, b);

        cout << result << "\n";
    }

    //fout.close();

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
