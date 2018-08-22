
// Gregory calendar
//1.�� ���� ������ 4�� ����� �ƴϸ�, ������� 2���� 28�ϱ����� �ִ�.
//2.���� ������ 4�� ����̸鼭 100�� ����� �ƴϸ�, ����(2�� 29��)�� �����Ѵ�.
//3.���� ������ 100�� ����̸鼭 400�� ����� �ƴ� ��, �� �ش� ������� �����Ѵ�.
//4.���� ������ 400�� ����̸�, ����(2�� 29��)�� �����Ѵ�.
// constraints 1700 <= X <= 2700

/*
Given a year, y, find the date of the 256th day of that year 
according to the official Russian calendarduring that year
  output :dd.mm.yyyy
*/

/* 2016
   mont ; Sep.
   31 + 29 + 31 + 30 + 31 + 30 
   + 31 + 31 = 244
   256 -244 = 12
 -->  12.09.2016

 const int mon7 = 215; //7 months' days

 string solve(int year)
 {
 short int feb; //days in february
 if(year < 1918) //julian
 feb = year%4 ? 28 : 29;
 else if(year > 1918) //gregorian
 feb = !(year%400) || year%100&&!(year%4) ? 29 : 28;
 else //dreaded 1918
 feb = 15;
 feb = 256 - (feb + mon7);
 return to_string(feb) + ".09." + to_string(year);
 }

*/

// day calcuration


#include <iostream>
#include <fstream>
#include <string>


using namespace std;

// Complete the solve function below.
string solve(int year) {

	const int mon7 = 215;	// 7months' days ( 1 ~ 7)  except feb

	short int feb = 0; // days in february

	if (year < 1918)		//julian
		feb = year % 4 ? 28 : 29;
	else if (year > 1918)	// gregorian
		feb = (!(year % 400) || year % 100) && !(year % 4) ? 29 : 28;
	else
		feb = 15;

	feb = 256 - (feb + mon7);
	return to_string(feb) + ".09." + to_string(year);
		
}

int main()
{
	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/day-of-the-programmer-testcases/output/output00.txt");

	int year;
	cin >> year;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string result = solve(year);

	fout << result << "\n";

	fout.close();

	return 0;
}