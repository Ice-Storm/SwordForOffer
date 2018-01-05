//
//  main.cpp
//  offer-29
//
//  Created by 何昊 on 2017/10/20.
//  Copyright © 2017年 何昊. All rights reserved.
//
//  连续子数组的最大和
//

#include <iostream>
#include <vector>

using namespace std;

// {6,-3,-2,7,-15,1,2,2}

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxValue = array[0];
        for(int i = 0; i < array.size(); i++) {
            for(int j = i; j < array.size(); j++) {
                int temp = 0;
                for(int k = i; k <= j; k++) {
                    temp += array[k];
                }
                maxValue = max(temp, maxValue);
            }
        }
        return maxValue;
    }
    
    int FindGreatestSumOfSubArray1(vector<int> array) {
        int temp = array[0];
        int currentValue = array[0];
        for(int i = 1; i < array.size(); i++) {
            if(currentValue > 0) {
                currentValue += array[i];
            } else {
                currentValue = array[i];
            }
            if(currentValue > temp) temp = currentValue;
        }
        return currentValue;
    }
};

int main(int argc, const char * argv[]) {
    Solution *p = new Solution();
    int arr[8] = {1,-2,3,10,-4,7,2,-5};
    vector<int> list(arr, arr + 8);
    cout << p->FindGreatestSumOfSubArray1(list) << '\n';
    return 0;
}
