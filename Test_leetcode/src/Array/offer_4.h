#include<vector>

namespace sole
{
    using namespace std;
    class solution_offer_4
    {
        public:
        bool find_num_in_two_diamond(const vector<int>& vec, const int& row, const int& col, const int& target)
        {
            int row_index = 0, col_index = col-1;
            
            while((row_index<row) && (col_index>=0))
            {
                int temp = vec[row_index*col+col_index];
                if(temp == target) return true;
                else if(target < temp) col_index--;
                else row_index++;
            }

            return false;
        }
    };
};