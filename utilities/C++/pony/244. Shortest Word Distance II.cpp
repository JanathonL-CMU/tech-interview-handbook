244. Shortest Word Distance II
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.



class WordDistance {
public:
    WordDistance(vector<string> words) {
        
    }
    
    int shortest(string word1, string word2) {
        
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
























class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i=0;i<words.size();i++)
            wordMap[words[i]].push_back(i);
    }
    int shortest(string word1, string word2) {
        int  i=0, j=0, dist = INT_MAX;
        while(i < wordMap[word1].size() && j <wordMap[word2].size()) { 
            dist = min(dist, abs(wordMap[word1][i] - wordMap[word2][j]));
            wordMap[word1][i]<wordMap[word2][j]?i++:j++;
        }
        return dist;
    }
private:
    unordered_map<string, vector<int>> wordMap;
};





class WordDistance {
  unordered_map<string, vector<int>>map;
public:
WordDistance(vector<string>& words) {
    
    for(int i=0; i < words.size(); i++)map[words[i]].push_back(i);
}

int shortest(string word1, string word2) {
    vector<int>w1=map[word1], w2=map[word2];
    int dist=INT_MAX;
    
    for(auto & index1 : w1)
        for(auto &index2 : w2){
            if(abs(index1- index2) < dist)dist=abs(index1-index2);
        }
    return dist;
}
};