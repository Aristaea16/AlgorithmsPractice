/*
 * Laurie Kirk 8-15-20
 * Checks whether a given string is a palindrome. Counts only letters or digits
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

class Solution {
public:
    bool isPalindrome(string s) {
        // Indices of far left and right of the string
        int left = 0;
        int right = s.size() - 1;
        
        // Account for empty string
        if (s.compare("") == 0)
            return true;
        
        while (left < s.size() && right >= 0 && left < right)
        {
            // Skip non-alphanumeric characters
            while (left < s.size() && !isalpha(s[left]) && !isdigit(s[left]))
                left++;
            while (right >= 0 && !isalpha(s[right]) && !isdigit(s[right]))
                right--;
            
            // Now check if they are equal not counting case
            if (left >= right) // The string contained no digits or letters
                return true;
            else if (tolower(s[left]) != towlower(s[right]))
                return false;
            
            // Next indices
            left++;
            right--;
        }
        
        // We have gone through the whole strin gso it was a palindrome
        return true;
    }
};
