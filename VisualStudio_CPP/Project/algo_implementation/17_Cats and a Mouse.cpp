//Output Format
//For each query, return Cat A if cat catches the mouse first,
//Cat B if cat catches the mouse first, or
//Mouse C if the mouse escapes.
//
//Sample Input 0
//2 
//1 2 3
//1 3 2
//Sample Output 0
//Cat B  Mouse C
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<string> split_string(string);

// Complete the catAndMouse function below.
string catAndMouse(int x, int y, int z) 
{
	
	int cat_a = (z - x < 0) ? (z - x) * -1 : z - x;
	int cat_b = (z - y < 0) ? (z - y) * -1 : z - y;
	string win = "Mouse C";
	
	if (cat_a < cat_b) { win = "Cat A"; }
	if (cat_a > cat_b) { win = "Cat B"; }
	return win;
}

int main()
{
	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/cats-and-a-mouse-testcases/output/output00.txt");

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string xyz_temp;
		getline(cin, xyz_temp);

		vector<string> xyz = split_string(xyz_temp);

		int x = stoi(xyz[0]);

		int y = stoi(xyz[1]);

		int z = stoi(xyz[2]);

		string result = catAndMouse(x, y, z);

		fout << result << "\n";
	}

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
