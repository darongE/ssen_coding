#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> split_string(string);

//input
//9
//10 5 20 20 4 5 2 25 1

//output
// 2  4
vector<int> breakingRecords(vector<int> scores) {

	int max = 0, min = 0;
	vector<int> new_vec = { 0, 0 };

	max = scores[0];
	min = scores[0];

	for (int i = 0; i < scores.size(); ++i)
	{
		if (max < scores[i])
		{
			max = scores[i];
			new_vec[0] += 1;
		}
		
		else if(min > scores[i])
		{
			min = scores[i];
			new_vec[1] += 1;
		}

	}


	return new_vec;
}

int main()
{
	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/breaking-best-and-worst-records-testcases/output/output00.txt");

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string scores_temp_temp;
	getline(cin, scores_temp_temp);

	vector<string> scores_temp = split_string(scores_temp_temp);

	vector<int> scores(n);

	for (int i = 0; i < n; i++) {
		int scores_item = stoi(scores_temp[i]);

		scores[i] = scores_item;
	}

	vector<int> result = breakingRecords(scores);

	for (int i = 0; i < result.size(); i++) {
		fout << result[i];

		if (i != result.size() - 1) {
			fout << " ";
		}
	}

	fout << "\n";

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
