#include <iostream>
#include <fstream>


using namespace std;

//Sample Input
//3014

//Sample Output
//127

//Period  Height
//0          1  |  1      2 | 2    3  
//3          6  |  4      7 | 5    14

// Complete the utopianTree function below.
int utopianTree(int n) 
{
	int i = 1, height = 1;
	while (i <= n)
	{
      if (i % 2 == 0)
	  {
      	height += 1;
      }
      else {
      	height *= 2;
      }
      i++;
	}
	return height;
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
