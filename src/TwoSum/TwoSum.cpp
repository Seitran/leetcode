#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted_nums(nums);
        vector<int> ans(2);
        int ret, index1, index2;
        
        sort(sorted_nums.begin(), sorted_nums.end());

        for (int i = 0; i < sorted_nums.size(); i++) {
            if ((ret = binary_search(sorted_nums, i + 1, sorted_nums.size() - 1, target - sorted_nums[i])) > 0) {
                index1 = get_index(nums, sorted_nums[i], -1);
                index2 = get_index(nums, sorted_nums[ret], index1);
                
                ans[0] = index1 < index2 ? index1 + 1 : index2 + 1;
                ans[1] = index1 < index2 ? index2 + 1 : index1 + 1;
                return ans;
            }
            
        }
    }

    static int get_index(vector<int>& array, int value, int except_index)
    {
        int index;
        for (int i = 0; i < array.size(); i++)
            if (array[i] == value && except_index != i)
                return i;
        return -1;
    }
    
    static int binary_search(vector<int>& array, int begin_index, int end_index, int target)
    {
        int mid_index = (begin_index + end_index) / 2;
        
        if (begin_index > end_index)
            return -1;

        if (array[mid_index] > target) {
            end_index = mid_index - 1;
        } else if (array[mid_index] < target) {
            begin_index = mid_index + 1;
        } else return mid_index;
        return binary_search(array, begin_index, end_index, target);
    }
};

int main(void)
{
    Solution *solution = new Solution();
    vector<int> nums(4);
    nums[0] = 7;
    nums[1] = 11;
    nums[2] = 15;
    nums[3] = 2;
    vector<int> ans = solution->twoSum(nums, 9);
    
    
    return 0;
}




