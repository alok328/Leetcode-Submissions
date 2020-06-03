/*

Problem statement:
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.
Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. 
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Examples:

Input: J = "aA", S = "aAAbbbb"
Output: 3

Input: J = "z", S = "ZZ"
Output: 0

*/
/*Solution*/
class Solution {
public:
    int numJewelsInStones(string j, string s) {
        set<char> jewels;
        for(char c : j){
            jewels.insert(c);
        }
        int count = 0;
        for(char c : s){
            if(jewels.find(c) != jewels.end()){
                count++;
            }
        }
        return count;
    }
};