#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Complete the repeatedString function below.

/*
aba : aba aba abaa
 a : 7

jdiacikk
899491
*/

long repeatedString(string s, long n) {


    long i = 0;
    // let's find item
    long *alphabet = nullptr;
    alphabet = (long*)malloc(sizeof(long) * n);
    memset(alphabet, 0, sizeof(alphabet)*n);

    string new_string;
    size_t length = s.size();


    if(length == 1)
    {
        if(s[0] != 'a')
            return 0;

        return n;

    }
    for(i = 0; i < n; ++i)
    {

        if(n > length && new_string[i] == 'a')
        {
           new_string += s[i%length];
           alphabet[new_string[i] -97]++;
        }
     }



    long temp = 0;
    temp = alphabet[0];

    free(alphabet);
    return temp;

}

int main()
{
    ofstream fout(getenv("/Users/yoshimi/Downloads/repeated-string-testcases/output/output00.txt"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    cout << result << "\n";

    fout.close();

    return 0;
}
