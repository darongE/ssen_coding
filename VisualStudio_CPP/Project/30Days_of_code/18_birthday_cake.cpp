#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

vector<string> split_string(string);
   
// Complete the solve function below.
//
//19
//2 5 1 3 4 4 3 5 1 1 2 1 4 1 3 3 4 2 1
//18 7

//3



// loop
// split 2 segments
// compare item

//5
//1 2 1 3 2
//3 2          d = 3  m = 2
int solve(vector<int> s, int d, int m)
{
	int i = 0,j = 0, nSize = 0;
	int sum = 0, factor = 0;

	nSize = s.size();

	if (nSize == 1)
		return 1;

	//squares.Length - (m - 1)

	for (i = 0; i < nSize; ++i)
	{
		sum = 0;
		
		int limit = i + m;
		if (limit > nSize)
			continue;

		// m 으로 나눔  : 7개 씩 

		for (j = i; j < limit; ++j)
		{
			sum +=  s[j];

		}

		if (sum == d)
			factor++;
	}

	return factor;

}

//

int main()
{

	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/the-birthday-bar-testcases/output/output03.txt");

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string s_temp_temp;
	getline(cin, s_temp_temp);

	vector<string> s_temp = split_string(s_temp_temp);
	vector<int> s(n);

	for (int i = 0; i < n; i++) {
		int s_item = stoi(s_temp[i]);

		s[i] = s_item;
	}

	string dm_temp;
	getline(cin, dm_temp);

	vector<string> dm = split_string(dm_temp);

	int d = stoi(dm[0]);

	int m = stoi(dm[1]);

	int result = solve(s, d, m);

	fout << result << "\n";

	fout.close();

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
