//
//  main.cpp
//  offer-18
//
//  Created by 何昊 on 2017/1/28.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) return;
        struct TreeNode *temp;
        temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

int main(int argc, const char * argv[]) {
    struct TreeNode root { 8 };
    struct TreeNode node1 { 6 };
    struct TreeNode node2 { 10 };
    struct TreeNode node3 { 5 };
    
    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    
    Solution *p = new Solution();
    p->Mirror(&root);
    
    cout << root.right->val << '\n';
    return 0;
}

