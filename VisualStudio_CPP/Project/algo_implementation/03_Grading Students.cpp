/*

## constraints
grade <= 40
1<= n < = 60
0 <= grade <= 100

## Explanation

* 40 - grade = diff
  diff < 3 : 5ÀÇ ¹è¼ö 

* grade > 40 / round(grade)
  grade *= 5

  Sample Input
  4
  73 67 38 33

  Sample Output 0

  75 67 40 33 */



//e.g) grade = 84 / round(84) = 85
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


vector<int> gradingStudents(vector<int> grades) {

	// set the rule

	// check 5's multiple

	int nSize = 0;
	nSize = grades.size();

	for (int i = 0; i < nSize; ++i)
	{
		// 73 % 5 = 3 / 38 % 5 = 3 [40]
		if (grades[i] >= 38 && grades[i] % 5 > 2)
			grades[i] = grades[i] + (5 - (grades[i] % 5));

	}

	return grades;

}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> grades(n);

	for (int grades_itr = 0; grades_itr < n; grades_itr++) {
		int grades_item;
		cin >> grades_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		grades[grades_itr] = grades_item;
	}

	vector<int> result = gradingStudents(grades);

	cout << "\n";

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;

	return 0;
}
