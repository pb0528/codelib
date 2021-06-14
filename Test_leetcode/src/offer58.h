#include<iostream>
#include<string>

using namespace std;

class solution58
{   
public:
    void reverseString(string& s, int start_pos, int end_pos)
    {
        for(int i = start_pos, j = end_pos - 1; i < j;)
        {
            swap(s[i++],s[j--]);
        }
    }
    void LeftRetotateString(string& s, const int& pos)
    {
        int len = s.size();
        reverseString(s,0,len);
        reverseString(s,0,len-pos);
        reverseString(s,len-pos,len);
    }
};
