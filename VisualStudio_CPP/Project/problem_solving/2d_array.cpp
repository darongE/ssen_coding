#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

//Print the largest(maximum) hourglass sum found in 

// Complete the hourglassSum function below.

/*
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0    --->	2 4 4
					  2     (19)
					1 2 4
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0   


*/
int hourglassSum(vector<vector<int>> arr) {

	vector<int> arr_sum;
	arr_sum.reserve(16);


	for (unsigned int row = 0; row < 4; ++row)
	{
		for (unsigned int col = 0; col < 4; ++col) 
		{
			arr_sum.push_back
			(   arr[row][col] + arr[row][col + 1] + arr[row][col + 2] +
				arr[row + 1][col + 1] +
				arr[row + 2][col] + arr[row + 2][col + 1] + arr[row + 2][col + 2]);
		}
	}
	int max_sum = *max_element(arr_sum.begin(), arr_sum.end());

	cout << max_sum << endl;
	return max_sum;
}

int main()
{
	ofstream fout;
	fout.open("C:/Users/yoshimi/Downloads/2d-array-testcases/output/output00.txt");

	vector<vector<int>> arr(6);
	
	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);

		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int result = hourglassSum(arr);

	fout << result << "\n";

	fout.close();

	return 0;
}
