//
//  main.cpp
//  offer-15
//
//  Created by 何昊 on 2017/12/25.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
};

class Solution {
public:
  ListNode* ReverseList(ListNode* pHead) {
    /*
    刚开始写直接操作pHead,既对源数据修改，又依赖源数据产生新数据，极其容易出现bug，引以为戒
    突然想起函数式编程的不可变数据~
     
    if(pHead == NULL) return pHead;
    struct ListNode *preNode = NULL;
    struct ListNode *newHead = NULL;
    while(pHead->next) {
      struct ListNode *nextNode = pHead->next;
      if (nextNode->next == NULL) newHead = nextNode;
      pHead->next = preNode;
      preNode = pHead;
      pHead = nextNode;
      
    }
    return newHead;
    */
    
    /*
     第一次翻转的时候preNode是null，第一个节点翻转以后就是最后一个节点。
     当时面growingIO的时候写错了这道题，没有freebug，记忆犹新
     */
    
    if(pHead == NULL) return pHead;
    struct ListNode *preNode = NULL;
    struct ListNode *newHead = NULL;
    struct ListNode *pNode = pHead;
    
    while(pNode != NULL) {
      struct ListNode *nextNode = pNode->next;
      if(pNode->next == NULL) newHead = pNode;
      pNode->next = preNode;
      preNode = pNode;
      pNode = nextNode;
    }
    return newHead;
  }
  
  ListNode* ReverseList2(ListNode* pHead) {
    if(pHead == NULL || pHead->next == NULL) return pHead;
    struct ListNode *newHead = ReverseList2(pHead->next);
    pHead->next->next = pHead;
    pHead->next = NULL;
    return newHead;
  }
};

int main(int argc, const char * argv[]) {
  struct ListNode node1 {1};
  struct ListNode node2 {2};
  struct ListNode node3 {3};
  
  node1.next = &node2;
  node2.next = &node3;
  
  Solution *p = new Solution();
  cout << p->ReverseList(&node1)->val << '\n';
  
  return 0;
}
