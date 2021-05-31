//
//  main.cpp
//  exp1 N-Square-Root Sort
//
//  Created by QianqianLiao on 2021/5/28.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 input
 8
 9 1 5 6 4 3 7 2
 */


void merge(vector<int> &a, int begin1, int end1, int begin2, int end2){
    int len = end1 + end2 - begin1 - begin2 + 2;
    int head = min(begin1, begin2);
    vector<int> merge_a;
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < len; i++) {
        if (begin2 == end2) {
            flag2 = 1;     //it means all the begin1 to end1 now is larger than the second
            break;
        }
        else if (begin1 == end1){
            flag1 = 1;
            break;
        }
        if (a[begin1] < a[begin2]) {
            merge_a.push_back(a[begin1++]);
        }
        else{
            merge_a.push_back(a[begin2++]);
        }
        
    }
    if (flag2 == 1) {
        merge_a.insert(merge_a.end(), a.begin() + begin1, a.begin() + end1);
    }
    if (flag1 == 1) {
        merge_a.insert(merge_a.end(), a.begin() + begin2, a.begin() + end2);
    }
    copy(merge_a.begin(), merge_a.end(), a.begin() + head);
    return;
}

void n_square_root_sort(vector<int> &a, int begin, int end){
    int len = end - begin + 1;
    if (len == 1) {
        return;
    }
    if(len == 2){
        if (a[begin] > a[end]) {
            swap(a[begin], a[end]);
        }
        return;
    }
    int group_num = int(sqrt(len));
    int group = group_num;
    if (group_num < sqrt(len)) {
        group = group_num + 1;
    }
    for (int i = 0; i < group; i++) {
        if (i == group - 1) {
            n_square_root_sort(a, begin + i * group_num, begin + len - 1); //the last group num may not == group_num
        }
        else{
            n_square_root_sort(a, begin + i * group_num, begin + (i + 1) * group_num - 1);
        }
    }
    for (int i = 0; i < group - 1; i++) {
        if (i == group - 2) {
            merge(a, begin, begin + (i + 1) * group_num, begin + (i + 1) * group_num, begin + len);
        }
        else{
            merge(a, begin, begin + (i + 1) * group_num, begin + (i + 1) * group_num, begin + (i + 2) * group_num);
        }
    }
}

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    vector<int> a(num);
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }
    n_square_root_sort(a, 0, num - 1);
    for (int i = 0; i < num; i++) {
        cout << a[i]<< " ";
    }
    return 0;
}
