//
//Complete the pageCount function in the editor below.
//It should return the minimum number of pages Brie must turn.
//
//pageCount has the following parameter(s) :
//
//n: the number of pages in the book
//p : the page number to turn to
//

// 1<= n <= 10^5
// 1 <= p <= n

//input	6  2  output 1


#include <iostream>
#include <fstream>

using namespace std;

/*
* Complete the pageCount function below.
*/


int pageCount(int n, int p) {
	
    int	min = (n / 2) - (p/ 2);
	if (min > p / 2)
		min = p / 2;

	return min;
}

int main()
{
	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/drawing-book-English/output/output00.txt");

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int p;
	cin >> p;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int result = pageCount(n, p);

	fout << result << "\n";

	fout.close();

	return 0;
}
