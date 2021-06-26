#include<string>
#include<algorithm>
using namespace std;

class Solution541 {
public:
    void swap_str(string& s, const int& start, const int& end)
    {
        for(int k = start, j = end;k < j;)
        {
            swap(s[k++],s[j--]);
        }
    }
    string reverseStr(string s, int k) {
        int len = s.size();
        for(int i = 0; i < len;)
        {
            if((len - i) < k) 
            {
                swap_str(s, i, len-1);
                break;
            }
            else
            if((len - i) < (2*k))
            {
                swap_str(s, i, (i+k-1));
                break;
            }
            swap_str(s, i, (i+k-1));
            i+=(2*k);
        }
        return s;
    }
};