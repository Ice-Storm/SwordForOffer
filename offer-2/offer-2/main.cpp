//
//  main.cpp
//  offer-2
//
//  Created by 何昊 on 2017/2/1.
//  Copyright © 2017年 何昊. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 *  解法一
 *  替换空格，可以按要求打印，没有按OJ调整输出，感觉OJ输出莫名其妙，第二种解法调整了
 */
class Solution {
public:
    void replaceSpace(char *str, int length) {
        if (str == NULL || length < 0) return;
            int spaceNum = 0;
            int newStrLen = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') spaceNum++;
        }
        newStrLen = length + spaceNum * 2;
        char newStr[newStrLen];
        int j, k;
        for (k = length, j = newStrLen; k >= 0; k--, j--) {
            if (str[k] == ' ') {
                newStr[j] = '0';
                j--;
                newStr[j] = '2';
                j--;
                newStr[j] = '%';
            } else {
                newStr[j] = str[k];
            }
        }
        cout << newStr << '\n';
    }
 };
 
/*
class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str==NULL||length<=0)
            return;
        int i=0;
        int oldLength=0;
        int spaceNum=0;
        while(str[i]!='\0'){
            oldLength++;
            if(str[i]==' ')
                spaceNum++;
            i++;
        }
        int newLength=oldLength+spaceNum*2;
        if(newLength>length){
            cout << length;
            return;
        }
        
        int pOldLength=oldLength;
        int pNewLength=newLength;
        while(pOldLength>=0&&pNewLength>pOldLength){
            if(str[pOldLength]==' '){
                str[pNewLength--]='0';
                str[pNewLength--]='2';
                str[pNewLength--]='%';
            }else{
                str[pNewLength--]=str[pOldLength];
            }
            pOldLength--;
        }
    }
};*/

int main(int argc, const char * argv[]) {
    char *s = "We Are Happy";
    Solution *p = new Solution();
    p->replaceSpace(s, 13);
    cout << '\n';
    return 0;
}
