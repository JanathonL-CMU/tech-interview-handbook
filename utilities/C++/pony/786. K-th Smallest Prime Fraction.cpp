786. K-th Smallest Prime Fraction


786. K-th Smallest Prime Fraction
Hard
150
9

A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]
Note:

A will have length between 2 and 2000.
Each A[i] will be between 1 and 30000.
K will be between 1 and A.length * (A.length - 1) / 2.
// Time Complexity: O(KlogN),
//
class Solution {
public:
    /*
    [n1,n2,n3,n4]
    {n1/n4}, {n1/n3}, {n1/n2}, {n1/n1}
    {n2/n4}, {n2/n3}, {n2/n2}
    */
    class Comparator{
    public:
        bool operator()(pair<double, pair<int,int>> a, pair<double, pair<int,int>> b){
            return a.first >= b.first;
        }  
    };
    // min heap
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        priority_queue<pair<double, pair<int,int>>, vector< pair<double, pair<int,int>> >, Comparator> pq;
        int n = A.size();
        for(int i=0;i<n;i++){
            pq.push({A[i]*1.0/A[n-1], {i, n-1}});
        }
        while(--K>0){
            auto cur = pq.top();
            pq.pop();
            int tail = cur.second.second;
            int front = cur.second.first;
            tail--;
            pq.push({A[front]*1.0/A[tail], {front, tail}});
        }
        int front = pq.top().second.first;
        int tail = pq.top().second.second;
        return {A[front], A[tail]};
    }
};

// O(NlogW) where N is the length of primes, and W is the width (in quantized units) 
// of our binary search, (hi - lo) / 1e-9 which is 10^9

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double lo = 0;
        double hi = 1;
        vector<int> ans = {0,1};
        while(hi-lo > 1e-9){          // this is very important
            double mid = lo + (hi-lo)/2.0;
            vector<int> res = under(mid, A);
            if(res[0] < K){
                lo = mid;
            } else {
                ans[0] = res[1];
                ans[1] = res[2];
                hi = mid;
            }
        }
        return ans;
    }
    vector<int> under(double x, vector<int> primes){   // make sure x is double 
        int cnt = 0;
        int num = 0;    // make sure num/denom = 0, which is the smallest
        int denom = 1;
        for(int i=0;i<primes.size();i++){
            int j = -1;
            while(primes[j+1] <= primes[i] * x) j++;
            cnt += j+1;
            if(j>=0 && num * primes[i] < denom * primes[j]){
                num = primes[j];
                denom = primes[i];
            }
        }
        return {cnt, num, denom};
    }
};