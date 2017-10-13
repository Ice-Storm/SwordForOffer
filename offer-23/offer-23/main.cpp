//
//  main.cpp
//  offer-23
//
//  Created by 何昊 on 2017/9/21.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 二叉搜索树的左子树节点的值都小于根节点，右子树的所有节点的值都大于根节点
 * 后序遍历次序 -> 左右根
 */

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(!sequence.size()) return false;

        int result = true;
        for(int i = (int)sequence.size() - 1; i >= 0; i--) {
            int back_value = sequence[i];
            int j = 0;
            while(sequence[j++] < back_value);
            while(sequence[j++] > back_value);
            if(j < i) {
                result = false;
                break;
            }
        }
        return result;
    }
};

int main() {
    int temp[7] = {1, 3, 2, 7, 11, 8, 6};
    vector<int> bst_node(temp, temp + 7);
    Solution *p = new Solution();
    cout << p->VerifySquenceOfBST(bst_node) << '\n';
    return 0;
}
