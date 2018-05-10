
#include <iostream>

using namespace std;



//Sample Input 1
//20 3 6 85

// p =20 , d= 3, m =6 , s = 85

// 20 + 17 + 14 + 11 + 8 + 6 + 6 = 82
//Sample Output 1
//7





int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy

   int sum = 0;
   int cnt = 0;

    for( sum = p; sum <= s ; sum += p  )
    {

     if( p - d < m)
        p = m;
     else
        p = p - d;


     ++cnt;
     cout << "p: " << p << endl;
     cout << "sum: " << sum << endl;
     cout << "no: " << cnt << endl;

    }


   return cnt;

}

//13 74 1 237  225
int main() {

    int p = 13;
    int d = 74;
    int m = 1;
    int s = 237;
   // cin >> p >> d >> m >> s;
    int answer = howManyGames(p, d, m, s);
    cout << answer << endl;
    return 0;
}
