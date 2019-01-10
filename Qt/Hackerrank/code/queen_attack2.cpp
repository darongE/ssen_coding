#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>
#include <stdlib.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.

// obstacles[] = { {5,5} , {4 2}, {2 3}};

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    // distance to edge
    int tSpan = n - r_q;
    int lSpan = c_q - 1;
    int bSpan = r_q - 1;
    int rSpan = n - c_q;
    // distance to corners
    int blSpan = min(c_q, r_q) -1;
    int brSpan = min(r_q-1, n-c_q);
    int tlSpan = min(n-r_q,abs(1-c_q));
    int trSpan = n - max(c_q, r_q);

    int rObstacle = 0;
    int cObstacle = 0;
    int tot = 0;

    // let's find
    for(int i = 0; i < k; ++i)
    {
       rObstacle = obstacles[i][0];
       cObstacle = obstacles[i][1];


       if(rObstacle == r_q )   // same row
       {
           if(cObstacle > c_q)
               rSpan = min(rSpan, cObstacle - c_q -1);
           if(cObstacle < c_q)
               lSpan = min(lSpan, c_q - cObstacle - 1);
       }

       if(cObstacle == c_q)
       {
            if(rObstacle > r_q)
                tSpan = min(tSpan, rObstacle - r_q - 1);
            if(rObstacle < r_q)
                bSpan = min(bSpan, r_q - rObstacle - 1);
       }

       if (abs(c_q-cObstacle) == abs(r_q-rObstacle)) // in the same diagonal
       {
           if  (rObstacle > r_q){ // Higher part.
               if  (cObstacle < c_q) // left
                   tlSpan = min(tlSpan, rObstacle-r_q-1);
               if  (cObstacle > c_q) // right
                   trSpan = min(trSpan, cObstacle-c_q-1);
           }
           if  (rObstacle < r_q){ // Lower part
               if  (cObstacle < c_q) // left
                   blSpan = min(blSpan, c_q-cObstacle-1);
               if  (cObstacle > c_q) // right
                   brSpan = min(brSpan, cObstacle-c_q-1);
         }
       }

    }

    tot = tSpan+rSpan+bSpan+lSpan+blSpan+brSpan+trSpan+tlSpan;
    return tot;
}

int main()
{

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
