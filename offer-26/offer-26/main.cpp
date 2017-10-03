//
//  main.cpp
//  offer-26
//
//  Created by 何昊 on 2017/9/29.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * 因子就是所有可以整除这个数的数,但是不包括这个数自身. 比如15的因子是1，3，5
 * 第一种方法暴力穷举
 * 需要注意的是第一个丑数是 1 ，如果是0丑数检查的时候会出现死循环
 *
 * 当时考虑丑数12的组合可以是 2 * 2 * 3，或者3 * 2 * 2，或者 2 * 3 * 2，后面考虑到可以
 * 交换律统一成 2 * 2 * 3这样，所以直接用while穷举
 */

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        int range = 10000;
        vector<int> result;
        for(int i = 1; i < range; i++) {
            if(isUglyNumber(i)){
                result.push_back(i);
            }
        }
        return result[index];
    }

    int isUglyNumber(int num) {
        while(num % 2 == 0){
            num /= 2;
        }
        while(num % 3 == 0){
            num /= 3;
        }
        while(num % 5 == 0){
            num /= 5;
        }
        return num == 1 ? true : false;
    }

    /**
     * 另一种解法
     * 假设有若干个已排序丑数在列表里，新产生的丑数必然是列表里的丑数乘2， 3， 5产生的。
     * 假设列表最大丑数为N，列表中的丑数乘以2的数如果小于N，则在列表中，若大于N，则取第一个大于N的数
     * 乘3， 乘5同理，最后取这三个数最小的
     */

    int GetUglyNumber_Solution2(int index) {
        if(index < 0) return 0;

        vector<int> uglySortV;
        uglySortV.push_back(1);

        int cursor = 0;
        int a, b, c;
        while(uglySortV.size() < index){
            int critical = uglySortV[cursor];

            for(int i = 0; i < uglySortV.size(); i++){
                if(uglySortV[i] * 2 > critical){
                    a = uglySortV[i] * 2;
                    break;
                }
            }

            for(int j = 0; j < uglySortV.size(); j++){
                if(uglySortV[j] * 3 > critical){
                    b = uglySortV[j] * 3;
                    break;
                }
            }

            for(int k = 0; k < uglySortV.size(); k++){
                if(uglySortV[k] * 5 > critical){
                    c = uglySortV[k] * 5;
                    break;
                }
            }

            uglySortV.push_back(min(a, min(b, c)));
            cursor++;
        }

        return uglySortV[index - 1];
    }
};


int main(int argc, const char * argv[]) {
    Solution *p = new Solution();

    cout << p->GetUglyNumber_Solution2(150) << "\n";
    return 0;
}
