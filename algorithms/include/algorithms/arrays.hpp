#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <map> 
#include <set>
#include <unordered_set> 
#include <unordered_map> 



class Array {
    public: 
        // O(n), clone collection and append it's own items to itself, iterate through list of length n 
        std::vector<int> get_concatenation(std::vector<int> &nums); 

        // O(n), place items from second half between items in first half, 2 * n operations 
        std::vector<int> shuffle(std::vector<int> &nums); 

        // O(n), iterate once, keep track of longest sequence, iterate list length n 
        int find_max_consecutive_ones(std::vector<int> &nums); 

        // O(2n) = O(n), Use set to find duplicate, iterate through and check which number is missing from set, n + n operations 
        // O(n), iterate through vector, keep track of natural sum to n as well as sum of vector and track duplicate, in the end we know we can subtract the duplicate and the missing number will add to that to match the natural sum of n 
        std::vector<int> find_error_nums(std::vector<int> &nums); 

        // O(n), Iterate once, as we find largest value, assign second largest, iterate list of length n, 
        int second_largest(std::vector<int> &nums); 

        // O(n), Sort and use two pointers, moving respective pointers if the sum is too big or small, iterate through 
        // O(n), Use set to save seen values, check if target - current exists already, iterate through 
        std::tuple<int, int> two_sum(const int target, std::vector<int> &nums); 

        // O(n) iterate through keep track of largest profit, save smallest and check profit, if we find smaller restart 
        int max_profit(std::vector<int> &prices); 

        // O(n), iterate through and use separate unordered set to track duplicates, unordred saves time! 
        bool contains_duplicate(std::vector<int> &nums); 

        // O(2n) = O(n), find prefix and postfix products, then multiply the prefix and post fix for each element 
        std::vector<int> product_except_self(std::vector<int> &nums); 

        // O(n), sliding window, move left pointer if the current sum is negative and start over again from the right, 
        int max_sub_array(std::vector<int> &nums); 

        // O(2n) = O(n), worst case we have to check every element twice, we use a window taking product of items, if we hit a zero shrink window keeping track of remaining product after dividing out terms, move past zero repeat, shrink again at the end 
        int max_product(std::vector<int> &nums); 

        // 
        int missing_multiple(std::vector<int>& nums, int k); 
}; 

/*
Blind 75 List 
Completed: 
- (Easy) Two Sum 
- (Easy) Best Time to Buy and Sell Stock 
- (Easy) Contains Duplicate 
- (Medium) Product of Array Except Self
- (Medium) Maximum Subarray 

TODO: 
- Maximum Product Subarray
- Find Minimum in Rotated Sorted Array
- Search in Rotated Sorted Array
- 3 Sum
- Container With Most Water
*/