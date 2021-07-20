#include<vector>
#include<string>
#include<iostream>
#include<stack>
#include<deque>

namespace solu38
{
    using namespace std;

    void permutation(string& str, int len, int pos);
    void print_stack(stack<char>& result);
    void combination(string& str, int pos, int len, deque<char>& result);
    void print_stack(deque<char>& source);
    void print_string(string& str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            permutation(str,0,i);
        }
        
    }

    void permutation(string& str, int len, int pos)
    {
        if( len == (str.size()-1)) 
        {
            cout<<str<<endl;
            return ;
        }
        swap(str[len], str[pos]);
        for(int i = len+1; i < str.size(); i++)
        {
            permutation(str,len+1,i);
        }
        swap(str[len],str[pos]);
    }

    void print_string_combination(string str)
    {
        deque<char> result;
        for(int i = 0; i < str.size(); i++)
        {
            combination(str, 0, i+1, result);
        }
    }

    void combination(string& str, int pos, int len, deque<char>& result)
    {
        if(result.size() == len)
        {
            print_stack(result);
            return;
        }
        
        if(pos < str.size())
        {
            result.push_back(str[pos]);
            //长度为m个字符中的 m-1的组合
            combination(str, pos + 1, len, result);
            result.pop_back();
            //长度为m字符中的 m的组合
            combination(str, pos + 1, len, result);
        }
    }

    void print_stack(deque<char>& source)
    {
        for(auto iter = source.begin(); iter!=source.end(); iter++)
        {
            std::cout<<*iter;
        }
        std::cout<<endl;
    }
}