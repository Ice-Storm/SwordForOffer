//
//  main.cpp
//  offer-25
//
//  Created by 何昊 on 2017/9/25.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode {
 int label;
 struct RandomListNode *next, *random;
 RandomListNode(int x) :
    label(x), next(NULL), random(NULL) {
 }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead == NULL) return NULL;
        RandomListNode* cursor = pHead;
        
        // 插入新节点
        while(cursor){
            RandomListNode* nNode = new RandomListNode(cursor->label);
            nNode->next = cursor->next;
            cursor->next = nNode;
            cursor = nNode->next;
        }

        // 复制random指针
        cursor = pHead;
        while(cursor){
            RandomListNode* newListCursor = cursor->next;
            if(cursor->random){
                newListCursor->random = cursor->random->next;
            }
            cursor = newListCursor->next;
        }
        
        // 拆分链表
        cursor = pHead;
        RandomListNode* temp;
        RandomListNode* newListHead = pHead->next;
        while(cursor->next){
            temp = cursor->next;
            cursor->next = temp->next;
            cursor = temp;
        }

        return newListHead;
    }
};

int main() {
    Solution *p = new Solution();
    RandomListNode* a = new RandomListNode(1);
    RandomListNode* b = new RandomListNode(2);
    RandomListNode* c = new RandomListNode(3);
    a->next = b;
    b->random = a;
    cout << p->Clone(a)->label << '\n';
    return 0;
}
