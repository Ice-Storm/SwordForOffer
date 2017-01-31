//
//  main.cpp
//  offer-19
//
//  Created by 何昊 on 2017/1/26.
//  Copyright © 2017年 何昊. All rights reserved.
//
//  解法一
//  假设矩阵四个角的点分别为 a b c d
//
//  a(1)  2   3   4   5   b(6)
//  7     8   9   10  11  12
//  c(13) 14  15  16  17  d(18)
//
//  然后每次输出完一行或者一列,那一行或者列的两个点向中心收敛
//  上面那个矩阵按这个算法输出的时候会在 8 - 11 区间反复输出，所以最后还要去重，解法有点麻烦



#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * 解法一
 */
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.size() <= 0) return matrix[0];
        vector<int> result;
        map<char, int> a, b, c, d;
        int col = matrix.size() - 1;
        int row = matrix[0].size() - 1;
        
        a['x'] = a['y'] = b['y'] = c['x'] = 0;
        d['x'] = b['x'] = row;
        d['y'] = c['y'] = col;
        
        while (a['x'] <= d['x'] && a['y'] <= d['y']) {
            for (int i = a['x']; i <= b['x']; i++) {
                result.push_back(matrix[a['y']][i]);
            }
            a['y'] += 1;
            b['y'] += 1;
            for (int j = b['y']; j <= d['y']; j++) {
                result.push_back(matrix[j][b['x']]);
            }
            b['x'] -= 1;
            d['x'] -= 1;
            for (int k = d['x']; k >= c['x']; k--) {
                result.push_back(matrix[c['y']][k]);
            }
            d['y'] -= 1;
            c['y'] -= 1;
            for (int m = c['y']; m >= a['y']; m--) {
                result.push_back(matrix[m][c['x']]);
            }
            c['x'] += 1;
            a['x'] += 1;
        }
        
        vector<int> temp;
        temp.push_back(result[0]);
        for (int i = 0; i < result.size(); i++) {
            int repeat = 0;
            for (int j = 0; j < temp.size(); j++) {
                if(result[i] == temp[j]) {
                    repeat = 1;
                    break;
                }
            }
            if (repeat != 1) temp.push_back(result[i]);
        }
        return temp;
    }
};

int main(int argc, const char * argv[]) {
    int m[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    vector<vector<int> > matrix(3, vector<int>(5));
    vector<int> n;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = m[i][j];
        }
    }
    
    Solution *p = new Solution();
    n = p->printMatrix(matrix);
    
    for (int i = 0; i < n.size(); i++) {
        cout << n[i] << ' ';
    }
    cout << '\n';
    return 0;
}
