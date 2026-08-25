#include "algorithms/dynamic_programming.hpp" 



int DynamicProgramming::nth_fibonacci(const int n) {

    // Base case 
    if (n == 0) return 0; 
    if (n == 1 || n == 2) return 1; 

    // Memoization ! 
    std::unordered_map<int, int> nth_value_map; 
    nth_value_map[0] = 0; 
    nth_value_map[1] = 1; 
    nth_value_map[2] = 1; 

    for (int i = 3; i <= n; i++) {
        nth_value_map[i] = nth_value_map[i - 1] + nth_value_map[i - 2]; 
    } 

    return nth_value_map.at(n); 
}; 


int DynamicProgramming::climb_stairs(const int n) {

    /* 
    1, 1 base case 
    2, 11, 2
    3, 111, 12, 21 
    4, 1111, 112, 211, 121, 22, 

    memoization? 
    */

    std::unordered_map<int, int> possible_steps; 
    possible_steps[1] = 1; // Base case 
    possible_steps[2] = 2; 

    if (n > 2) {
        for (int i = 3; i <= n; i++) { 
            possible_steps[i] = possible_steps[i - 1] + possible_steps[i - 2]; 
        }
    }
    
    return possible_steps[n]; 
}; 


int DynamicProgramming::coin_change(std::vector<int> &coins, int amount) {
    /*
    3, 4 = 12 
    12 - 3, 12 - 4 = 9, 8 -> 3, 2 

    8 - 3, 8 - 4 = 5, 4 -> -1, 1 

    4 -> 1 
    */

    std::unordered_map<int, int> fewest_moves; 

    // Base case 
    for (auto denomination : coins) {
        fewest_moves[denomination] = 1; 
    }

    for (int value = 1; value <= amount; value++) { 
        if (fewest_moves.find(value) != fewest_moves.end()) continue; 

        int smallest = -1; 

        for (auto denomination : coins) { 
            int difference = value - denomination; 

            if (difference < 0) continue; 

            int current_smallest = fewest_moves[difference]; 

            if (current_smallest < 0) continue; 

            if (current_smallest < smallest || smallest < 0) smallest = current_smallest; 
        } 

        if (smallest >= 1) fewest_moves[value] = smallest + 1; 
        else fewest_moves[value] = smallest; 
    } 

    return fewest_moves[amount]; 
}; 


int DynamicProgramming::length_of_LIS(std::vector<int> &nums) { 
    /*
    Approaches: 
    - O(nlogn + n^2) = O(n^2), Sort the list first, then for each item in the list compare it's original index to the rest, increasing the length if the index is larger than the current smallest, nvm doesnt work ! 
    - ^ If we see a larger increasing sequence first and later a smaller but still increasing sequence, the smaller sequence will take over and we will miss the larger sequence from earlier 


    [10, 9, 2, 6, 7, 3, 4, 1, 5, 8, 11, 12, 0] = 2, 3, 4, 5, 8, 11, 12 

    [2, 6, 7, 3, 8, 9] = 2, 6, 7, 8, 9 // This disproves the first approach 
    [0, 3, 1, 2, 4, 5] 

    - O(1/2 * n^2), save the LIS for each number, when we reach a number iterate backwards adding the LIS of numbers smaller than itself if the sum is greater than it's current LIS 
    [0, 4, 5, 7, 2, 8, 9, 1, 2, 3, 6] = 0, 1, 2, 3, 6 
    [1, 2, 3, 4, 2, 5, 6] 

    [10, 9, 2, 6, 7, 3, 4, 1, 5, 8, 11, 12, 0] 
    [ 1, 1, 1, 2, 3, 2, 3, 1, 4, 5,  6,  7, 1] 
    */

    std::unordered_map<int, int> LIS; 
    int max_LIS = 1; 
    LIS[nums[0]] = 1; 

    for (int right = 1; right < static_cast<int>(nums.size()); right++) { 
        int current_LIS = 1; 
        int current_value = nums.at(right); 

        for (int left = right - 1; left >= 0; left--) { 
            int prev_value = nums.at(left); 
            if (prev_value < current_value) { 
                current_LIS = std::max(current_LIS, LIS[prev_value] + 1); 
            }
        }

        max_LIS = std::max(current_LIS, max_LIS); 
        LIS[current_value] = current_LIS; 
    }

    return max_LIS; 
}; 