//Note: The resulting magic square must contain distinct integers in the inclusive range .
//	For example, we start with the following matrix :
//	  5 3 4
//	  1 5 8
//	  6 4 2
// We can convert it to the following magic square :
//	  8 3 4
//	 1 5 9
//	 6 7 2
//	 This took


#include <iostream>
#include <vector>
#include <fstream>


using namespace std;



void rotate(int arr[][3])
{
	int value = arr[0][2];
	arr[0][2] = arr[0][1];
	arr[0][1] = arr[0][0];
	arr[0][0] = arr[1][0];

	arr[1][0] = arr[2][0];
	arr[2][0] = arr[2][1];
	arr[2][1] = arr[2][2];
	arr[2][2] = arr[1][2];

	arr[1][2] = value;

}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s)
{
	int cm = 100;
	int sum = 0;
	int mag1[3][3] = { 8,1,6,3,5,7,4,9,2 };
	int mag2[3][3] = { 8,3,4,1,5,9,6,7,2 };

	int c1 = 0, c2 = 0;
	
	for (int i = 0; i < 4; ++i)
	{
		c1 = 0, c2 = 0;

		for (int j = 0; j < 9; ++j)
		{
			c1 += fabs(mag1[j / 3][j % 3] - s[j / 3][j % 3]);
			c2 += fabs(mag2[j / 3][j % 3] - s[j / 3][j % 3]);

		}

		if (c1 > c2 && cm > c2) // compare diff value, default value
			cm = c2;
		else if (c2 >= c1 && cm > c1)
			cm = c1;

		// rotate array

		rotate(mag1);
		rotate(mag1);
		rotate(mag2);
		rotate(mag2);
	}
	sum += cm;
	cout << sum;

	return sum;
}

int main()
{
	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/magic-square-forming-testcases/output/output00.txt");

	int s;
	int c1 = 0, c2 = 0;
	int cm = 100;
	int arr[3][3];


	vector<vector<int>> vec_matrix;
	vec_matrix.resize(3, vector<int>(3));

	for (int i = 0; i<9; i++)
	{
		cin >> vec_matrix[i / 3][i % 3];
	}


	int result = formingMagicSquare(vec_matrix);

	fout << result << "\n";

	fout.close();

	return 0;
}
