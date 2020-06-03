/*

Problem statement:

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

Examples:

Input: [3,2,3]
Output: 3

Input: [2,2,1,1,1,2,2]
Output: 2

*/
// Solution:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(auto x : nums){
            m[x]++;
        }
        int n = nums.size();
        int ans;
        for(auto x : nums){
            if(m[x] > n/2){
                ans = x;
                break;
            }
        }
        return ans;  
    }
};