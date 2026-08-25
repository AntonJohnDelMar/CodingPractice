#include <iostream> 
#include <string> 
#include <stack> 
#include <set> 
#include <queue> 
#include <algorithm> 
#include <map> 
#include <unordered_map> 
#include <unordered_set> 
#include <array> 
#include <cctype> 



class String { 
    public: 
        // O(n), push chars into stack, see if stack equals original string 
        // O(n), better to use two pointer, if pointers ever differ then not a palindrome, we do not count non alphanumeric chars so skip those, we also don't count capitols as different 
        bool check_palindrome(const std::string string); 

        // O(n + k), k is backtrack, use set to track unique chars, once we see a dup char we delete chars until we hit the original dup, keep track of the longest length as we go 
        int length_of_longest_substring(std::string s); 

        // O(26n), sliding window technique, a valid window is one where the length - most frequent char is <= k, if invalid move the left pointer, 
        int character_replacement(std::string s, int k); 

        // O(n + k) = O(n), create map of char and their frequency, if two maps are the same it is anagram 
        // O(nlogn + klogn), check if two sorted strings are same 
        bool is_anagram(std::string s, std::string t); 

        // O(m * n) use an array to count frequencies of char using ASCII values, then we can use the frequency "map" as they key for fast lookup 
        std::vector<std::vector<std::string>> group_anagrams(std::vector<std::string> &strs); 

        //
        bool valid_parentheses(std::string &s); 
}; 

/*
Completed: 
- (Medium) Longest Substring Without Repeating Characters
- (Medium) Longest Repeating Character Replacement
- (Easy) Valid Anagram 
- (Medium) Group Anagrams 
- (Easy) Valid Palindrome 
- (Easy) Valid Parentheses 

TODO: 
- Minimum Window Substring
- Longest Palindromic Substring
- Palindromic Substrings
- Encode and Decode Strings (Leetcode Premium)
*/