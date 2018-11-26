#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
contraints
1 <= t <= 15
0 < n < 10^9
*/


//input : 2 12 1012
//output : 2 3
#define toDigit(c) (c-'0')

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) 
{

    int t = 0 ,digitCount = 0;
 
	int original = 0;
	original = n;
    while (n > 0) 
	{
    	int curDigit = n % 10;
    	n /= 10;
    	if (curDigit != 0 && original % curDigit == 0)
    		digitCount++;
    	
    }
    cout << digitCount << "\n";
    
    
    return 0;
	
}

int main()
{

	ofstream fout;
	fout.open("C:/Users/yoshimi/Documents/hackerrank/find-digits-testcases/output/output00.txt");

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		int result = findDigits(n);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}
