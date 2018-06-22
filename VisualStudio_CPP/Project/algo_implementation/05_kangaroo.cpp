
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

vector<string> split_string(string);


//Print YES if they can land on the same location at the same time; otherwise, print NO.

//Sample Input 0
//
//0 3 4 2
//
//Sample Output 0
//
//YES

//Sample Input 1	0 2 5 3
//
//Sample Output 1  NO


/*
14 4 98 2

18 22 26  *** 
100 102 ** 

100 / 18  = 5.55
*/



//45 7 56 2

//		  52, 59, 66, 73
//		  58, 60, 62, 64
// diff	   6, 1,4,	

// Complete the kangaroo function below.
string kangaroo(int x1, int v1, int x2, int v2) 
{
	if(v1 > v2 && ((x2 - x1) % (v1 - v2) == 0))
		return string("YES");

	return string("NO");
}

int main()
{
	
	string x1V1X2V2_temp;
	getline(cin, x1V1X2V2_temp);

	vector<string> x1V1X2V2 = split_string(x1V1X2V2_temp);

	int x1 = stoi(x1V1X2V2[0]);

	int v1 = stoi(x1V1X2V2[1]);

	int x2 = stoi(x1V1X2V2[2]);

	int v2 = stoi(x1V1X2V2[3]);

	string result = kangaroo(x1, v1, x2, v2);

	cout << result << endl;
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
