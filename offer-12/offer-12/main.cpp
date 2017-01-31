//
//  main.cpp
//  offer-12
//
//  Created by 何昊 on 2017/1/30.
//  Copyright © 2017年 何昊. All rights reserved.
//
//  解法一
//  快速幂算法
//  快速幂算法的核心思想是二分优化
//  A^8 = A * A * A * A * A * A * A * A 总共7次乘法
//  分解 A^8 = ( A * A * A * A ) ^ 2 总共四次乘法
//  再分解 A^8 = [(A * A) ^ 2] ^ 2 总共三次乘法 logn = 8 即 n = 3
//


#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 1) return 1;
        double n = 1;
        long long p = abs((long long)exponent);
        while (p) {
            if (p & 1) {
                // n为奇数
                n *= base;
            }
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1/n : n;
    }
};

int main(int argc, const char * argv[]) {
    int n = 0;
    Solution *p = new Solution();
    n = p->Power(8, 5);
    cout << n << '\n';
    return 0;
}
