
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the bonAppetit function below.

//input
//4 1
//3 10 2 9
//12

// n = 4. k = 1, bill[] = { 3, 10, 2, 9}
// b = 12 (charged)
// b[1] = 10 /  3 + 2 + 9 = 14  b(actual) = 14 /2 = 7
// charged = 12 - 7 = 5  (12 > 7)  b (charged) - b (actual) 
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void bonAppetit(vector<int> bill, int k, int b) {


	int charged = 0, actual = 0;

	int tmp = bill[k];
	std::string message = "";
	// erase 1
	bill.erase(bill.begin() + k);
	actual = ( std::accumulate(bill.begin(), bill.end(), 0)) /2;
	if (b > actual) {

		charged = b - actual;
		cout << charged << endl;

	}
	else if (b == actual) {

		message = "Bon Appetit";
		cout << message << endl;
	}

}

int main()
{
	string nk_temp;
	getline(cin, nk_temp);

	vector<string> nk = split(rtrim(nk_temp));

	int n = stoi(nk[0]);
	int k = stoi(nk[1]);

	string bill_temp_temp;
	getline(cin, bill_temp_temp);

	vector<string> bill_temp = split(rtrim(bill_temp_temp));

	vector<int> bill(n);

	for (int i = 0; i < n; i++) {
		int bill_item = stoi(bill_temp[i]);

		bill[i] = bill_item;
	}

	string b_temp;
	getline(cin, b_temp);

	int b = stoi(ltrim(rtrim(b_temp)));

	bonAppetit(bill, k, b);

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}