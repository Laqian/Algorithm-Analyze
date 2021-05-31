//
//  main.cpp
//  0-1 Bag
//
//  Created by QianqianLiao on 2021/5/27.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int knapsack(vector<int> &weight, vector<int> &value, vector<vector<int>> &dp, int capacity, int num){
    for (int  i = 1; i < num + 1; i++){
        for (int j = 1; j < capacity + 1; j++){
            if(weight[i] <= j){
                dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - weight[i]] + value[i]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[num][capacity];
}

vector<int> find_solution(vector<int> &weight, vector<int> &value, vector<vector<int>> &dp, int capacity, int num){
    vector<int>  inbag;
    int flag;
    while (capacity != 0 | capacity < *min_element(weight.begin(), weight.end())) {
        flag = 0;
        for (int i = num; i > 1; i--) {
            if (dp[i][capacity] != dp[i - 1][capacity]) {
                capacity = capacity - weight[i];
                inbag.push_back(i);
                flag = 1;
            }
        }
        if (flag == 0) {
            capacity = capacity - 1; // if not found element add in this capacity, search capacity - 1
        }
    }
    return inbag;
}

int main(int argc, const char * argv[]) {
    int capacity, num;
    cin >> capacity;
    cin >> num;
    vector<int> value(num + 1, 0);
    vector<int> weight(num + 1, 0);
    for (int i = 0; i < num; i++){
        cin >> value[i];
    }
    for (int i = 0; i < num; i++){
        cin >> weight[i];
    }
    vector<vector<int>>dp(num + 1, vector<int>(capacity + 1, 0));
    return 0;
}
