/***
 *
 *
 *   Sample Input
 *
 *  3
 *  sam 99912222
 *  tom 11122222
 *  harry 12299933
 *  sam
 *  edward
 *  harry
 *
 *  Sample Output
 *
 * sam=99912222
 * Not found
 * harry=12299933
 *
 *
 ***/


#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


//map<int, int> m = {{1, 10}, {2, 5}, {4, 6}, {6, 1}};
//using mypair = pair<int, int>;

//vector<mypair> v(begin(m), end(m));

//sort(begin(v), end(v), [](const mypair& a, const mypair& b) { return a.second < b.second; });

//for(auto const &p : v)
//    cout << "m[" << p.first << "] = " << p.second << endl;


//key를 조사하는 함수는 map::find() 입니다.
//원형:

//    iterator find (const key_type& k);
//    const_iterator find (const key_type& k) const;

//파라미터:

//    k: 찾고 싶은 key

//return 값:

//    key를 찾은 경우: element의 iterator
//    key를 못 찾은 경우 : map::end


int main()
{
    std::map<string, string> map_phonebook;

    int n;
    cin >> n;
    string name;
    string phonenum;
    // read names and numbers, add on map_phonebook
    for(int i = 0; i < n; ++i)
    {
        
		cin >> name;
		cin >> phonenum;
		
        map_phonebook[name] = phonenum;
		cin.clear();
    }

    //execute queries
    std::map<string, string>::iterator it;

	vector<string> vec_query = { "sam", "edward","harry" };

	int i = 0;
    while(i < vec_query.size()){

     it = map_phonebook.find(vec_query[i]);

     if(it != map_phonebook.end())  // found key in map_phonebook
     {
         cout << it->first << "=" << it->second << '\n';
     }
     else{ // the iterator hit the end of the phone book without finding key
         cout << "Not found" << '\n';
     }
	 ++i;

    }

    return 0;
}









