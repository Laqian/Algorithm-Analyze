//
//  main.cpp
//  exp2 String Distance
//
//  Created by QianqianLiao on 2021/5/30.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 input
 cmc
 snmn
 2
 
 output
 10
 */
int dist(char a, char b){
    return abs(a - b);
}

int string_distance(string str1, string str2, int k){
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, INT_MAX));
    // initial
    for (int i = 0; i <= str1.length(); i++) {       //compare with all blank space
        dp[i][0] = i * 2;
    }
    for (int i = 0; i <= str2.length(); i++) {
        dp[0][i] = i * 2;
    }
    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            int space = min(dp[i - 1][j] + k, dp[i][j - 1] + k);
            dp[i][j] = min(dp[i - 1][j - 1] + dist(str1[i - 1], str2[j - 1]), space);
            
        }
    }
    return dp[str1.length()][str2.length()];
}

int main(int argc, const char * argv[]) {
    string str1;
    string str2;
    int k;
    cin >> str1 >> str2 >> k;
    cout << string_distance(str1, str2, k)<< '\n';
    return 0;
    
}
