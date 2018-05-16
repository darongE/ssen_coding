#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {


	int ar_count = 0;
	int i = 0, j = 0;

	cin >> ar_count;
	vector<string> arr(ar_count);
	string ar_temp;

	for (int ar_itr = 0; ar_itr < ar_count; ar_itr++)
	{
		cin >> ar_temp;
		arr[ar_itr] = ar_temp;

	}

	std::string strOdd = "", strEven = "";

	for (i = 0; i < arr.size(); ++i)
	{
		strOdd = "", strEven = "";

		for (j = 0; j < arr[i].size(); ++j)
		{
			if (j % 2 == 0)
			{
				strEven += arr[i][j];
			}
			else
			{
				strOdd += arr[i][j];
			}
		}

		cout << strEven << " " << strOdd << endl;
	}

	return 0;
}
