#include<vector>
#include<queue>
#include<iostream>
#include<iterator>

namespace sol
{
    using namespace std;
    int findSmallestComm(const vector<int> &vec1, const vector<int> &vec2, const vector<int> &vec3)
    {

        int len1 = vec1.size(), len2 = vec2.size(), len3 = vec3.size();
        for (int i = 0; i < len1; i++)
        {
            for (int k = 0; k < len2; k++)
            {
                if (vec1[i] == vec2[k])
                {
                    for (int m = 0; m < len3; m++)
                    {
                        if (vec1[i] == vec3[m])
                            return vec3[m];
                    }
                }
            }
        }

        return -1;
    } //O(N3)

    int find_max(int *pointer_a, int *pointer_b, int *pointer_c)
    {
        int *temp = *pointer_a < *pointer_b ? pointer_b : pointer_a;
        temp = (*temp < *pointer_c) ? pointer_c : temp;
        return *temp;
    }

    int findSmallestComm_2(const vector<int> &vec1, const vector<int> &vec2, const vector<int> &vec3)
    {
        int len1 = vec1.size(), len2 = vec2.size(), len3 = vec3.size();
        int *p1 = const_cast<int *>(vec1.data());
        int *p2 = const_cast<int *>(vec2.data());
        int *p3 = const_cast<int *>(vec3.data());
        while ((p1 < (p1 + len1)) && (p2 < (p2 + len2)) && (p3 < (p3 + len3)))
        {
            int max_num = find_max(p1, p2, p3);
            while ((*p1) <= max_num && (p1 < (p1 + len1)))
                p1++;
            while ((*p2) <= max_num && (p2 < (p2 + len2)))
                p2++;
            while ((*p3) <= max_num && (p3 < (p3 + len3)))
                p3++;
            //int m = *(p1-1) , k = *(p2-1), mo = *(p3-1);
            if ((*(p1 - 1) == *(p2 - 1)) && (*(p1 - 1) == *(p3 - 1)) && (*(p3 - 1) == *(p2 - 1)))
                return *(p1 - 1);
        }
        return -1;
    }

    void kthlargestElement(const vector<int> &vec, const int &size, const int &k)
    {
        priority_queue<int, vector<int>, greater<int>> result; //小顶堆
        for (int i = 0; i < size; i++)
        {
            result.push(vec[i]);
            if (result.size() > k)
                result.pop();
        }

        if (!result.empty())
            cout << result.top() << endl;
    }

    int partion(vector<int> &vec, int begin, int end)
    {
        int len = vec.size();
        if (begin < 0 || end >= len)
            return -1;
        int smaller = begin - 1, flag = (begin + end) / 2;
        //int target = vec[flag];
        swap(vec[flag], vec[end]);
        for (int i = begin; i < end; i++)
        {
            if (vec[i] < vec[end])
            {
                smaller++;
                if (smaller != i)
                    swap(vec[i], vec[smaller]);
            }
        }
        smaller++;
        swap(vec[smaller], vec[end]);
        return smaller;
    }

    void kth_smallest_element(vector<int> &vec, const int &k)
    {
        int start = 0, end = vec.size() - 1;
        int index = partion(vec, start, end);
        while (index != k - 1)
        {
            if (index > k - 1)
            {
                end = index - 1;
                index = partion(vec, start, end);
            }
            else
            {
                start = index + 1;
                index = partion(vec, start, end);
            }
        }

        for (int i = 0; i < k; i++)
            std::cout << vec[i] << " ";
        std::cout << '\n';
    }

    void test()
    {
        vector<int> vec= {4,5,1,6,2,7,3,8};
        kth_smallest_element(vec,3);
    }

    int find_max_sum_sub_array(vector<int> vec, int n)
    {
        if (vec.size() < n)
            return -1;
        int len = vec.size();
        int pre = 0, next = n - 1, result = 0, sum = 0;
        for (int i = pre; i <= next; i++)
        {
            sum += vec[i];
        }
        if (n == len)
            return sum;
        pre++;
        next++;
        for (int i = pre; next < len;)
        {
            int temp = sum;
            temp -= vec[pre++];
            temp += vec[next++];
            sum = (temp > sum ? temp : sum);
        }
        return sum;
    }

    vector<int> reflectLine(vector<int> vec, int n)
    {
        int len = vec.size();
        vector<int> result;
        if (len == 2)
        {
            result = {vec[1], vec[2]};
        }
        else
        {
        }
    }
}
