#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

/**
 请实现一个函数，将一个字符串中的空格替换成“%20”。
 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
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
								newStr[--j] = '2';
								newStr[--j] = '%';
						} else {
								newStr[j] = str[k];
						}
				}
				cout << newStr << '\n';
    }
};

int main(){
		char *s = "We Are Happy";
    Solution *p = new Solution();
    p->replaceSpace(s, 13);
    return 0;
}
