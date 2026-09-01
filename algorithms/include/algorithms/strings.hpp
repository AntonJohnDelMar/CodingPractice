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
#include <sstream> 



class String { 
    public: 
        // O(n), push chars into stack, see if stack equals original string 
        // O(n), better to use two pointer, if pointers ever differ then not a palindrome, we do not count non alphanumeric chars so skip those, we also don't count capitols as different 
        bool check_palindrome(const std::string string); 

        // O(n + k) = O(n), k is backtrack, use set to track unique chars, once we see a dup char we delete chars until we hit the original dup, keep track of the longest length as we go 
        int length_of_longest_substring(std::string s); 

        // O(26n) = O(n), sliding window technique, a valid window is one where the length - most frequent char is <= k, if invalid move the left pointer, 
        int character_replacement(std::string s, int k); 

        // O(n + k) = O(n), create map of char and their frequency, if two maps are the same it is anagram 
        // O(nlogn + klogn) = O(nlogn), check if two sorted strings are same 
        bool is_anagram(std::string s, std::string t); 

        // O(m * n) use an array to count frequencies of char using ASCII values, then we can use the frequency "map" as they key for fast lookup 
        std::vector<std::vector<std::string>> group_anagrams(std::vector<std::string> &strs); 

        // O(n), use stack, just check for matching close and end or new open, if that fails the parentheses is invalid 
        bool valid_parentheses(std::string &s); 

        // O(n), convert to string and validate palindrome with two pointer method, 
        // reverse integer method, issues if x is too large and causes overflow when trying to represent 
        bool is_palindrome_number(int x); 

        // O(n), iterate through string, count the length of words as we go along, do not count if it is a space and restart on the next word, 
        int length_of_last_word(std::string s); 

        // O(n * m), go by index and check if each str has the same char at the current idx, worst case n is len of lcp and m is number of strs 
        std::string longest_common_prefix(std::vector<std::string>& strs); 

        // O(n), use a map to store character to value, itr through string and add symbol values, check for the six subtraction cases by looking at the next symbol if necessary 
        int roman_to_int(std::string s); 

        // O(n + m), KMP algorithm 
        int needle_in_haystack(std::string haystack, std::string needle); 

        // O(n), just do binary addition tracking carries, save output into deque to push front, convert deque to string in the end 
        std::string add_binary(std::string a, std::string b); 

        // O(n), XOR each element, the element that remains is the single, this is because A^A = 0 whereas A^B^A = B, 
        int single_number(std::vector<int> &nums); 
}; 

/* 
Blind 75 List 
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