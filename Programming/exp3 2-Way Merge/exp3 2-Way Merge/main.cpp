//
//  main.cpp
//  exp3 2-Way Merge
//
//  Created by QianqianLiao on 2021/5/29.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int min_merge(priority_queue<int, vector<int>, greater<int>> &a){
    int sum = 0;
    while (a.size()!= 1) {
        int min1 = a.top();
        a.pop();
        int min2 = a.top();
        a.pop();
        int sum_len = min1 + min2;
        sum += sum_len - 1;
        a.push(sum_len);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    priority_queue<int, vector<int>, greater<int>> a;  // ascending order
    for (int i = 0; i < num; i++) {
        int len;
        cin >> len;
        a.push(len);
    }
    cout << min_merge(a);
    return 0;
}
