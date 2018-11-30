// 269. Alien Dictionary
// Hard
// 563
// 108


// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

// Example 1:

// Input:
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]

// Output: "wertf"
// Example 2:

// Input:
// [
//   "z",
//   "x"
// ]

// Output: "zx"
// Example 3:

// Input:
// [
//   "z",
//   "x",
//   "z"
// ] 

// Output: "" 

// Explanation: The order is invalid, so return "".
// Note:

// You may assume all letters are in lowercase.
// You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
// If the order is invalid, return an empty string.
// There may be multiple valid order of letters, return any one of them is fine.
// Accepted
// 56,592
// Submissions
// 197,875

class Solution {
public:
    void constructGraph(unordered_map<char, unordered_set<char>>& graph, vector<int>& indegree, vector<string> words){
        //确保每个char都会在res中出现
        for(string word:words){
            for(char c:word){
                if(indegree[c-'a']==0){
                    indegree[c-'a'] = 1;
                }
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int len = min(word1.size(),word2.size());
            for(int j=0;j<len;j++){
                if(word1[j]!=word2[j] ){
                    // 判断不重边
                    if(!(graph.count(word1[j]) && graph[word1[j]].count(word2[j]))){
                        graph[word1[j]].insert(word2[j]);
                        indegree[word2[j]-'a']++;
                        char c = word2[j];
                    }
                    break;
                }
            }
        }
    }
    void topo_sort(unordered_map<char, unordered_set<char>>& graph, vector<int>& indegree, string& res){
        queue<char> que;
        int cnt = 0;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==1){
                char c = i+'a';
                que.push(c);
            }
            if(indegree[i]>0){
                cnt++;
            }
        }
        while(!que.empty()){
            char cur = que.front();
            que.pop();
            res.push_back(cur);
            for(char c:graph[cur]){
                indegree[c-'a']--;
                if(indegree[c-'a']==1){
                    que.push(c);
                }
            }
        }
        // 判断有环
        if(res.size()!=cnt){
            res = "";
        }
        
    }
    string alienOrder(vector<string>& words) {
        string res;
        if(words.size()==0){
            return res;
        }
        unordered_map<char, unordered_set<char>> graph;
        vector<int> indegree(26,0);
        // generator adjacency list
        constructGraph(graph, indegree, words);
        
        topo_sort(graph, indegree, res);
        return res;
    }
};
// class Solution {
// public:
//     string alienOrder(vector<string>& words) {
        
//         //generate adjacency list
//         vector<vector<bool>> adj(26, vector<bool>(26, false));
//         vector<bool> appear(26, false);
//         int n = words.size(), sn = 0;
//         bool flag;
//         if(n == 0)
//             return "";
//         for(int i = 0; i < n; i++){
//             flag = false;
//             sn = words[i].size();
//             for(int j = 0; j < sn; j++){
//                 appear[words[i][j] - 'a'] = true;
//                 if(i > 0 && j < words[i-1].size() && words[i][j] != words[i-1][j] && !flag){
//                     adj[words[i-1][j] - 'a'][words[i][j] - 'a'] = true;
//                     flag = true;
//                 }
//             }
//         }
//         stack<int> Stack;
//         vector<int> visited(26, 0); // 0 - unvisited, 1 - visiting, 2 - finished visiting
//         hasCycle = false;
        
//         //topological sort
//         topologicalSort(adj, Stack, visited, appear);
//         string res = "";
//         if(hasCycle)
//             return res;
//         while(!Stack.empty()){
//             res += (Stack.top() + 'a');
//             Stack.pop();
//         }
//         return res;
//     }
// private:
//     bool hasCycle;
//     void dfs(int i, vector<vector<bool>> &adj, stack<int> &Stack, vector<int> &visited){
//         visited[i] = 1;
//         for(int j = 0; j < 26; j++)
//             if(adj[i][j] == true){
//                 if (visited[j] == 0)
//                     dfs(j, adj, Stack, visited);
//                 else if(visited[j] == 1)
//                     hasCycle = true;
//             }
//         visited[i] = 2;
//         Stack.push(i);
//     }
    
//     void topologicalSort(vector<vector<bool>> &adj, stack<int> &Stack, vector<int> &visited, vector<bool> &appear){
//         bool hasCycle = false;
//         for(int i = 0; i < 26; i++)
//             if(appear[i] == true && visited[i] == 0)
//                 dfs(i, adj, Stack, visited);
//     }
// };