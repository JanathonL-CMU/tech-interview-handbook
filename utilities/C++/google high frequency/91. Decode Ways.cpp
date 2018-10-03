// 91. Decode Ways
class Solution {
public:
    
    int numDecodings(string s) {
        vector<int> dp(s.size(),0);
        if(s.size()==0) return 0;
        dp[s.size()] = 1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i] = 0;
            }
            else if(i+1<s.size() && s.substr(i,2)<="26"){
                dp[i] = dp[i+1]+dp[i+2];
            }
            else{
                dp[i] = dp[i+1];
            }
        }
        return dp[0];
    }
    
};