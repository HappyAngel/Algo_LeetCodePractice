/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * ideas: use 2 pointers starting from the origin, one walks 1 step per time, the other 2
 * when the 2 steps pointer catches up 1 step pointer, we can know it has cycle
 * to get the pointer of where the cycle begins, we can use another 2 pointers, one starting at
 * catching up point,the other one starts at origin, both of them walks 1 step per time, we can prove they
 * will meet at the point where the cycle begins.
 *
 * to prove the second point:
 *
 * let's ues L1 to represents distance from origin to cycle begin point, L2 representing distance between cycle begin
 * point to catching up point and L3 representing distance between catching up point and cycle begin points(the other part).
 * 
 * condition is: the 1 step pointer meets 2 step pointer at catching up point, thus we can deduce below expression:
 * L1 + L2 = (L1+L2+L3+L2)/2 => 2*L1 + 2*L2 = L1+2*L2+L3 => L1 = L3 (done.)
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
