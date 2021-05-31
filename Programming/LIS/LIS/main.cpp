//
//  main.cpp
//  LIS
//
//  Created by QianqianLiao on 2021/5/27.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> longest_increasing(vector<int> &a, vector<int> &dp){
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                a[i] = max(a[i], a[j] + 1);
            }
        }
    }
    return dp;
}
vector<int> find_longest(vector<int> &a, vector<int> &dp){
    vector<int> subsequence;
    int max = 0;
    int max_index = 0;
    int flag, flag_index;
    for (int i = 0; i < a.size() ; i++) {
        if (dp[i] > max) {
            max = dp[i];
            max_index = i;
        }
    }
    flag = max;
    flag_index = max_index;
    subsequence.push_back(max_index);
    while (flag != 0) {  // no subsequence, than break
        for (int i = flag_index - 1; i >= 0; i--) {
            if (a[i] == flag - 1 && a[i] > a[flag_index]) {
                flag = flag - 1;
                flag_index = i;
                subsequence.push_back(i);
            }
        }
    }
    return subsequence;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
