// 243. Shortest Word Distance
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Input: word1 = “coding”, word2 = “practice”
// Output: 3
// Input: word1 = "makes", word2 = "coding"
// Output: 1
// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int last_for_word_1 = -1;
        int last_for_word_2 = -1;
        int res = INT_MAX;
        for (int i = 0; i < words.size(); ++i)
        {
        	if (words[i]==word1)
        	{
        		if (last_for_word_2!=-1)
    			{
    				res = min(res, i-last_for_word_2);
    			}	
        		last_for_word_1 = i;
        	} else if (words[i]==word2){
        		if (last_for_word_1!=-1)
        		{
        			res = min(res, i-last_for_word_1);
        		}
        		last_for_word_2 = i;
        	}
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{	
	string w[] = {"practice", "makes", "perfect", "coding", "makes"};
	vector<string> words(w, w+5);
	Solution slt;
	cout<<slt.shortestWordDistance(words, "makes", "perfect")<<endl;
	return 0;
}