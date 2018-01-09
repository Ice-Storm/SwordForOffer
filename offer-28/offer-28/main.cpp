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
 */

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
    
    /**
     * 解法二:
     *    当一个数字占数组超过一半必然有两个相同数字相邻的情况
     *    第一个循环找出相领的，但并不一定是超过半数的，如果必然数组有超过半数的就可以找出
     *    第二个循环最终确认是否是超过半数的
     */
    
    int MoreThanHalfNum_Solution2(vector<int> numbers) {
        if(numbers.size() <= 0) return 0;
        
        int result = numbers[0];
        int times = 1;
        
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] == result) {
                times++;
            } else if(times <= 0) {
                result = numbers[i];
                times = 1;
            } else {
                times--;
            }
        }
        
        times = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] == result) times++;
        }
        
        return (numbers.size() / 2) >= times ? 0 : result;
    }
};

int main(int argc, const char * argv[]) {
    Solution *p = new Solution();
    int numbers[9] = {1,2,3,2,4,2,5,2,3};
    vector<int> list(numbers, numbers + 9);
    cout << p->MoreThanHalfNum_Solution(list) << '\n';
    return 0;
}
