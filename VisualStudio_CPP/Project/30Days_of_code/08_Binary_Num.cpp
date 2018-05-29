
/*
Sample Input 1 : 5  / Output 1 : 1
 
Sample Input 2 : 13 / Output 2 : 2 

constraints : 1<= n < = 10^6
*/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	int counter = 0, maxCounter = 0;

	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// run loop

	int r = 0;

	while (n != 0)
	{
		r = n % 2;
		n = n / 2;

		if (r == 1)
		{  
			counter++;
			if (counter >= maxCounter)
				maxCounter = counter;

		
		}
		else if (r == 0)
		{
			counter = 0;
		}


	}


	cout << maxCounter << endl;

	return 0;

}