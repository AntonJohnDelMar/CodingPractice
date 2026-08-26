#include "algorithms/arrays.hpp" 



std::vector<int> Array::get_concatenation(std::vector<int> &nums) { 
    std::vector<int> temp = nums; 

    for(auto itr = nums.begin(); itr != nums.end(); ++itr) {
        temp.push_back(*itr); 
    } 

    return temp; 
}; 


std::vector<int> Array::shuffle(std::vector<int> &nums) { 
    int n = nums.size() % 2; 

    for (int i = 0; i < 2 * n; i++) {
        if (i % 2) {
            nums.insert(nums.begin() + i, nums.at(i + n - 1)); 
        }
    }

    nums.erase(nums.begin() + 2 * n, nums.end()); 
    
    return nums; 
}; 


int Array::find_max_consecutive_ones(std::vector<int> &nums) { 
    int max = 0; 
    int count = 0; 

    // 0 0 1 1 0 0 0 1 1 1 1 
    for (auto &curr : nums) {
        if (curr == 1) count++; 
        else count = 0; 

        max = std::max(max, count); 
    }; 

    return max; 
}; 


std::vector<int> Array::find_error_nums(std::vector<int> &nums) { 
    /* 
    Approaches: 
    - O(2n), use a set to find duplicate number, iterate through again to find the missing number, requires two passes 
    - O(n), iterate through vector, keep track of natural sum to n as well as sum of vector and track duplicate, in the end we know we can subtract the duplicate and the missing number will add to that to match the natural sum of n 

    [4, 5, 3, 1, 1] return [1, 2]  
    [2, 2] return [2, 1] 
    [1, 2, 2] return [2, 3] 
    [1, 1] return [1, 2] 
    [4, 1, 3, 4] 
    12 
    10 
    return [duplicate, missing] 
    */

    std::unordered_set<int> seen; 
    int duplicate = -1; 

    int natural_sum = 0; 
    int vector_sum = 0; 
    for (int i = 0; i < nums.size(); i++) { 
        int current_num = nums[i]; 
        if (seen.contains(current_num)) duplicate = current_num; 
        seen.insert(current_num); 

        vector_sum += current_num; 
        natural_sum += (i + 1); 
    }

    return {duplicate, natural_sum - (vector_sum - duplicate)}; 
}; 

/*
    std::unordered_set<int> seen;  
    std::vector<int> result; 
    int duplicate = -1; 

    for (auto &num : nums) {
        if (seen.contains(num)) duplicate = num; 
        seen.insert(num); 
    } 

    for (int i = 1; i < static_cast<int>(nums.size()) + 1; i++) {
        if (!seen.contains(i)) return {duplicate, i}; 
    }

    return {-1, -1}; 
*/


int Array::second_largest(std::vector<int> &nums) {
    /*
    naive approach - iterate twice, find largest value, then iterate again for the second largest 
    - O(2n) complexity, terrible scalablity, 
    - O(n), Iterate once, as we find largest value, assign second largest, iterate list of length n, 
    */
    int largest = -1; 
    int second_largest = -1; 

    for (auto &curr_num : nums) {
        if (curr_num >= largest) { 
            second_largest = largest; 
            largest = curr_num; 
        }; 

        if (curr_num > second_largest && curr_num < largest) { 
            second_largest = curr_num; 
        }; 
    }; 

    return second_largest; 
}; 


std::tuple<int, int> Array::two_sum(const int target, std::vector<int> &nums) {  
    std::map<int, int> values; 

        for (int i = 0; i <= static_cast<int>(nums.size()); i++) { 
            int curr = nums.at(i); 
            int difference = target - curr; 

            if (auto find = values.find(difference); find != values.end()) { 
                return {i, values[difference]}; 
            }

            values.insert({curr, i}); 
        }

        return {-1, -1}; 

    // Two pointer approach
    /* 
    std::sort(nums.begin(), nums.end()); 

    auto start = nums.begin(); 
    auto end = nums.end() - 1; 

    int sum = 0; 

    while (start != end) {
        int small = *start; int large = *end; 
        std::tuple<int, int> pair {small, large}; 
        sum = small + large; 

        if (sum == target) {
            return pair; 
        } 

        if (sum < target) {
            start++; 
        }

        if (sum > target) {
            end--; 
        }
    }

    return {0, 0}; 
    */
}; 


int Array::max_profit(std::vector<int> &prices) { 
    // [7, 1, 5, 3, 6, 4, 0, 2, 4, 6], output 5, buy when it is 1 sell when it is 6, 
    // Track smallest value, track max profit 
    // 1 5 
    // 0 6 

    int smallest = 1e6; 
    int profit = 0; 

    for (int i = 0; i < static_cast<int>(prices.size()); i++) { 
        int curr = prices.at(i); 
        int curr_profit = curr - smallest; 

        if (curr < smallest) {
            smallest = curr; 
            continue; 
        }

        if (curr_profit > profit) {
            profit = curr_profit; 
            continue; 
        }

    }

    return profit; 
}; 


