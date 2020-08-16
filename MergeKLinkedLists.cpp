/*
 * Laurie Kirk 8-105-20
 * Merges k linked lists into a single one
 * Time complexity: O(n*k^2) 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merged_lists_head = NULL;
        ListNode* merged_lists_tail = NULL; // Since we will be constantly inserting at tail
        bool all_lists_empty = false;
        int min_index = -1; // Index of next list to grab element from
        int i; // Declaring the loop variable so it can be referenced elsewhere
        
        while (!all_lists_empty)
        {
            min_index = -1;
            
            // Find the next smallest element to add to our list
            for (int i = 0; i < lists.size(); ++i)
            {
                if (lists[i] == NULL)
                {
                    lists.erase(lists.begin() + i);
                    --i; // Account for the erase
                }
                else if (min_index == -1)
                    min_index = i;
                else if (lists[i]->val < lists[min_index]->val)
                    min_index = i;
            }
            
            // Check if we have no more elements
            if (min_index == -1)
                all_lists_empty = true;
            else
            {
                // Otherwise, add the next node and remove it
                add_node(&merged_lists_head, &merged_lists_tail, lists[min_index]->val);
                lists[min_index] = lists[min_index]->next;
            }
        }
        
        return merged_lists_head;
    }
    
    /*
     Adds a single node to the tail of the list
     */
    void add_node(ListNode** head, ListNode** tail, int new_value)
    {
        // Create a new node to add
        ListNode *new_node = new ListNode();
        new_node->val = new_value;
        new_node->next = NULL;
        
        // If this is the first node added
        if (*head == NULL)
        {
            *head = new_node;
            *tail = new_node;
        } else
        {
            // Add to the end of the list
            (*tail)->next = new_node;
            *tail = new_node;
        }
    }
};
