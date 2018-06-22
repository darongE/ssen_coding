#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
	Find max difference

  # Constraints
	1<= N <= 10
	1 <= elements[i] <= 100 , 0 <= i <= N -1

  # Input
  3
  1 2 5

  # Output
  4

  1 - 2  = | -1| = 1
  1 - 5 = | -4| = 4
  2 - 5 = | -3| = 3


  5
  8 19 3 2 7
*/


class Difference {
private:
	vector<int> elements;

public:

	Difference(vector<int> value) {
		
		maximumDifference = 0;
		for (int i = 0; i < value.size(); ++i)
			elements.push_back(value[i]);

	}

	int maximumDifference;

	void computeDifference()
	{
	
		int diff = 0, old_diff = 0;
		int nSize = elements.size();

		for (int i = 0 ; i < nSize; ++i)
		{
			for (int j = i + 1; j < nSize; ++j)
			{
				diff = abs(elements[i] - elements[j]);
				
				if(diff > old_diff)
				   old_diff = diff;		

				if (maximumDifference < diff)
					maximumDifference = diff;

			}

		}

	}

};

// End of Difference class
int main() 
{
	int N;
	cin >> N;

	vector<int> a;

	for (int i = 0; i < N; i++) {
		int e;
		cin >> e;

		a.push_back(e);
	}

	Difference d(a);

	d.computeDifference();

	cout << d.maximumDifference;

	return 0;
}