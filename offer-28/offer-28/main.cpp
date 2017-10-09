//
//  main.cpp
//  offer-28
//
//  Created by 何昊 on 2017/10/4.
//  Copyright © 2017年 何昊. All rights reserved.
//
//  数组中出现次数超过一半的数字
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/**
 * 需要注意的是 len 变量的类型要是float，负责在后面 floor((len / 2)) 的时候会截断小数部分，导致floor没有向下取整
 * /

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() <= 0) return 0;

        sort(numbers.begin(), numbers.end());
        float len = numbers.size();
        int temp = numbers[0];
        int count = 0;
        for(int i = 0; i < (int)numbers.size(); i++){
            if(numbers[i] == temp){
                count++;
                if(count > floor(len / 2)) return numbers[i];
            }
            if(numbers[i] != temp && count){
                count = 1;
                temp = numbers[i];
            }
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution *p = new Solution();
    int numbers[9] = {1,2,3,2,4,2,5,2,3};
    vector<int> list(numbers, numbers + 9);
    cout << p->MoreThanHalfNum_Solution(list) << '\n';
    return 0;
}
