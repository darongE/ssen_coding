#include <iostream>
#include <string>

using namespace std;

/*
* Complete the timeConversion function below.
*/

/*
INPUT : 07:05:45PM
OUTPUT : 19:05:45
1 <= hh <= 12
00 <= mm,ss <= 59
24hour format 00 <= hh <= 23
*/
string timeConversion(string s) {

	std::string time = s.substr(8, 2);
	std::string strHour = s.substr(0, 2);

	
	if (time == "PM")  
	{
	    int hour = stoi(strHour);
		
		if (hour < 12)
			hour += 12;

		strHour = std::to_string(hour);
		s = strHour + s.substr(2, 6);
	}
	else
	{
		if (strHour == "12") {
			strHour = "00";
			s = strHour + s.substr(2, 6);

		}
		else	
		  s = s.substr(0, 8);		// COPY EXCEPT AM, PM
	}

	return s;
}

int main()
{

	string s;
	getline(cin, s);

	string result = timeConversion(s);
	cout << result << "\n";


	return 0;
}
