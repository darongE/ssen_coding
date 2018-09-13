#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


//
//7
//100 100 50 40 40 20 10
//4
//5 25 50 120
//Sample Output
//6 4 2 1

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.

// 120 100 100 50 50 40 40 25 20 10 5




vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice)
{
	int ranking = 0;

	int i = 0, n = 0;
	int m = 0, rank = 1;
	n = scores.size();

	vector<int> r(n);

	int rnk = 1, data = 0;
	
	r[0] = rnk;

	// bring rank number in score array
	for (int i = 1; i<n; i++) 
	{
		if (scores[i] == scores[i - 1]) 
			r[i] = rnk;
		else
			r[i] = ++rnk;
	}
	int j = 0;

	m = alice.size();

	vector<int> value;


	for (int i = n - 1; ( i>0 && j<m); i--) 
	{
		if (scores[i] >= alice[j])
		{ 
			
		    data = r[i] + (scores[i] > alice[j]);

			value.push_back(data);
			cout << data << '\n';
			
			j++; 
			i++;
		}
	}


	// Last item compare...

	while ( j < m) 
	{ 
		data = 1 + (scores[0] > alice[m - 1]);
		cout << data << '\n';

		value.push_back(data);
		 j++;


	}


	return value;
}

int main()
{
	ofstream fout;
	fout.open("C:/Users/yoshimi/Documents/hackerrank/climbing-the-leaderboard-testcases/output/output00.txt");

	int scores_count;
	cin >> scores_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string scores_temp_temp;
	getline(cin, scores_temp_temp);

	vector<string> scores_temp = split_string(scores_temp_temp);

	vector<int> scores(scores_count);

	for (int i = 0; i < scores_count; i++) {
		int scores_item = stoi(scores_temp[i]);

		scores[i] = scores_item;
	}

	int alice_count;
	cin >> alice_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string alice_temp_temp;
	getline(cin, alice_temp_temp);

	vector<string> alice_temp = split_string(alice_temp_temp);

	vector<int> alice(alice_count);

	for (int i = 0; i < alice_count; i++) {
		int alice_item = stoi(alice_temp[i]);

		alice[i] = alice_item;
	}

	vector<int> result = climbingLeaderboard(scores, alice);

	for (int i = 0; i < result.size(); i++) {
		fout << result[i];

		if (i != result.size() - 1) {
			fout << "\n";
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
