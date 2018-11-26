
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;



vector<string> split_string(string);


//5
//4 3 5 1 2
//

/*
p(1) = 4, p(2) = 3, p(3) = 5, p(4) = 1, p(5) = 2

x = 1 = p(4) = p(p(1))
x = 2 = p(5) = p(p(3))
x = 3 = p(2) = p(p(5))
x = 4 = p(1) = p(p(4))
x = 5 = p(3) = p(p(2))

*/

// Complete the permutationEquation function below.
vector<int> permutationEquation(vector<int> p)
{
	int nSize = p.size();
	vector<int>ans;
	ans.resize(nSize + 1);

	for (int i = 1; i <= nSize; ++i)
		ans[p[p[i - 1] - 1]] = i;

	ans.erase(ans.begin());
	return ans;
}

int main()
{
	ofstream fout;
	fout.open("C:/Users/yoshimi/Downloads/permutation-equation-testcases/output/output00.txt");

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string p_temp_temp;
	getline(cin, p_temp_temp);

	vector<string> p_temp = split_string(p_temp_temp);

	vector<int> p(n);

	for (int i = 0; i < n; i++) {
		int p_item = stoi(p_temp[i]);

		p[i] = p_item;
	}

	vector<int> result = permutationEquation(p);

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
