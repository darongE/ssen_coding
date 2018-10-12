#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

vector<string> split_string(string);

// Complete the angryProfessor function below.
//Note: Non - positive arrival times() indicate the student arrived early 
//	or on time; positive arrival
//	times() indicate the student arrived minutes late.

// if(a <0) cancel;  else no_cancel;

string angryProfessor(int k, vector<int> a) 
{

	int size = a.size();
	for (int i = 0; i<size && k>0; i++) {
		if (a[i] <= 0) {
			k--;
		}
	}
	if (k == 0)
		return "NO";
	else
		return "YES";

}

int main()
{
	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/angry-professor-testcases/output/output00.txt");

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		string nk_temp;
		getline(cin, nk_temp);

		vector<string> nk = split_string(nk_temp);

		int n = stoi(nk[0]);

		int k = stoi(nk[1]);

		string a_temp_temp;
		getline(cin, a_temp_temp);

		vector<string> a_temp = split_string(a_temp_temp);

		vector<int> a(n);

		for (int i = 0; i < n; i++) {
			int a_item = stoi(a_temp[i]);

			a[i] = a_item;
		}

		string result = angryProfessor(k, a);

		cout << "result:" << result;

		fout << result << "\n";
	}

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y && x == ' ';
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
