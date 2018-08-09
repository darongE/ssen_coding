#include <iostream>
#include <vector>

using namespace std;

//3
//3 2 1
//Sample Output 1
//Array is sorted in 3 swaps.
//First Element : 1
//Last Element : 3

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	
	for (int a_i = 0; a_i < n; a_i++) 
		cin >> a[a_i];

	//bubble sort

	int iTemp = 0, factor = 0;
	int i = 0, j = 0;
	int nSize = 0;
	nSize = a.size();
	
	// set first number and compare each elements

	for (i = 0; i < nSize; ++i)
	{
		for (int j = i; j < nSize; ++j)
		{
			iTemp = a[i];

			if (iTemp > a[j])
			{
				a[i] = a[j];
				a[j] = iTemp;
				++factor;
				
			}
		}
	}


	cout << "Array is sorted in " << factor << " swaps." << "\n";
	cout << "First Element: " << a.front() << "\n";
	cout << "Last Element: " << a.back() << "\n";


	return 0;
  }