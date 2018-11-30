// 34. Find First and Last Position of Element in Sorted Array
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower(nums,target);
        // cout<<l<<endl;
        int r = upper(nums, target);
        // cout<<r<<endl;
        if(l>=0&&nums[l]!=target) l++;
        if(r>=0&&nums[r]!=target) r--;
        if(l>r){
            return {-1,-1};
        }
        return {l,r};
    }
    int upper(vector<int> nums, int target){
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int m = l + (r-l)/2;
            if(nums[m]>target){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return r;
    }
    int lower(vector<int> nums, int target){
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int m = l + (r-l+1)/2;   // make sure ceiling
            if(nums[m]>=target){
                r = m-1;
            }
            else{
                l = m;
            }
        }
        return r;
    }
};