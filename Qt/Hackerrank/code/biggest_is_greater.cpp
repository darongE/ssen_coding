#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Complete the biggerIsGreater function below.

/*
 * 6
lmno
dcba
dcbb
abdc
abcd
fedcbabcd
 *
 *
 */
string biggerIsGreater(string w) {


   size_t nSize = w.size();
   size_t j = nSize - 1;
   string newWord;

   int i = nSize -1;
   // find the longest suffix
   while(i > 0 && w[i - 1] >= w[i])
   {
        i--;
   }

   if (i == 0)
      return "no answer";

   while(w[j] <= w[i - 1])
       j--;


   // swap
   char tmp = w[i - 1];
   w[i - 1] = w[j];
   w[j] = tmp;

   // reverse suffix
   j = w.size() - 1;
   while(i < j)
   {
       tmp = w[i];
       w[i] = w[j];
       w[j] = tmp;
       i++;
       j--;   // length 에서 거꾸로
   }



   return w;
}

int main()
{
    ofstream fout(getenv("/Users/yoshimi/Downloads/bigger-is-greater-testcases/output04.txt"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);
        cout << "string :"  << result << "\n";

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
