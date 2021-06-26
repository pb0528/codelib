/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution151 {
public:
    string reverseWords(string s) {
        int len = s.size();
        vector<int> word_len;
        int word_num = 0, char_num = 0 ,temp_len = 0; //记录字符串中的单词数以及每个单词的个数
        for(int i = 0 , k = 0; i < len;)
        {
            while(s[i]==' ' && i < len) i++;
            if(i >= len) break;
            word_num++;
            k = i;
            temp_len = char_num;
            while(s[k]!=' ' && k < len) {k++; char_num++;}
            word_len.emplace_back(char_num - temp_len);
            i = k;
        }
        int new_len = char_num+word_num-1;
        string result(new_len, ' '); //创建目标字串
        int index = 0;
        //从后向前搬运
        for(int i = 0, j = (len-1), k = (len-1); (j >= 0) && (i < new_len); )//"the sky is blue"
        {
            while(s[j] == ' ') j--;
            index++;
            int temp1 = i + word_len[word_num - index];
            int temp2 = temp1;
            temp2--;
            while( temp2 >= i) result[temp2--] = s[j--];
            i = temp1;  
            if(i < new_len) result[i++] = ' ';
        }
        return result;
    }
};