
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> split_string(string);

//7 11
//5 15

//3 2  {count}

//- 2 2 1
//5 - 6

// Complete the countApplesAndOranges function below.
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {

	int i = 0, j = 0, cntA = 0, cntB = 0;
	int nSizeA = 0, nSizeB = 0;
	// the number of apples that fall on Sam's house.

	int tmp = 0;
	nSizeA = apples.size();
	nSizeB = oranges.size();

	for (i = 0; i < nSizeA; ++i)
	{
		 tmp = a + apples[i];

		if (s <= tmp && t >= tmp)
			cntA++;
	}



	for (j = 0; j < nSizeB; ++j)
	{

		tmp = b + oranges[j];

		if (s <= tmp && t >= tmp)
			cntB++;

	}

	cout << "apple" << cntA << endl;
	cout << "orange" << cntB << endl;

}

int main()
{
	string st_temp;
	getline(cin, st_temp);

	vector<string> st = split_string(st_temp);

	int s = stoi(st[0]);

	int t = stoi(st[1]);

	string ab_temp;
	getline(cin, ab_temp);

	vector<string> ab = split_string(ab_temp);

	int a = stoi(ab[0]);

	int b = stoi(ab[1]);

	string mn_temp;
	getline(cin, mn_temp);

	vector<string> mn = split_string(mn_temp);

	int m = stoi(mn[0]);

	int n = stoi(mn[1]);

	string apples_temp_temp;
	getline(cin, apples_temp_temp);

	vector<string> apples_temp = split_string(apples_temp_temp);

	vector<int> apples(m);

	for (int i = 0; i < m; i++) {
		int apples_item = stoi(apples_temp[i]);

		apples[i] = apples_item;
	}

	string oranges_temp_temp;
	getline(cin, oranges_temp_temp);

	vector<string> oranges_temp = split_string(oranges_temp_temp);

	vector<int> oranges(n);

	for (int i = 0; i < n; i++) {
		int oranges_item = stoi(oranges_temp[i]);

		oranges[i] = oranges_item;
	}

	countApplesAndOranges(s, t, a, b, apples, oranges);

	return 0;
}

vector<string> split_string(string input_string) 
{
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