/*
 * Laurie Kirk 8-6-20
 * Searching a 2D matrix for a value
 * Time complexity: O(m+n)
 *
 * Note: could be improved by implementing binary search instead
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int current_row = 0;
        int current_col = 0;
        
        if (matrix.empty())
            return false;
        
        // Test each row
        while (current_row < matrix.size())
        {
            // Don't check an empty row and skip a row if the value is greater than the next
            if (!matrix[current_row].empty() && !(current_row + 1 < matrix.size() &&
                                                 target >= matrix[current_row+1][current_col]))
            {
                // No need to keep checking if we already passed where it could be
                if (target < matrix[current_row][current_col])
                    return false;
                else if (target >= matrix[current_row][current_col])
                {
                    // Check the remaining items in that row
                    while (current_col < matrix[current_row].size())
                    {
                        if (target < matrix[current_row][current_col])
                            return false;
                        if (target == matrix[current_row][current_col])
                            return true;

                        // Otherwise, check next element
                        ++current_col;
                    }
                }
            }
            
            // Try next row from the beginning
            ++current_row;
            current_col = 0;
        }
        
        // We did not find the target
        return false;
    }
};
