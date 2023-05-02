// Given the head of a singly linked list, return the middle node 
// of the linked list.

// If there are two middle nodes, return the second middle node.


// 1->2->3->4->5

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.


// 1->2->3->4->5->6

// Example 2:
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, 
// we return the second one.
 

// Constraints:
// The number of nodes in the list is in the range [1, 100].
// 1 <= Node.val <= 100

// Accepted: 12/18/2022 - 0ms beats 100% - 7MB beats 78.39%

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* middleNode(ListNode* head) {
        ListNode* mid = head;
        
        while (head && head->next){
            head = head->next->next;
            mid = mid->next;
        }
        return mid;
    }
};