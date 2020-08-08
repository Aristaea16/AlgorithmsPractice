/*
 * Laurie Kirk 8-8-20
 * Finding all possible letter combinations of a Phone Number
 * Time complexity: O(n^2) where n is the number of possible letters for each digit
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Define the possible characters for each number
        // index 0 -> number 2, etc...
        vector<std::string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<std::string> combinations;
        std::string temp;
        
        // Account for empty string
        if (digits.empty())
            return combinations;
        
        // Start from the first digit and recurse fro all of its possible letters
        for (int i = 0; i < letters[digits[0]-'0'-2].size(); ++i)
            letter_combinations_helper(combinations, digits, temp, i, 0, letters);
        
        return combinations;
    }
    /*
     * combinations: the vector of strings being built up
     * digits: the given string of digits
     * current_string: the current string being built up to be added to combinations
     * letter_index: the current index of the letter we are adding
     * digits_index: the index of the current digit we are looking at
     * letters: the possible letters each digit can be
     */
    void letter_combinations_helper(vector<std::string>& combinations, std::string digits, 
                                    std::string current_string, int letter_index, int digits_index,
                                    vector<std::string> letters)
    {
        // Otherwise, add the next letter to the string being built
        // -2 because phone number letters start at 2, not 0
        current_string.push_back(letters[digits[digits_index]-'0'-2][letter_index]);
        
            
        if (current_string.size() == digits.size())
        {
            // Add the string and start afresh
            combinations.push_back(current_string);
        }
            
        // Now recurse to push back all the possibilities for the next character
        if (digits_index + 1 < digits.size())
        {
            for (int i = 0; i < letters[digits[digits_index+1]-'0'-2].size(); ++i)
            {
                letter_combinations_helper(combinations, digits, current_string,
                                              i, digits_index+1, letters);
            }
        }
    }
};
