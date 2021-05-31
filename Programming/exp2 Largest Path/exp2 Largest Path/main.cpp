//
//  main.cpp
//  exp2 Largest Path
//
//  Created by QianqianLiao on 2021/5/29.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 input
 5
 7
 3 8
 8 1 0
 2 7 4 4
 4 5 2 6 5
 
 output
 30
 */

int largest_path(vector<vector<int>> &dp, int num){
    for (int i = num - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j];
        }
    }
    return dp[0][0];
}

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    vector<vector<int>> dp(num, vector<int>(num, 0));
    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> dp[i][j];
        }
    }
    cout << largest_path(dp, num);
    return 0;
}
