#include<string>
#include<vector>
#include<iostream>

namespace sole
{
    #define print(x) std::cout<<x<<std::endl
    using namespace std;
    bool hasCorePath(const vector<char>& char_map, const int& row, const int& col, const string& str, int row_index, int col_index, vector<bool>& visited, int& len)
    {
        if(len == str.size()) return true;
        bool is_in_path = false;
        if((row_index < row) && (col_index < col) && (row_index >= 0) && (col_index >= 0) && (char_map[row_index*col+col_index] == str[len]) 
            && !visited[row_index*col+col_index])
        {
            len++;
            visited[row_index*col+col_index] = true;
            is_in_path = hasCorePath(char_map, row, col, str, row_index+1, col_index, visited, len) ||
                        hasCorePath(char_map, row, col, str, row_index-1, col_index, visited, len) ||
                        hasCorePath(char_map, row, col, str, row_index, col_index+1, visited, len) ||
                        hasCorePath(char_map, row, col, str, row_index, col_index-1, visited, len);
            
            if(!is_in_path) 
            {
                len--;
                visited[row_index*col+col_index] = false;
            }
        }

        return is_in_path;
    }

    bool hasPath(const vector<char>& char_map, const int& row, const int& col, const string& str)
    {
        vector<bool> visited(char_map.size(),0);
        int len = 0;
        for(int i=0; i<row;i++)
            for (int j = 0; j < col; j++)
            {
                if(hasCorePath(char_map,row,col,str,i,j,visited,len))
                    return true;
            }
        
        return false;
            
    }  

    void test()
    {
        vector<char> test_data = {'a', 'b', 't', 'g', 'c', 'f', 'c', 's', 'j', 'd', 'e', 'h'};
        string str = "bfce";
        print(hasPath(test_data, 3, 4, str));
    }
    
};