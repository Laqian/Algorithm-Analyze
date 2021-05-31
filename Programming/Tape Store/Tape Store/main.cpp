//
//  main.cpp
//  Tape Store
//
//  Created by QianqianLiao on 2021/5/28.
//

#include <iostream>

using namespace std;

typedef struct file_info{
    double pro;
    double len;
}file_info;

bool cmp(file_info file1, file_info file2){
    return file1.pro * file1.len < file2.pro * file2.len;
}

double min_cost(file_info *file, int num){
    double sum = 0;
    for (int i = 0; i < num; i++) {
        sum += (num - i) * file[i].pro * file[i].len;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    int pro_sum = 0;
    file_info file[num];
    for (int i = 0; i < num; i++) {
        cin>> file[i].len >> file[i].pro;
        pro_sum += file[i].pro;
    }
    for (int i = 0; i < num; i++) {
        file[i].pro /= pro_sum;
    }
    sort(file, file + num, cmp);
    cout << "output: "<<min_cost(file, num);
    return 0;
}
