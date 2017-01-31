//
//  main.cpp
//  offer-16
//
//  Created by 何昊 on 2017/1/30.
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* result = NULL;
        ListNode* current = NULL;
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        while (pHead1 != NULL && pHead2 != NULL) {
            if (pHead1->val <= pHead2->val) {
                if (result == NULL) {
                    current = result = pHead1;
                } else {
                    current->next = pHead1;
                    current = current->next;
                }
                pHead1 = pHead1->next;
            } else {
                if(result == NULL){
                    current = result = pHead2;
                } else {
                    current->next = pHead2;
                    current = current->next;
                }
                pHead2 = pHead2->next;
            }
        }
        
        if (pHead1 == NULL) {
            current->next = pHead2;
        }
        if (pHead2 == NULL) {
            current->next = pHead1;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    struct ListNode n1 {1};
    struct ListNode n2 {2};
    struct ListNode n3 {33};
    struct ListNode n4 {44};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    struct ListNode k1 {6};
    struct ListNode k2 {7};
    struct ListNode k3 {8};
    struct ListNode k4 {9};
    k1.next = &k2;
    k2.next = &k3;
    k3.next = &k4;
    
    struct ListNode *t1, *t2, *t;
    t1 = &n1;
    t2 = &k1;
    Solution *p = new Solution();
    t = p->Merge(t1, t2);
    cout << t->next->next->next->next->next->val << '\n';
    return 0;
}
