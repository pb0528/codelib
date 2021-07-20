#include<vector>
#include<stack>
#include<iostream>

namespace NMN
{
    using namespace std;
    vector<int> FindNMaxNum(const vector<int>& vec)
    {
        stack<int> reqList;
        vector<int> result(vec.size(), -1);
        bool is_req = false;
        for(int i=0; i<vec.size(); i++)
        {
            is_req = true;
            while(!reqList.empty() && is_req)
            {
                int temp = reqList.top();
                if(vec[i] > vec[temp])  
                {
                    result[temp] = vec[i];
                    reqList.pop();
                }
                else
                {
                    reqList.push(i);
                    is_req = false;
                }
            }
            
            reqList.push(i);  //压栈
        }

        return result;
    }

    void test()
    {
        vector<int> req = {1, 3, 2, 4, 99, 101, 5, 8};
        vector<int> result = FindNMaxNum(req);
        for(auto i : result)
        {
            cout<< i <<" ";
        }

        cout<<'\n';
    }
}