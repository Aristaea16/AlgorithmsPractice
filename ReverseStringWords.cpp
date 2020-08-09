/*
 * Laurie Kirk 8-9-20
 * Reversing the words in a string
 * Space comlexity: O(1)
 * Time complexity: O(n) where n is the number of characters in the input string
 */

class Solution {
public:
    string reverseWords(string s) {
        int left_index = 0; // Front of the string
        int right_index = s.size() - 1; // Back of the string
        int temp_index = -1;
        int last_word = false;
        
        // Account for the empty string or only whitespace
        if (s.compare("") == 0 || s.find_first_not_of(' ') == std::string::npos)
            return "";
        
        // Keep reversing until we reach the word that was first
        while (!last_word)
        {
            // Find next word removing any whitespace
            while (std::isspace(s[right_index]) || std::isspace(s[left_index]))
            {
                if (std::isspace(s[right_index]))
                {
                    s.erase(s.begin() + right_index); 
                    --right_index;
                }
                if (std::isspace(s[left_index]))
                {
                    s.erase(s.begin() + left_index);
                    
                    // Account for shift
                    --right_index;
                }
            }
            
            // Now we should be at the next word so we find its beginning
            temp_index = right_index;
            while (temp_index - 1 >= 0 && !std::isspace(s[temp_index-1]))
                --temp_index;
            
            // If we haven't reached the first word which should now be in its correct place
            if (temp_index - 1 >= 0 && temp_index > left_index)
            {
                // Copy word to the left index and remove the right one
                s.insert(left_index, s.substr(temp_index, right_index - temp_index + 1) + " ");
                // Account for the extra letters at the beginning
                s.erase(s.begin() + temp_index + (right_index - temp_index + 1), s.end());
                
                // Set the left index to the next location to insert at
                // Note: +2 because we are accounting for the extra space
                left_index += right_index - temp_index + 2;
            } else
            {
                // Set our loop breaking flag
                last_word = true;
            }
            
        }
        
        return s;
    }
};
