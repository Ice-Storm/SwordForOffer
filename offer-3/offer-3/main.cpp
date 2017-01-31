//
//  main.cpp
//  offer-3
//
//  Created by 何昊 on 2017/1/21.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> valList;
        if (head == NULL) return valList;
        while (head) {
            valList.push_back(head->val);
            head = head->next;
        }
        int i = 0;
        int j = valList.size() - 1;
        while (i < j) {
            int temp;
            temp = valList[i];
            valList[i] = valList[j];
            valList[j] = temp;
            i++;
            j--;
        }
        return valList;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> list;
    struct ListNode *pn, *pnn;
    struct ListNode nn = { 8, NULL };
    pnn = &nn;
    struct ListNode n = { 9, pnn };
    pn = &n;
    Solution *p = new Solution();
    list = p->printListFromTailToHead(pn);
    for (int i = 0; i < list.size(); i++) {
        cout << list[i];
    }
    return 0;
}
