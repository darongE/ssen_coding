//For example,arr= [1,1,2,2,3] assume your bird sightings are of types.
//There are two each of types and, and one sighting of type.
//Pick the lower of the two types seen twice : type 

//input
//6
//1 4 4 4 5 3

// 4
// 1- 1, 3-1,4 - 3, 5-1
// 4 have 3 elements : answer 4

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>   

#include <functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {

	int max = *std::max_element(arr.begin(), arr.end());
	int min = *std::min_element(arr.begin(), arr.end());
	vector<int>vec_cnt;
	vec_cnt.resize(max);

	for (auto &&i : arr) {

		if (i == max)
			vec_cnt[max- 1]++;
		else if (i < max)
		{
			if (i == min)
				vec_cnt[min -1]++;
			else
			{
				if (i == max - 1)
					vec_cnt[max - 2]++;
				else if (i == max - 2)
					vec_cnt[max -3]++;
				else
				{
					if (max - 3 != min)
					{
						vec_cnt[max - 4]++;
					}
				}
			}

		}

	}

	int max_cnt = *std::max_element(vec_cnt.begin(), vec_cnt.end());

	for (int i = 0; i < vec_cnt.size(); ++i)
	{
		if (vec_cnt[i] == max_cnt)
			return i + 1;
	}

	return 0;
}

int main()
{
	ofstream fout;
	fout.open("C://Users/yoshimi/Downloads/migratory-birds-testcases/output/output00.txt");

	string arr_count_temp;
	getline(cin, arr_count_temp);

	int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split(rtrim(arr_temp_temp));

	vector<int> arr(arr_count);

	for (int i = 0; i < arr_count; i++) {
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	int result = migratoryBirds(arr);

	fout << result << "\n";

	fout.close();

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

vector<string> split(const string &str) 
{
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
