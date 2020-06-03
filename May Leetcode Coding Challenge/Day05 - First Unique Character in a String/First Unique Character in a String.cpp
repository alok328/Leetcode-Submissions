/*

Problem Statement:

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

*/

/*Solution*/
class Solution {
public:
    int firstUniqChar(string s) {
        int counts[26] = {0};
        for(char c : s){
            counts[c - 97] += 1; 
        }
        int ans = 0;
        for(char c : s){
            if(counts[c-97] == 1){
                return ans;
            }
            ans++;
        }
        return -1;
    }
};