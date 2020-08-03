/*
 * Laurie Kirk 8-2-20
 * Finding the longest substring with no repeating characters
 * Time complexity: O(n^2), n = s.length()
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Hash table for holding the characters of the substring for each iteration
        std::unordered_set<char> substring;
        
        int longest_length = 1; // If the string isn't empty, it will always be at least 1
        int current_length = 1;
        int start_index = 0; // The index where the substring will start
        int current_index = start_index + 1; // Current index of character being checked
        
        // Account for empty string
        if (s.compare("") == 0)
            return 0;
        
        substring.insert(s[start_index]); // Our first letter
        
        // Test all relevant substrings
        while (start_index < s.length())
        {            
            // Check if this character has been seen before and is at a valid index
            if (current_index < s.length() && substring.find(s[current_index]) == substring.end())
            {
                substring.insert(s[current_index]);
                current_length++;
                current_index++;
            }
            else
            {
                // Find index of the next unique character from the last starting index
                start_index = next_unique_index(s, start_index);
                
                // See if this size is greater
                if (current_length > longest_length)
                    longest_length = current_length;
                
                // Reset for next iteration
                current_length = 1;
                current_index = start_index + 1;
                substring.clear();
                if (start_index < s.length())
                    substring.insert(s[start_index]);
            }                        
        }
        
        return longest_length;
    }
    
    /*
     If there are more than two of the same letter in a row, returns the index of the last occurrence
     */
    int next_unique_index(std::string s, int start_index)
    {
        // Declared outside loop so we can return it
        int i;
        
        for (i = start_index + 1; i < s.length(); ++i)
        {
            // Return either the next unique char or the last one of a sequence of the same
            if (s[i] != s[start_index] || (i+1 < s.length() && s[i] != s[i+1]))
                return i;
        }
        
        // There was no unique index
        return i;
    }
};
