//
//  main.cpp
//  Maximun Product
//
//  Created by QianqianLiao on 2021/5/28.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int array_to_num(vector<int> &num){
    int data = 0;
    for (int i = 0; i < num.size(); i++) {
        data = data * 10 + num[i];
    }
    return data;
}

vector<vector<int>> maximun_product(vector<vector<int>> &dp, vector<int> &num, int k){
    int max = 0;
    for (int k_count = 1; k_count <= k; k++) {
        for (int i = k_count + 1; i < num.size(); i++) {
            for (int j = k_count; j < i; j++) {
                vector<int> data(num.begin()+ j + 1, num.begin() + i);
                int result = dp[j][k_count - 1] * array_to_num(data);
                if (max < result) {
                    max = result;
                }
            }
            dp[i][k_count] = max;
        }
    }
    return dp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
