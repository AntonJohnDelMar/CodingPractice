#include "algorithms/strings.hpp" 



bool String::check_palindrome(const std::string str) { 
    /*
    Approaches: 
    - O(n/2), two pointer method, move right/left pointer if not alpha numeric effectively getting rid of those chars, then check if the char at left and right are the same regardless of capitalization also, 

    "A man, a plan, a canal: Panama"

    */
    if (str == "") return true; 

    int left = str.size() - 1; 
    for (int right = 0; right < left; right++) { 
        char right_char = str[right]; 
        char left_char = str[left]; 

        while (std::isalnum(right_char) == 0) { 
            ++right;
            if (right > str.size() - 1) break; 
            right_char = str[right]; 
        }

        while (std::isalnum(left_char) == 0) { 
            --left; 
            if (left < 0) break; 
            left_char = str[left]; 
        }

        if (right >= left) break; 

        if (std::tolower(right_char) != std::towlower(left_char)) return false; 
        --left; 
    }

    return true; 
}; 


int String::length_of_longest_substring(std::string s) {
    /*
    Approach: unordered set to track unique characters, once we reach duplicate check curr_len > max_len then delete everything before the duplicate character 

    abcadb cebb = adbce 5
    
    current 5
    max 5 
    */

    std::set<char> unique_chars; 
    std::queue<char> curr_substr; 
    int max_len = 0; 
    int curr_len = 0;   

    for (auto _char : s) {
        auto found = unique_chars.find(_char); 

        if (found == unique_chars.end()) { 
            unique_chars.insert(_char); 
            curr_substr.push(_char); 
            curr_len++; 

            max_len = std::max(max_len, curr_len); 
        } 

        else { 
            char dup_char = *found; 
            char substr_char = curr_substr.front(); 

            while (substr_char != dup_char) { 
                curr_len--; 
                curr_substr.pop(); 
                unique_chars.erase(substr_char); 

                substr_char = curr_substr.front(); 
            } 

            curr_substr.pop(); 
            curr_substr.push(dup_char); 
        }
    }

    return max_len; 
}; 


int String::character_replacement(std::string s, int k) {
    if (s.size() == 0) return 0; 
    /*
    Approach: 
    - O(n + k) k backtracking, track current longest substring, remember first skip, iterate until out of skips, sliding window was the right idea! 
    - O(n), we have a sliding window and we check if the window is valid, a window is valid if we have enough skips to create the most frequent character in the window, 

    ABCDE, k = 1 
    ABBB, k = 2 
    CCCCBAAABBA, k = 2 
    BAAABBAB, k = 2
    AABAB BA, k = 1 
    */

    int max_len = 0; 
    int window_len = 0; 

    std::map<char, int> frequencies; 
    int max_freq = 0; 

    int left = 0; 
    for (int right = 0; right < static_cast<int>(s.size()); right++) { 
        char curr_char = s[right]; 

        if (frequencies.find(curr_char) == frequencies.end()) frequencies[curr_char] = 1; 
        else ++frequencies[curr_char]; 

        max_freq = std::max(max_freq, frequencies[curr_char]); 

        window_len = right - left + 1; 

        if (window_len - max_freq <= k) { 
            max_len = std::max(max_len, window_len); 
            continue; 
        }

        else {
            while (window_len - max_freq > k) {
                --frequencies[s[left]]; 
                ++left; 
                window_len = right - left + 1; 
            }
        }
    }

    return max_len; 
}; 


bool String::is_anagram(std::string s, std::string t) { 
    if (s.size() != t.size()) return false; 
    /*
    Approach:  
    - O(n + k), We need the same characters and the same amount, create two maps and compare them 
    - O(nlogn + klogk), We sort both strings and compare, 

    BAC -> ABC
    CAB -> ABC
    */ 

    std::unordered_map<char, int> s_count; 
    std::unordered_map<char, int> t_count; 

    for (int i = 0; i < static_cast<int>(s.size()); i++) { 
        s_count[s[i]]++; 
        t_count[t[i]]++; 
    }

    return s_count == t_count; 
}; 


std::vector<std::vector<std::string>> String::group_anagrams(std::vector<std::string> &strs) { 
    /* 
    Approaches: 
    - O(longest string), use hashmap to count char frequencies, convert each word into their hashmap, use dictionary with index as key and the frequency map as the value, as we check the words add it to the respective index in the output if there is a match or make a new entry 
    - O(m * n) use an array to count frequencies of char using ASCII values, then we can use the frequency "map" as they key for fast lookup 

    ["eat","tea","tan","ate","nat","bat"] 
    0 -> a = 1, e = 1, t = 1 
    1 -> a = 1, n = 1, t = 1 
    2 -> a = 1, b = 1, t = 1 
    [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]] 
    */
    if (strs.size() == 0) return {}; 

    std::unordered_map<std::string, std::vector<std::string>> anagram_groups; 

    for (auto &string : strs) { 
        std::array<int, 26> char_counts{}; 

        for (auto &_char : string) {
            char_counts[_char - 'a']++; 
        }

        std::string key = ""; 
        for (auto &count : char_counts) {
            key += std::to_string(count) + "#"; 
        } 

        anagram_groups[key].push_back(string); 
    }

    std::vector<std::vector<std::string>> result; 
    for (auto &anagram : anagram_groups) {
        result.push_back(anagram.second); 
    }

    return result; 
}; 


