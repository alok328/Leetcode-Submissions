/*

Problem Statement:
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:

    1. The town judge trusts nobody.
    2. Everybody (except for the town judge) trusts the town judge.
    3. There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.
If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

Examples:

Input: N = 2, trust = [[1,2]]
Output: 2

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

*/
// Solution:
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        map<int, set<int>> m;
        for(auto x : trust){
            m[x[0]].insert(x[1]);
        }
        set<int> candidates;
        for(int i=1; i<=n; i++){
            if(m.find(i) == m.end()){
                candidates.insert(i);
            }
        }
        for(auto x : candidates){
            bool flag = false;
            for(int i=1; i<=n; i++){
                if(i != x){
                    if(m[i].find(x) == m[i].end()){
                        flag = false;
                        break;
                    }else{
                        flag = true;
                    }
                }
            }
            if(flag){
                return x;
            }
        }
        return -1;
    }
};