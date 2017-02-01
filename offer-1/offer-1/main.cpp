//
//  main.cpp
//  offer-1
//
//  Created by 何昊 on 2017/2/1.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size() - 1;
        int col = array[0].size() - 1;
        int i = 0, j = row;
        while(j >=0 && i <= col){
            if(target < array[j][i]) {
                j--;
            } else if(target > array[j][i]){
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int> > arr(4, vector<int>(4));
    int ini[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7 ,8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = ini[i][j];
        }
    }
    Solution *p = new Solution();
    cout << p->Find(7, arr) << '\n';
    return 0;
}
