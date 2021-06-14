#include<string>

using namespace std;

class Solution23
{
public:
    string ReplaceSpace(string s)
    {
        int len = s.size(), num = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == ' ') num++;
        }
        s.resize(len + 2 * num, ' ');
        for(int i = len-1, j = s.size()-1; i < j; i--)
        {
            while(s[i] != ' ')
            {
                s[j--] = s[i--];
            }
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        }
        return s;
    }
};