bool Array::contains_duplicate(std::vector<int> &nums) { 
    std::unordered_set<int> seen; 

    for (int i = 0; i < static_cast<int>(nums.size()); i++) { 
        int curr_num = nums.at(i); 

        if (seen.count(curr_num) > 0) return true; 

        seen.insert(curr_num); 
    } 

    return false; 
}; 


std::vector<int> Array::product_except_self(std::vector<int> &nums) { 
    /*
    O(n + n) = O(2n), return array where each element is product of the other elements except itself, no division! 
    Find prefix and postfix products, then multiply the prefix and post fix for each element 
    [1, 2, 3, 4] = [24, 12, 8, 6] 
    */
    std::vector<int> result; 

    int prefix = 1; 
    for (int i = 0; i < static_cast<int>(nums.size()); i++) { 
        result.push_back(prefix); 
        prefix *= nums.at(i); 
    }

    // [1, 1, 2, 6] 
    int postfix = 1; 
    for (int j = static_cast<int>(nums.size()) - 1; j >= 0; j--) {
        result.at(j) *= postfix; 
        postfix *= nums.at(j); 
    }

    return result; 
}; 


int Array::max_sub_array(std::vector<int> &nums) { 
    if (nums.size() == 1) return nums.at(0); 
    /*
    Approaches: 
    - naive solution: O(n^2) find sum of subarrays of each size, i.e. n, n - 1, n - 2 until 1 
    - O(~1/2 * n^2), keep track of cummulative sum, and subtract and add elements as needed as we come across each window size 
    - O(n) solution: use sliding window like, move right and only move left if prefix is negative, track largest sub array 

    [1, -2, 3, -4, 5] 
    [-2, 1, -3, 4, -1, 2, 1, -5, 4] 
    [-2, -1, -4] 
    */ 

    int max_sum = -1e4; 
    int sum = 0; 

    for (int right = 0; right < static_cast<int>(nums.size()); right++) { 
        int curr_num = nums.at(right); 

        sum += curr_num; 

        max_sum = std::max(max_sum, sum); 

        if (sum < 0) {
            sum = 0; 
        }

    }

    return max_sum; 
}; 


int Array::max_product(std::vector<int> &nums) { 
    /*
    Approaches: 
    - Track product of window, if it is <= 0 reset window, doesn't work in the case we have multiple (-) in a row 
    - Window, move right as far as we can (stop if it is 0 or the end) taking product along the way, then we move the left and divide out the numbers as we go 

    [-2, 0, -1] 
    [3, -1, 4] 
    [-1, -2, -3, 0] 
    [2, -5, -2, -4, 3] 
    [-1, -2, -3] 
    */
    if (nums.size() == 1) return nums[0]; 

    int max_product = 1e-4; 
    int window_product = 1; 

    int left = 0; 
    int right = 0; 

    auto shift_left_to_right = [&]() { 
        while (left < right - 1) { 
            window_product /= nums[left]; 
            left++; 
            max_product = std::max(max_product, window_product); 
        } 

        if (left == right) left++; 
        else left += 2; // Skip index with zero term 
        window_product = 1; 
    }; 

    for (right = 0; right < nums.size(); right++) { 
        int right_num = nums[right]; 

        int current_product = window_product * right_num; 
        max_product = std::max(max_product, current_product); 

        if (current_product == 0) {
            shift_left_to_right(); 
        } 

        else {
            window_product = current_product; 
        }
    }

    shift_left_to_right(); 

    return max_product; 
}; 


int missing_multiple(std::vector<int>& nums, int k) {
    /*
    Approaches: 
    - O(n + mlogm) = O(mlogm), if modulo is 0 then it is a multiple, we can calculate multiple by dividing, save the multiples in a sorted vector then iterate and find the smallest missing one 

    10, 6, 7, 9, 2, 3, 8, k = 2 
    5, 3, n, n, 1, n, 4 
    */ 

    std::set<int> seen_multiples; 
    for (auto &number : nums) { 
        if (number % k == 0) seen_multiples.insert(number / k); 
    }

    for (int i = 0; i < seen_multiples.size(); i++) { 
        if (!seen_multiples.contains(i + 1)) return k * (i + 1); 
    } 

    return k * (seen_multiples.size() + 1); // return nth + 1 multiple, i.e. we had 2, 4, 6, 8 so return 10 
}; 