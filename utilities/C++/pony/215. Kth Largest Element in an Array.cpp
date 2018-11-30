// 215. Kth Largest Element in an Array
// Medium
// 1408
// 135


// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Example 1:

// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
// Example 2:

// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    /*
    min heap nlogk
    4 min
    1 wrong
    */
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int, vector<int>, greater<int>> pq;
    //     for(int i=0;i<nums.size();i++){
    //         pq.push(nums[i]);
    //         if(pq.size()>k){
    //             pq.pop();
    //         }
    //     }
    //     return pq.top();
    // }
    /*
    max heap klogn
    quick select
    avg O(N)
    1. Initialize left to be 0 and right to be nums.size() - 1;
    2. Partition the array, if the pivot is at the k-1-th position, return it (we are done);
    3. If the pivot is right to the k-1-th position, update right to be the left neighbor of the pivot;
    4. Else update left to be the right neighbor of the pivot.
    5. Repeat 2.
    28 min
    7 wrong
    time: O(N)  avg
    space: O(h)
    */
    int partition(vector<int>& nums, int left, int right, int k){
        int pivot = nums[right];
        int l = left, r = right-1;
        while(l<=r){
            if(nums[r]>=pivot){
                swap(nums[l],nums[r]);
                l++;
            } else{
                r--;
            }
        }
        // cout<<r<<" "<<nums[r]<<endl;

        swap(nums[right],nums[l]);
        // for(int i=left;i<=right;i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0){
            return 0;
        }
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi){
            int index = partition(nums, lo, hi, k);
            // cout<<index<<endl;
            if(index==k-1){
                return nums[index];
            } else if(index>k-1){
                hi = index-1;
            } else {
                lo = index+1;
            }
        }
        return nums[lo];
    }
    
};

int main(int argc, char const *argv[])
{
	int test[] = {1,3,2,4,5,9,5};
	vector<int> nums(test, test+8);
	Solution slt;
	cout<<slt.findKthLargest(nums, 2)<<endl;
	return 0;
}