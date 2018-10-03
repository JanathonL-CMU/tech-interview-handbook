//10. Regular Expression Matching
/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> mem(s.size()+1,vector<int>(p.size()+1,-1));
        return match(s,p, 0, 0,mem);   
    }
    bool match(string s, string p, int s1, int s2, vector<vector<int>>& mem){
        if(s1==s.size() && s2==p.size()) return true;
        else if(s2==p.size()) return false;
        if(mem[s1][s2]!=-1) return mem[s1][s2];
        bool res=false;
        if(p.size()>s2+1){
            if(p[s2+1]=='*'){
                res = res || match(s, p, s1, s2+2,mem);
                
                if(s1<s.size() && (s[s1]==p[s2]||p[s2]=='.')){
                    res = res || match(s,p,s1+1, s2, mem);
                }
            }  
        }
        if(s1<s.size() && (s[s1]==p[s2]||p[s2]=='.')){
            res = res || match(s, p, s1+1, s2+1,mem);
        }
        
        mem[s1][s2]= res;
        return res;
    }
};