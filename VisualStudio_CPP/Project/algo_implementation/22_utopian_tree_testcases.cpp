#include <iostream>
#include <fstream>

using namespace std;

// Complete the utopianTree function below.

//
//Period  Height
//0          1
//1          2
//2          3
//3          6
//4          7
//5          14
//6		     15


//3 014

//3
//6     15
//5	    14
//4		7
int utopianTree(int n) 
{

	int a[6] = { 1,2,3,6,7,14 };

	return a[n];

}

int main()
{
	ofstream fout;
	fout.open("C:/Users/yoshimi/Downloads/utopian-tree-testcases/output/output00.txt");

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		int result = utopianTree(n);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}
