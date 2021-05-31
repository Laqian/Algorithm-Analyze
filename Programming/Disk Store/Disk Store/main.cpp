//
//  main.cpp
//  Disk Store
//
//  Created by QianqianLiao on 2021/5/28.
//

#include <iostream>

using namespace std;
bool cmp(int pro1, int pro2){
    return pro1 > pro2;
}

double min_time(int num, double *pro){
    int mid = (num + 1) / 2 - 1;
    int right = -1;
    int offset = 0;
    double disk_pro[num];
    double time = 0;
    for (int i = 0; i < num; i++) {
        disk_pro[mid + right * offset] = pro[i];
        right *= -1;
        if (right == 1) {
            offset++;
        }
    }
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num ; j++) {
            time += disk_pro[i] * disk_pro[j] * abs(i - j);
        }
    }
    return time;
}

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    double file_pro[num];
    double pro_sum = 0;
    for (int i = 0; i < num; i++) {
        cin >> file_pro[i];
        pro_sum += file_pro[i];
    }
    for (int i = 0; i < num; i++) {
        file_pro[i] /= pro_sum;
    }
    sort(file_pro, file_pro + num, cmp);
    cout << "output: "<< min_time(num, file_pro) ;
    return 0;
}
