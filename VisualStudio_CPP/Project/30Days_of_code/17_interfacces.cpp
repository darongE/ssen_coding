#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// constraints
// 1 <=  N <= 1000


// input 6
// output
// I implemented: AdvancedArithmetic
// 12  

// 1 + 2 + 3 + 6= 12



class AdvancedArithmetic 
{

public:
	virtual int divisorSum(int n) = 0;
};

class Calculator : public AdvancedArithmetic {

public:
	int divisorSum(int n) {

		int i = 1, sum = 0;

		while (i <= n)
		{
		  if (n % i == 0)
				sum += i;
	
			++i;
		}


		return sum;
	}
};


int main()
{
	int n;
	cin >> n;

	AdvancedArithmetic *myCalculator = new Calculator();
	int sum = myCalculator->divisorSum(n);
	cout << "I implemented: AdvancedArithmetic\n" << sum;

	return 0;
}