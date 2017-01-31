//
//  main.cpp
//  offer-20
//
//  Created by 何昊 on 2017/1/26.
//  Copyright © 2017年 何昊. All rights reserved.
//
//  解法一
//  思路非常像用两个栈实现队列的解法,注意获得两个栈长度的位置就好。

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    stack<int> s1, s2;
    void push(int value) {
        s1.push(value);
    }
    void pop() {
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        int size1 = s1.size();
        int min = s1.top();
        int temp;
        while (size1 > 0) {
            temp = s1.top();
            min = temp < min ? temp : min;
            s2.push(temp);
            s1.pop();
            size1--;
        }
        int size2 = s2.size();
        while (size2 > 0) {
            s1.push(s2.top());
            s2.pop();
            size2--;
        }
        return min;
    }
};

int main(int argc, const char * argv[]) {
    Solution *p = new Solution();
    p->push(3);
    p->min();
    p->push(4);
    cout << p->min() << '\n';
    return 0;
}
