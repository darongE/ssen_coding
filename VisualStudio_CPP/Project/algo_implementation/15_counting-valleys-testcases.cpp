
//Sample Input   8
//UDDDUDUU  
//Sample Output  1
//Explanation
//If we represent _ as sea level, a step up as / 
//, and a step down as \, Gary's hike can be drawn as:

//  _ / \          _
//	     \       /
//		  \ / \ /

//It's clear that there is only one valley there, so we print on a new line.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) 
{
	int sea_level = 0, Ans = 0;

	for (int i = 0; i < n; ++i)
	{
		char ch = s[i];
		if (ch == 'U')
			++sea_level;
		if (ch == 'D')
			--sea_level;
		if (sea_level == 0 && ch == 'U')
			++Ans;
		
	}

	
	return Ans;
}

int main()
{
	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/counting-valleys-testcases/output/output00.txt");

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string s;
	getline(cin, s);

	int result = countingValleys(n, s);

	fout << result << "\n";

	fout.close();

	return 0;
}
