/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode *oneStepPointer = head;
        ListNode *twoStepsPointer = head;
        
        while(oneStepPointer->next != NULL && twoStepsPointer->next != NULL && twoStepsPointer->next->next != NULL)
        {
            oneStepPointer = oneStepPointer->next;
            twoStepsPointer = twoStepsPointer->next->next;
            
            if(oneStepPointer == twoStepsPointer)
            {
                ListNode *tmpNode = head;
                
                while(tmpNode != oneStepPointer)
                {
                    tmpNode = tmpNode->next;
                    oneStepPointer = oneStepPointer->next;
                }
                
                return tmpNode;
            }
        }
        
        return NULL;
    }
};