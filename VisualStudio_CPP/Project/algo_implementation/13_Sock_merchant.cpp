#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.

//9
//10 20 20 10 10 30 50 10 20

// 10 - 10 /10 - 10/ 20 - 20  : 3
int sockMerchant(int n, vector<int> ar) 
{

	short int pairs = 0;
	for (int i = 0; i < n - 1; ++i)
	{ 
		//selection sort
		for (int j = i + 1; j < n; ++j)
		{
			if (ar[i] > ar[j])
			{
				short int tmp = ar[j];
				ar[j] = ar[i];
				ar[i] = tmp;
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) //number of pairs
		if (ar[i] == ar[i + 1])
			pairs++, i++;

	return pairs;
}

int main()
{

	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/sock-merchant-testcases/output/output00.txt");

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string ar_temp_temp;
	getline(cin, ar_temp_temp);

	vector<string> ar_temp = split_string(ar_temp_temp);

	vector<int> ar(n);

	for (int i = 0; i < n; i++) {
		int ar_item = stoi(ar_temp[i]);

		ar[i] = ar_item;
	}

	int result = sockMerchant(n, ar);

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
