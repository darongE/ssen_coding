//Day Shared Liked Cumulative
//1      5     2       2
//2      6     3       5
//3      9     4       9
//4     12     6      15
//5     18     9      24

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) 
{

	int liked = 0;
	int cnt = 0;
	int default_person = 5;
	for (int i = 0; i < n; ++i)
	{

		liked = floor(default_person / 2);
		default_person = liked * 3;
		cnt = cnt + liked;

	}

	return cnt;
}

int main()
{
	ofstream fout;
	fout.open("C:/Users/yoshimi/Downloads/strange-advertising-testcases/output/output00.txt");

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int result = viralAdvertising(n);

	fout << result << "\n";

	fout.close();

	return 0;
}
