#include <vector>

class Solution {
private:
    int countWays(int n, std::vector<int>& memo){
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(memo[n]!=-1){
            return memo[n];
        }
        return memo[n] = countWays(n-1, memo) + countWays(n-2, memo);
    }
public:
    int climbStairs(int n) {
        std::vector<int> memo(n+1,-1);
        return countWays(n,memo);
    }
};
