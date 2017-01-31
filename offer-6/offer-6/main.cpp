//
//  main.cpp
//  offer-6
//
//  Created by 何昊 on 2017/1/24.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 *  解法一
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() <= 0) return 0;
        int temp = rotateArray.front();
        for (int i = 0; i < rotateArray.size(); i++) {
            if (rotateArray[i] < temp) {
                temp = rotateArray[i];
            }
        }
        return temp;
    }
};
*/

/**
 * 解法二
 */
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() <= 0) return 0;
        int left = 0;
        int right = rotateArray.size() - 1;
        int temp = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (rotateArray[left] < rotateArray[mid]) {
                left = mid;
            } else if (rotateArray[right] > rotateArray[mid]) {
                right = mid;
            } else {
                return rotateArray[mid + 1];
            }
        }
        return temp;
    }
};


int main(int argc, const char * argv[]) {
    int min;
    int arr[] = {3, 4, 5, 1, 2};
    vector<int> testDate(arr, arr + 5);
    Solution *p = new Solution();
    min = p->minNumberInRotateArray(testDate);
    cout << min << '\n';
    return 0;
}
