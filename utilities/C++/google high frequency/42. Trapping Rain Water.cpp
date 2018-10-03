// 42. Trapping Rain Water
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
 */
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> l(height.size(),0);
        vector<int> r(height.size(),0);
        for(int i=1;i<height.size();i++){
            l[i]=max(l[i-1],height[i-1]);
        }
        
        
        for(int i=height.size()-2;i>=0;i--){
            r[i]=max(r[i+1],height[i+1]);
        }
        int sum = 0;
        for(int i=0;i<height.size();i++){
            // cout<<min(l[i],r[i])-height[i]<<" ";
            int num = min(l[i],r[i])-height[i];
            sum += num>0? num:0;
        }
        cout<<endl;
        return sum;
    }
};