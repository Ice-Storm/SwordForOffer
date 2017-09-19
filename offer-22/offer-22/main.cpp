//
//  main.cpp
//  offer-22
//
//  Created by 何昊 on 2017/9/19.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 二叉树的层序遍历
 */


struct TreeNode {
    int val;
    struct TreeNode *left;
	struct TreeNode *right;
//	TreeNode(int x) :
//       val(x), left(NULL), right(NULL) {
//	}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> value_list;
        
        if (root == NULL) return value_list;
        
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        
        while(!node_queue.empty()) {
            TreeNode* front;
            front = node_queue.front();
            value_list.push_back(front->val);
            node_queue.pop();
            if(front->left) {
                node_queue.push(front->left);
            }
            if(front->right) {
                node_queue.push(front->right);
            }
        }
        return value_list;
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
    vector<int> node_list;
    
    node_list = p->PrintFromTopToBottom(&root);
    
    for(int i = 0; i < node_list.size(); i++){
        cout << node_list[i] << ' ';
    }
    
    cout << '\n';
    return 0;
}
