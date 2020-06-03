/*

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

Examples:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Input: nums = [3,3,7,7,10,11,11]
Output: 10

*/
// Solution using logic of binary search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        if(nums.size() == 1){
            return nums[0];
        }
        while(l<=r){
            int m = l + (r-l)/2;
            if(m-1>=0 && nums[m-1] == nums[m]){
                int ls = m+l-1;
                int rs = r-m;
                if(ls%2 != 0){
                    r = m-2;
                }else{
                    l = m+1;
                }
            }else if(m+1 < nums.size() && nums[m+1] == nums[m]){
                int ls = m-l;
                int rs = r-m-1;
                if(ls%2 != 0){
                    r = m-1;
                }else{
                    l = m+2;
                }
            }else{
                return nums[m];
            }
        }
        return l;
    }
};