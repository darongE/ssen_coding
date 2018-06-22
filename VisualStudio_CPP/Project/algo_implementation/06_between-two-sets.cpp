
/*
* Complete the getTotalX function below.

Sample Input
2 3
2 4
16 32 96   --> 4, 8 (G.C.D)  / 16 (L.C.M)

Sample Output
3
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	
	int n, m;
	// enter count of array a[], b[]
	cin >> n >> m;
	vector<int> a, b;

	// enter value each array
	for (int i = 0; i<n; ++i) {
		int value;
		cin >> value;
		a.push_back(value);
	}

	for (int i = 0; i<m; ++i) {
		int value;
		cin >> value;
		b.push_back(value);
	}

	// find min, max value on a[], b[]
	int maxA = *max_element(a.begin(), a.end());   // G.C.D (최대공약수)
	int minB = *min_element(b.begin(), b.end());   // L.C.M (최소공배수)	

	int numBetweens = 0;
	
	// run loop on array
	// check divided == 0
	// 범위 x = 4, y = 16  4 <= x <= 16
	for (int x = maxA; x <= minB; ++x) {
		bool cont = true;


		for (int i = 0; i<n; ++i) {
			if (x % a[i] != 0) {
				cont = false;
			}
		}
		if (cont) {
			for (int j = 0; j<m; ++j) {
				if (b[j] % x != 0) {
					cont = false;
				}
			}
		}

		if (cont) {
			numBetweens += 1;
		}
	}
	cout << numBetweens;

	return 0;
}
