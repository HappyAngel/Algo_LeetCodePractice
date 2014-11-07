/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * Condition:  assume n >= length (ListNode)
 * 
 * Algorithm: maintain 3 pointers, 1 is curPointer, 1 is previous pointer of curPointer, the last one is the curPointer + n-1, if last one is null, we get to the target. one pass.
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        if (n<1 || head == NULL)
        {
            return head;
        }
        
        if (head->next == NULL)
        {
            return NULL;
        }
        
        ListNode* prePointer = head;
        ListNode* curPointer = head->next;
        ListNode* nextPointer = curPointer->next;
        
        // setting nextPointer to be (curPointer + n-1)
        while (n>1)
        {
            if(nextPointer == NULL)
            {
                // assume n >= length(linkNode)
                return head->next;
            }
            
            nextPointer = nextPointer->next;
            n--;
        }
        
        while (nextPointer != NULL)
        {
            prePointer = prePointer->next;
            curPointer = curPointer->next;
            nextPointer = nextPointer->next;
        }
        
        prePointer->next = curPointer->next;
        
        return head;
    }
};