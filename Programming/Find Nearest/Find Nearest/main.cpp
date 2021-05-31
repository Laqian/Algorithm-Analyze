//
//  main.cpp
//  Find Nearest
//
//  Created by QianqianLiao on 2021/4/30.
//

#include <iostream>
#include <string>
using namespace std;

int point[100];

int FindNearest(int begin, int end) {
    int mid, min_distance, min_mid, min_left, min_right, min_aside;
    if (begin == end)
        return INFINITY;
    if (begin == end - 1)
        return point[end] - point[begin];
    mid = (end - begin) / 2;
    min_mid = point[mid+1] - point[mid];
    min_left = FindNearest(begin, mid);
    min_right = FindNearest(mid + 1, end);
    min_aside = min(min_left, min_right);
    min_distance = min(min_mid, min_aside);
    return min_distance;
}

int main(int argc, const char * argv[]) {
    int nearest;
    int point_len;
    cout << "input point length\n";
    cin >> point_len;
    cout << "input "<< point_len << " points\n";
    
    for (int i = 0; i < point_len; i++)
        cin >> point[i];
    nearest = FindNearest(0, point_len - 1);
    cout << "min distance:"<< nearest << "\n";
    return 0;
}
