#include <iostream> 
#include <vector> 
#include <algorithm>
#include <map> 
#include <unordered_map> 
#include <unordered_set> 



class DynamicProgramming {
    public: 
        // O(n), use map for cache memoization, save fib sequence value using map, 
        int nth_fibonacci(const int n); 

        // O(n), use memoization, cache values in map, check how many steps for values 1 or 2 before, i.e. for 5 check 4 and 3 
        int climb_stairs(const int n); 

        // O(denom * coins), cache saves fewest # of denominations per coin value, for each coin value up to the target calculate the fewest coins needed by subtracting the denom and checking the fewest for that value 
        int coin_change(std::vector<int> &coins, int amount); 

        // O(1/2 * n^2) = O(n^2), save the LIS for each number, when we reach a number iterate backwards adding the LIS of numbers smaller than itself if the sum is greater than it's current LIS 
        int length_of_LIS(std::vector<int> &nums); 
}; 

/*
Blind 75 List 
Completed: 
- (Easy) Climbing Stairs 
- (Medium) Coin Change 

TODO: 
- Longest Increasing Subsequence
- Longest Common Subsequence
- Word Break Problem
- Combination Sum
- House Robber
- House Robber II
- Decode Ways
- Unique Paths
- Jump Game
*/