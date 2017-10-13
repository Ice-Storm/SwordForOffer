//
//  main.cpp
//  offer-31
//
//  Created by 何昊 on 2017/10/10.
//  Copyright © 2017年 何昊. All rights reserved.
//
//  整数中1出现的次数（从1到n整数中1出现的次数）
//

/**
 * 解法二
 * 十位(0-9)上1的个数是1
 * 百位(10-99)上1的个数是10
 * 千位(100-999)上1的个数是100
 * 以此类推
 *
 * x / 10为不考虑最后一位的1的个数
 *
 * 考虑余数(最后一位的情况)
 *  1.如果余数大于1则在基础上+1
 *  2.如果余数等于1则n - current/10 + 1,因为当前位前的每一位变化都会影响1的个数
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if(n <= 0) return 0;

        int sum = 0;
        int number = 0;

        while(number <= n){
            int temp = number;
            while(temp > 0){
                if(temp % 10 == 1){
                    sum++;
                }
                temp /= 10;
            }
            number++;
        }
        return sum;
    }

    // 解法二
    int NumberOf1Between1AndN_Solution1(int n) {
        if(n <= 0) return 0;

        int sum = 0;
        int mult = 1;
        int current = n;

        while(current > 0){
            int quotient = current / 10;
            int remainder = current % 10;
            sum += quotient * mult;
            if(remainder > 1){
                sum += mult;
            }

            if(remainder == 1){
                sum += n - current * mult + 1;
            }

            mult *= 10;
            current /= 10;
        }

        return sum;
    }
};

int main(int argc, const char * argv[]) {
    Solution *p = new Solution();
    cout << p->NumberOf1Between1AndN_Solution(1000) <<'\n';
    return 0;
}
