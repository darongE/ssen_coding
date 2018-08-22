

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

/*
* Complete the birthdayCakeCandles function below.
For example, if your niece is turning 4 years old, and the cake will have  4 candles of height 
she will be able to blow out 2 candles successfully, 
since the tallest candle is of height 3 and there are 2 such candles.

>> INPUT
4
3 2 1 3    ==> 3 : 2°³ 
>> OUTPUT 
2
*/

int birthdayCakeCandles(int n, vector<int> ar) {

	// find max num
	int cnt = 0;
	int max = *std::max_element(ar.begin(), ar.end());

	for (int i = 0; i < ar.size(); ++i)
	{
		if (ar[i] == max)
			++cnt;
	}

	return cnt;

}

int main()
{

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string ar_temp_temp;
	getline(cin, ar_temp_temp);

	vector<string> ar_temp = split_string(ar_temp_temp);

	vector<int> ar(n,0);

	for (int ar_itr = 0; ar_itr < n; ar_itr++) {
		int ar_item = stoi(ar_temp[ar_itr]);

		ar[ar_itr] = ar_item;
	}

	int result = birthdayCakeCandles(n, ar);

	cout << result << "\n";


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