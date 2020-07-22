/*
 * Laurie Kirk 7-21-20
 * Reversing a linked list
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
    ListNode* reverseList(ListNode* head) {
        // Account for empty list
        if (head == NULL)
            return head;
        
        ListNode *temp = head;
        ListNode *previous = NULL;
        ListNode *next_node = head->next;
    
        // Loop through each node reversing pointers
        while (next_node != NULL)
        {
            temp->next = previous;
            previous = temp;
            temp = next_node;
            next_node = next_node->next;
        }
        
        // Account for last node[]
        temp->next = previous;
        
        return temp;
    }
};
