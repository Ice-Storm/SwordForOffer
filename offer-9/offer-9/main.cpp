//
//  main.cpp
//  offer-9
//
//  Created by 何昊 on 2017/1/25.
//  Copyright © 2017年 何昊. All rights reserved.
//
//  解法一
//  跳台阶的升级版，按照跳台阶的思路
//  1. 有一个台阶 f(1) = 1 一种跳法
//  2. 有两个台阶 f(2) = 2 两种跳法
//  3. 有三个台阶 f(3) = f(2) + f(1)
//  4. 有三个台阶 f(4) = f(3) + f(2) + f(1)
//  5. 以此类推
//  特别注意，初始化count的时候为1， 因为有可能一次跳 n 个台阶，即一次跳完
//
//  解法二
//  用数组缓存结果，思路同解法一，性能更好一点


#include <iostream>
#include <vector>

using namespace std;

/**
 *    解法一
 *
 
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        int count = 1;
        for (int i = 1; i < number; i++) {
            count += jumpFloorII(number - i);
        }
        return count;
    }
};
*/

/**
 * 解法二
 */
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        vector<int> list(number);
        list[0] = 1;
        list[1] = 2;
        for (int i = 2; i < number; i++) {
            for (int j = 0; j < i; j++) {
                list[i] += list[j];
            }
            list[i] += 1;
        }
        return list[number - 1];
    }
};

int main(int argc, const char * argv[]) {
    int n = 0;
    Solution *p = new Solution();
    n = p->jumpFloorII(30);
    cout << n << '\n';
    return 0;
}
