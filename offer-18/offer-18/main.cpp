//
//  main.cpp
//  offer-18
//
//  Created by 何昊 on 2017/1/28.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <stack>

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
  
  void Mirror2(TreeNode *pRoot) {
    if (pRoot == NULL) return;
    stack<TreeNode*> nodeStack;
    nodeStack.push(pRoot);
    while(!nodeStack.empty()){
      struct TreeNode* top = nodeStack.top();
      nodeStack.pop();
      struct TreeNode* tmpNode = top->left;
      top->left = top->right;
      top->right = tmpNode;
      if(top->left != NULL) nodeStack.push(top->left);
      if(top->right != NULL) nodeStack.push(top->right);
    }
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

