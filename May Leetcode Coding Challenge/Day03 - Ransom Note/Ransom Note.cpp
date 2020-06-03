/*

Problem statement:
Given an arbitrary ransom note string and another string containing letters from all the magazines, 
write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Example:

Input: J = "aA", S = "aAAbbbb"
Output: 3

*/
/* Solution */
class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char, int> s;
        for(char c : m){
            s[c]++;
        }
        for(char c : r){
            if(s[c]>0){
                s[c]-=1;
            }else{
                return false;
            }
        }
        return true;
    }
};