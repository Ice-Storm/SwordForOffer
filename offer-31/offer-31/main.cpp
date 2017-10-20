//
//  main.cpp
//  offer-31
//
//  Created by 何昊 on 2017/10/20.
//  Copyright © 2017年 何昊. All rights reserved.
//
//  把数组排成最小的数
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/**
 * 在字典中，单词是按照首字母在字母表中的顺序进行排列的，比如 alpha 在 beta 之前。而第一个字母相同时，会去比较两个单词的第二个字母在字母表中的顺序，比如 account 在 advanced 之前，以此类推。
 * 下列单词就是按照字典序进行排列的
 * as
 * aster
 * astro
 * 从大到小
 */

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> stringifyNumbers;
        stringstream stream;
        string result;
        for(int i = 0; i < numbers.size(); i++) {
            stream.clear();
            stream << numbers[i];
            stream >> stringifyNumbers[i];
        }
        sort(stringifyNumbers.begin(), stringifyNumbers.end(), strCompare);
        for(int i = 0; i < stringifyNumbers.size(); i++) {
            result += stringifyNumbers[i];
        }
        return result;
    }

    static bool strCompare(string str, string otherStr) {
        string tempStr = str;
        str = str + otherStr;
        otherStr = tempStr + otherStr;
        return str.compare(otherStr) < 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution *p = new Solution();
    int temp[3] = {3, 32, 321};
    vector<int> arr(temp, temp + 3);
    cout << p->PrintMinNumber(arr) << '\n';
    return 0;
}
