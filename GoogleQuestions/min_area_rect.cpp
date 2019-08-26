/*
Question :
Given a set of points.
Find minimum area rectangle out of all possible rectangles formed.
Consider only rectangles formed with sides parallel to the x and y axes.
*/

/*
Similar LeetCode Problems : 
https://leetcode.com/problems/minimum-area-rectangle/
https://leetcode.com/problems/minimum-area-rectangle-ii/
*/

/*
Solution Analysis :
Time Complexity : O(n^2) where n is number of points
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int minAreaRect(vector<vector<int>>& points) {
    unordered_set<int> pointSet;

    // Assume that x and y coordinates are in range of (0,40000)
    // Also x and y coordinates are integers. 
    // This means that distance between every x coordinate is atleast 1 (same stands true for y coordinate)
    // So we can map all y coordinates for given x in space of 40000 uniquely
    // Hence our hash function can be : h(x,y) = 40001*x + y 
    
    int HASH_CONSTANT = 40001;
    for(vector<int> point : points){
        pointSet.insert(HASH_CONSTANT*point[0]+point[1]);
    }
    
    int minarea = INT_MAX;

    // Iterate over all pair of points
    for(int i=0; i<points.size(); i++){
        for(int j=i+1; j<points.size(); j++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];
            
            // Check if given pair can form diagonal of rectangle ?
            if(x1!=x2 && y1!=y2){

                // If yes, do we have another two missing points in our point set ?
                // Not that this method is only possible when we have rectangles parallel to x&y axes
                if(pointSet.find(HASH_CONSTANT*x1+y2) != pointSet.end() &&
                    pointSet.find(HASH_CONSTANT*x2+y1) != pointSet.end()){
                    minarea = min(minarea, abs(x2-x1)*abs(y2-y1));
                }
            }
        }
    }
    
    return (minarea == INT_MAX ? 0 : minarea);
}

int main(){

    vector<vector<int>> points1 = {{1,1},{1,3},{3,1},{3,3},{2,2}};
    assert(minAreaRect(points1) == 4);

    vector<vector<int>> points2 = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};
    assert(minAreaRect(points2) == 2);

    vector<vector<int>> points3 = {{1,1},{1,3},{3,1},{4,1}};
    assert(minAreaRect(points3) == 0);

    return 0;

}