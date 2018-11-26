
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
/*
jumpingOnClouds has the following parameter(s):

c: an array of integers representing cloud types
k: an integer representing the length of one jump
*/


/*
 c = [0,0,1,0]   k =2 
 0 --> 2 --> 0

 e = 100 / 100 -2 = 98s

*/

// 2 == -1 -2 
// e.g)8 2
// 0 0 1 0 0 1 1 0

// 0 --> 2  / 100 -1 - 2 = 97
// 2 --> 4 / 97 - 1 = 96
// 4 --> 6 / 96 -1 -2 = 93
// 6 --> 0 / 93 - 1 = 92



using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c, int k)
{
	// run loop
	int i = 0, e = 0, sum = 100;
	int end = 0;

	end = c.size() - 1;
	for (i = 0; i < c.size(); ++i)
	{
		e = sum;
		// 1 or divided 2

		if (i % k == 0 && i > 0)
		{
			if (c[i] == 1)
				sum = (e - 1 - 2);
			else 
				sum = e - 1;

			if (i == end)
			{
				if (c[0] == 0)
					sum -= 1;
				else
					sum = sum - 1 - 2;

			}
			
		}
		else
		{
			if (i == end)
			{
				if (c[0] == 0)
					sum -= 1;
				else
					sum = sum - 1 - 2;

			}
		}
		
	}


	return sum;

}

int main()
{
	ofstream fout;
	fout.open("C:/Users/yoshimi/Documents/hackerrank/jumping-on-the-clouds-revisited-testcases/output/output00.txt");

	string nk_temp;
	getline(cin, nk_temp);

	vector<string> nk = split_string(nk_temp);

	int n = stoi(nk[0]);
	int k = stoi(nk[1]);

	string c_temp_temp;
	getline(cin, c_temp_temp);

	vector<string> c_temp = split_string(c_temp_temp);

	vector<int> c(n);

	for (int i = 0; i < n; i++) {
		int c_item = stoi(c_temp[i]);

		c[i] = c_item;
	}

	int result = jumpingOnClouds(c, k);

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
