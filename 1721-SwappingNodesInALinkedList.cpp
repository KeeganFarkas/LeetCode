// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth 
// node from the beginning and the kth node from the end (the list is 1-indexed).


// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]

// Example 2:
// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
// Output: [7,9,6,6,8,7,3,0,9,5]
 

// Constraints:
// The number of nodes in the list is n.
// 1 <= k <= n <= 105
// 0 <= Node.val <= 100

// Accepted 05/15/2023 - 696ms beats 39.9% - 180.1MB beats 87.37%

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* current = head;
        ListNode* kFromEnd = head;

        for (int i = 1; i < k; i++){
            current = current->next;
        };

        ListNode* kFromBeg = current;

        while (current->next != nullptr){
            current = current->next;
            kFromEnd = kFromEnd->next;
        };

        int temp = kFromBeg->val;
        kFromBeg->val = kFromEnd->val;
        kFromEnd->val = temp;

        return head;
    }
};