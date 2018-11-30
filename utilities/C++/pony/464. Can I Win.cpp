464. Can I Win



In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
         if(desiredTotal==0){
             return true;
         }
        // 这个判断要加
        if(desiredTotal > maxChoosableInteger*(maxChoosableInteger+1)/2) return false;
        int visited = 0;
        unordered_map<int,bool> mem;
        return dfs(maxChoosableInteger, desiredTotal, visited, mem);
    }

    // 有个trick就是一旦知道我取了什么，就可以知道我target减少了多少，所以状态只需要用visited进行记录就好了
    bool dfs(int range, int target, int visited, unordered_map<int,bool>& mem){
        if(target<=0){
            return false;
        }
        if(mem.count(visited)){
            return mem[visited];
        }
        for(int i=1;i<=range;i++){
            int mask = 1<<i;
            if(visited&mask) continue;
            if(!dfs(range, target-i, visited | mask, mem)){
                mem[visited] = true;
                return true;
            }
        }
        mem[visited] = false;
        return false;
    }
};