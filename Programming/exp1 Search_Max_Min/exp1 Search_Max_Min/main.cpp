//
//  main.cpp
//  exp1 Search_Max_Min
//
//  Created by QianqianLiao on 2021/5/29.
//

#include <iostream>
using namespace std;

typedef struct{
    int max;
    int min;
}max_min;

/*
 input
 4
 1 2 3 4
 
 output
 max: 4 min: 1
 */

max_min search_max_min(int *a, int begin, int end){
    int len = end - begin;
    max_min value;
    if (len == 1) {
        value.max = a[begin];
        value.min = a[begin];
        return value;
    }
    int divide_num = len/2;
    max_min value1;
    max_min value2;
    value1 = search_max_min(a, begin , begin + divide_num); //binary search
    value2 = search_max_min(a, begin + divide_num, end);
    value.max = max(value1.max, value2.max);
    value.min = min(value1.min, value2.min);
    return value;
    
}

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    int a[num];
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }
    max_min value = search_max_min(a, 0, num);
    cout << "max: "<< value.max << " min: " << value.min;
    return 0;
}
