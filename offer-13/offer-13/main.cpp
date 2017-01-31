//
//  main.cpp
//  offer-13
//
//  Created by 何昊 on 2017/1/26.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> a;
        vector<int> b;
        vector<int> temp(array.size());
        temp = array;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 0)
                a.push_back(i);
            else
                b.push_back(i);
        }
        array.clear();
        for (int i = 0; i < b.size(); i++) {
            array.push_back(temp[b[i]]);
        }
        for (int i = 0; i < a.size(); i++) {
            array.push_back(temp[a[i]]);
        }
    }
};

int main(int argc, const char * argv[]) {
    int n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    vector<int> vn(n, n + 11);
    Solution *p = new Solution();
    p->reOrderArray(vn);
    for (int i = 0; i < vn.size(); i++){
        cout << vn[i] << ' ';
    }
    cout << '\n';
    return 0;
}
