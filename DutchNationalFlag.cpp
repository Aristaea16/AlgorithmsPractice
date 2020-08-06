/*
 * Laurie Kirk 8-5-20
 * Solving the Dutch National Flag Problem
 * AKA sorting red, white, and blue in order in place
 * Time complexity = O(n)
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0; // Starting from leftmost index
        int blue = nums.size()-1; // Starting from rightmost index
        int current_index = 0; // To loop through vecotr
        
        // Loop through swapping all red (0) values to the left and
        //  blue (2) values to the right leaving white (1) in the middle
        while (current_index <= blue)
        {
            if (nums[current_index] == 0)
            {
                swap(nums, current_index, red);
                ++current_index;
                ++red;
            } else if (nums[current_index] == 2)
            {
                swap(nums, current_index, blue);
                --blue;
            } else
            {
                // Value was white
                ++current_index;
            }
        }
    }
    
    /*
     Swaps the values at the two specified indices
     */
    void swap(vector<int>& nums, int index1, int index2)
    {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
};
