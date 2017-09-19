//
//  main.cpp
//  offer-21
//
//  Created by 何昊 on 2017/9/18.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 *  使用一个栈来进行模拟
 *  输出的向量的当前指针指向的元素必然是栈顶元素(输出序列有效的情况下)
 */

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack <int> st;
        int j = 0;
        for(int i = 0; i < popV.size(); i++) {
            st.push(pushV[i]);
            while(!st.empty() && st.top() == popV[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty() ? true : false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input = {1, 2, 3, 4, 5};
    vector<int> output = {4, 5, 3, 2, 1};
    
    Solution *p = new Solution();
    
    cout << p->IsPopOrder(input, output) << '\n';
    
    return 0;
}
