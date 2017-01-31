//
//  main.cpp
//  offer-14
//
//  Created by 何昊 on 2017/1/28.
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL) return pListHead;
        struct ListNode *n, *head;
        head = pListHead;
        int t = 0, count = 0;
        while (pListHead) {
            pListHead = pListHead->next;
            count++;
        }
        if (k <= count){
            count -= k;
        }
        while (t < count) {
            head = head->next;
            t++;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    struct ListNode root{1};
    struct ListNode node1{2};
    struct ListNode node2{3};
    struct ListNode node3{4};
    struct ListNode *t;
    root.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    Solution *p = new Solution();
    t = p->FindKthToTail(&root, 2);
    cout << t->val << '\n';
    return 0;
}
