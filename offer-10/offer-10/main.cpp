//
//  main.cpp
//  offer-10
//
//  Created by 何昊 on 2017/1/25.
//  Copyright © 2017年 何昊. All rights reserved.
//
//  解法一
//  1 只有一列的时候有一种排列方法 return 1
//  2 只有两列的时候有两种排列方法 return 2
//  3 有n列的时候分两步
//    3.1 第一次摆一列，剩下 n - 1 列待排
//    3.2 第一次摆两列，剩下 n - 2 列待排
//    3.3 对于剩下的 n - 1 或者 n -2 个重复第三步


#include <iostream>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        if (number > 2) {
            return rectCover(number - 1) + rectCover(number - 2);
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    int n;
    Solution *p = new Solution();
    n = p->rectCover(8);
    cout << n << '\n';
    return 0;
}

