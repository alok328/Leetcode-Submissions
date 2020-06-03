/*

Problem Statement:

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

Example:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

*/
/*Solution by comparing slopes*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1, y1, x2, y2;
        x1 = coordinates[0][0];
        y1 = coordinates[0][1];
        x2 = coordinates[coordinates.size()-1][0];
        y2 = coordinates[coordinates.size()-1][1];
        float mi = (float)(y2-y1)/(x2-x1);
        float mf;
        int x, y;
        for(int i=1; i<coordinates.size()-1; i++){
            x = coordinates[i][0];
            y = coordinates[i][1];
            mf = (float)(y-y1)/(x-x1);
            if(mf!=mi){
                return false;
            }
        }
        return true;
    }
};