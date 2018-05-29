#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE_DIVDE 3
// input
//1 1 1 0 0 0
//0 1 0 0 0 0
//1 1 1 0 0 0
//0 0 2 4 4 0
//0 0 0 2 0 0
//0 0 1 2 4 0

//output 19  (find max sum)
//2 4 4
//  2
//1 2 4

//1 1 1   1 1 0   1 0 0   0 0 0
//  1       0       0       0
//1 1 1   1 1 0   1 0 0   0 0 0
//

// 16 matrix
// brainstorming : [2][0] + [2][1] + [2][2] + [3][1]
//				   [4][0] + [4][1] + [4][2]

int main()
{
	vector<vector<int>> arr(6);
	vector<int> vec_sum;
	int sum = 0, i  = 0, j = 0;
	int value = 0;
	

	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);

		for (int j = 0; j < 6; j++) 
			cin >> arr[i][j];


		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	// make sum like I type form

	for (i = 0; i < 6 - SIZE_DIVDE + 1; i++)
	{
		for (j = 0; j < 6 - SIZE_DIVDE + 1; ++j)
		{
			sum = 0;
			// top 3- column
			for (int x = j; x < j + SIZE_DIVDE; ++x)
				sum += arr[i][x];
		
			// bottom 3-column
			for (int x = j; x < j + SIZE_DIVDE; ++x)
				sum += arr[i + SIZE_DIVDE - 1][x];
		
			// middle point
			sum += arr[i + 1][j + 1];
			vec_sum.push_back(sum);

		}

	}
	
	value = *max_element(vec_sum.begin(), vec_sum.end());
	cout << value;

	return 0;
}
// -1 - 1   0 - 9 - 2 - 2
//- 2 - 1 - 6 - 8 - 2 - 5
//- 1 - 1 - 1 - 2 - 3 - 4
//- 1 - 9 - 2 - 4 - 4 - 5
//- 7 - 3 - 3 - 2 - 9 - 9
//- 1 - 3 - 1 - 2 - 4 - 5