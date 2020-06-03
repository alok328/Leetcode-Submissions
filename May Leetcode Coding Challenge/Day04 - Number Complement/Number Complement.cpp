/*

Problem statement:
Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.

Examples:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

*/
/*Solution*/
class Solution {
public:
    int findComplement(int num) {
        string bin = ""; //flipped
        int rem;
        while(num>0){
            rem = num%2;
            num /= 2;
            bin += rem == 1 ? "0" : "1"; 
        }
        int ans=0, dig;
        for(int i=0; i<bin.length(); i++){
            dig = bin[i] == '1' ? 1 : 0;
            ans += pow(2, i) * dig;
        }
        return ans; 
    }
};