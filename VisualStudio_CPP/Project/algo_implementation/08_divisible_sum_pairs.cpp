/*
	array of integer is given and Find 
	and print the number of pairs where i < j and ai + aj is divisible by k.

	Sample Input
	6 3   : n, divide_num
	1 3 2 6 1 2
	Sample Output 5
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> split_string(string);


// ## Sol 1
// Complete the divisibleSumPairs function below.
// O(n)
using namespace std;
int divisibleSumPairs(int n, int k, vector<int> ar)
{

	int count = 0;
	int counts[6] = {}, bucket = 0;

	for (int i = 0; i < n; i++)
	{
		// the idea is that if (a1 + a2) % k == 0
		// then (a1 % k + a2 % k) should be equal to k (or 0)
	    bucket = ar[i] % k;
		// adding all new combinations with arr[i] to the count
		// also handling bucket == 0 with % k here
		count += counts[(k - bucket) % k];
		counts[bucket]++;
	}

	return count;
}

// normal answer
//int divisibleSumPairs(int n, int k, vector<int> ar)
//{
//	int i = 0, j = 0, cnt = 0;
//
//	// make for-loop
//	for (i = 0; i < n ; ++i)
//	{
//		for (j = i + 1; j < n; ++j)
//		{
//
//			int sum = ar[i] + ar[j];
//
//			if (sum % k == 0 && i < j)
//			{
//				cout << i << "," << j
//					<< ":" << sum << endl;
//
//				cnt++;
//			}
//
//		}
//
//	}
//	
//	return cnt;
//}

int main()
{
	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/divisible-sum-pairs-testcases/output/output00.txt");

	string nk_temp;
	getline(cin, nk_temp);

	vector<string> nk = split_string(nk_temp);

	int n = stoi(nk[0]);

	int k = stoi(nk[1]);

	string ar_temp_temp;
	getline(cin, ar_temp_temp);

	vector<string> ar_temp = split_string(ar_temp_temp);

	vector<int> ar(n);

	for (int i = 0; i < n; i++) {
		int ar_item = stoi(ar_temp[i]);

		ar[i] = ar_item;
	}

	int result = divisibleSumPairs(n, k, ar);

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
