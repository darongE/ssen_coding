#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

vector<string> split_string(string);
//
//6
//4 6 5 3 3 1
// 4,3,3
// |4 -3 | = 1 , |3 -3 | = 0  
//4

// Complete the pickingNumbers function below.
// |a - b| < 2
//
//Output Format
//
//A single integer denoting the maximum number of integers you can choose 
//from the array such that the absolute difference between any two of the chosen integers is X <= 1



/*
6
98 3 99 1 97 2

*/

int pickingNumbers(vector<int> a) 
{
	// run loop
	int nSize = a.size();
	int z = 0;
	int arr[100] = { 0 };


	for (int k = 0; k < a.size(); ++k)
	{
		arr[a[k]]++;

	}

	for (int i = 2; i < nSize; i++)
		z = max(z, arr[i] + arr[i - 1]);

	return z;


}



int main()
{
	ofstream fout;
	fout.open("C:/Users/yoshimi/Documents/hackerrank/picking-numbers-testcases/output/output00.txt");

	int n = 0;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string a_temp_temp;
	getline(cin, a_temp_temp);

	vector<string> a_temp = split_string(a_temp_temp);

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		int a_item = stoi(a_temp[i]);

		a[i] = a_item;
	}

	int result = pickingNumbers(a);

	fout << result << "\n";

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
