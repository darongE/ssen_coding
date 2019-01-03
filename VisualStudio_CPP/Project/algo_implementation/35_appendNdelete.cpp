#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) 
{


}

int main()
{
	ofstream fout;
	
	//(getenv("OUTPUT_PATH"));

	string s;
	getline(cin, s);

	string t;
	getline(cin, t);

	int k;
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string result = appendAndDelete(s, t, k);

	fout << result << "\n";

	fout.close();

	return 0;
}
