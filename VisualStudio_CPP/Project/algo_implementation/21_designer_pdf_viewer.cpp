#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the designerPdfViewer function below.

// ascii : a-z [97 - 122]
//1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 7
//zaba
int designerPdfViewer(vector<int> h, string word)
{
	
	int temp = 0, height = 0;
	for (int i = 0; i < word.size(); ++i)
	{
		height = h[(int)word[i] - 97];
		
		if (height> temp) 
			temp = height;
		
	}

	return temp*word.size();
}

int main()
{

	ofstream fout;
	fout.open("C:/Users/yoshimi/Documents/hackerrank/designer-pdf-viewer-testcases/output/output00.txt");

	string h_temp_temp;
	getline(cin, h_temp_temp);

	vector<string> h_temp = split_string(h_temp_temp);

	vector<int> h(26);

	for (int i = 0; i < 26; i++) {
		int h_item = stoi(h_temp[i]);

		h[i] = h_item;
	}

	string word;
	getline(cin, word);

	int result = designerPdfViewer(h, word);

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