bool String::valid_parentheses(std::string &s) { 
    /*
    Approaches: 
    - O(n), use a stack, when we see an open add it to the stack, pop from the stack the closed brackets, order is preserved naturally, 

    */

    std::unordered_map<char, char> close_open_pairs { {')', '('}, {'}', '{'}, {']', '['} }; 
    std::stack<char> parentheses; 

    for (auto &_char : s) { 
        if (!close_open_pairs.contains(_char)) parentheses.push(_char); 

        else if (!parentheses.empty() && parentheses.top() == close_open_pairs[_char]) parentheses.pop(); 

        else return false; 
    }

    return parentheses.empty(); 
}; 


bool String::is_palindrome_number(int x) {
    /*
    Approaches: 
    - O(n), convert to string and check palindrome  
    */
    std::string num_str = std::to_string(x); 

    int right = 0; 
    int left = num_str.size() - 1; 

    while(right <= left) { 
        if (num_str[right] != num_str[left]) return false; 
        right++; 
        left--; 
    }

    return true; 

/*
    // Math approach, reverse number, problem with overflow if x is too large though ? 
    if (x < 0) return false; 

    int in = x; 
    int out = 0; 
    while(in) {
        out = (out * 10) + (x % 10); 
        in /= 10; 
    }

    return (out == x); 
*/
}; 


int String::length_of_last_word(std::string s) {
    int length = 0; 

    bool counting = false; 

    for (auto &c : s) { 
        if (c != ' ') { 
            if (!counting) {
                counting = true; 
                length = 1; 
            }
            
            else length++; 
        }

        else {
            counting = false; 
        }
    } 

    return length; 
    /* 
    std::stringstream sstream(s); 

    std::string last_word = ""; 

    while (sstream >> last_word); 

    return last_word.length(); 
    */
}; 


std::string String::longest_common_prefix(std::vector<std::string>& strs) { 
    /*
    Approaches: 
    - O(n * m), go by index and check if each str has the same char at the current idx, worst case n is len of lcp and m is number of strs 
    */

    std::string lcp = ""; 

    int max_str_len = 200; 
    for (int i = 0; i < max_str_len; i++) { 

        char common_char = strs[0][i]; 
        bool is_common = true; 
        for (auto &str : strs) {
            char curr_char = str[i]; 

            if (curr_char != common_char || curr_char == '\0') { 
                is_common = false; 
                break; 
            }
        }

        if (is_common) lcp += common_char; 
        else break; 
    }

    return lcp; 
}; 


int String::roman_to_int(std::string s) { 
    /*
    Approaches: 
    - O(n), use a map to store character to value, itr through string and add symbol values, check for the six subtraction cases by looking at the next symbol if necessary 
    - O(n), use switch statement, add symbol values to total, check special subtraction cases, uses less space than map method 

    */

    std::unordered_map<char, int> symbol_value { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} }; 

    int roman_numeral = 0; 
    for (int i = 0; i < s.size() - 1; i++) { 
        if (symbol_value[s[i]] < symbol_value[s[i + 1]]) roman_numeral -= symbol_value[s[i]]; 
        else roman_numeral += symbol_value[s[i]]; 
    }

    return roman_numeral + symbol_value[s[s.size() - 1]]; 
    /* 
        switch (current_char) {
            case ('I'): 
                if (i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X')) roman_numeral -= 1; 
                else roman_numeral += 1; 
                break; 

            case('V'): 
                roman_numeral += 5; 
                break; 

            case('X'): 
                if (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C')) roman_numeral -= 10; 
                else roman_numeral += 10; 
                break; 

            case('L'): 
                roman_numeral += 50; 
                break; 

            case('C'): 
                if (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M')) roman_numeral -= 100; 
                else roman_numeral += 100; 
                break; 
           
            case('D'): 
                roman_numeral += 500; 
                break; 

            case('M'): 
                roman_numeral += 1000; 
                break; 
        }
    */
}; 


int String::needle_in_haystack(std::string haystack, std::string needle) { 
    /*
    Approaches: 
    -  O(n), itr through haystack, when a char matches needle continue itr and check if the following letters match needle, breaks in the case there is overlap like in "mississippi" "issip" 
    - O(n * m), naive solution, for each char of haystack check if it the following substring matches needle 
    - O(n + m), KMP algorithm 
    
    haystack = "leelleetcode", needle = "leet" 

    "mississippi" "issip" 
    "mississippi" "issipi" 
    */
    if (haystack.size() < needle.size()) return -1; 
    if (needle == "") return 0; 

    auto generate_LPS = [&]() {
        std::vector<int> LPS(needle.size()); 
        
        LPS[0] = 0; 
        int prev_LPS = 0; int i = 1; 
        
        while (i < needle.size()) {
            if (needle[i] == needle[prev_LPS]) {
                LPS[i] = prev_LPS + 1; 
                i++; 
                prev_LPS++; 
            }

            else if (prev_LPS == 0) {
                LPS[i] = 0; 
                i++; 
            }

            else prev_LPS = LPS[prev_LPS - 1]; 
        }

        return LPS; 
    }; 

    auto LPS = generate_LPS(); 

    int i = 0; int j = 0; 
    while (i < haystack.size()) {
        if (haystack[i] == needle[j]) { 
            i++; j++; 
        }

        else {
            if (j == 0) i++; 
            else j = LPS[j - 1]; 
        }

        if (j == needle.size()) return i - needle.size(); 
    }

    return -1; 
}; 