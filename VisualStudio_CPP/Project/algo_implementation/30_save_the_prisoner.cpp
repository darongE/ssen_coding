

// print the chair number of the prisoner 
// who receives the awful treat on a new line
// Sample Input 0  |  output
// 2
//  5 2 1          | 2
// 5 2 2		   | 3

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> split_string(string);
/*
   The first line contains an integer, t, denoting the number of test cases.
   	The next t lines each contain space 3 separated integers :
   n : the number of prisoners
   m : the number of sweets
   s : the chair number to start passing out treats at
*/

// tracking test case result and build algorithms
// Complete the saveThePrisoner function below.
int saveThePrisoner(int n, int m, int s) {

	int rvalue = 0;
	rvalue = (m - 1 + s - 1) % n + 1;

	return rvalue;

}

int main()
{
	ofstream fout;
	fout.open("C:/Users/yoshimi/Downloads/save-the-prisoner-testcases/output/output04.txt");

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		string nms_temp;
		getline(cin, nms_temp);

		vector<string> nms = split_string(nms_temp);

		int n = stoi(nms[0]);

		int m = stoi(nms[1]);

		int s = stoi(nms[2]);

		int result = saveThePrisoner(n, m, s);

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
