//
//  main.cpp
//  offer-11
//
//  Created by 何昊 on 2017/1/24.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int  NumberOf1(int n) {
        if (n == 0) return 0;
        int count = 0;
        while(n!= 0){
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    int n = 0;
    Solution *p = new Solution();
    n = p->NumberOf1(-2147483648);
    cout << n << '\n';
    return 0;
}
