//
//  main.cpp
//  offer-5
//
//  Created by 何昊 on 2017/1/21.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
    
    int pop() {
        int result;
        int size1 = stack1.size();
        while (size1 > 0) {
            stack2.push(stack1.top());
            stack1.pop();
            size1--;
        }
        result = stack2.top();
        stack2.pop();
        int size2 = stack2.size();
        while (size2 > 0) {
            stack1.push(stack2.top());
            stack2.pop();
            size2--;
        }
        return result;
    }
    
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, const char * argv[]) {
    Solution *p = new Solution();
    p->push(1);
    p->push(2);
    p->push(3);
    cout << p->pop() << '\n';
    cout << p->pop() << '\n';
    cout << '\n';
    return 0;
}
