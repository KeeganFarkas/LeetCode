// Given a linked list, swap every two adjacent nodes and return its head. 
// You must solve the problem without modifying the values in the list's nodes 
// (i.e., only nodes themselves may be changed.)


// Example 1:
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

// Example 2:
// Input: head = []
// Output: []

// Example 3:
// Input: head = [1]
// Output: [1]
 

// Constraints:
// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100

// Accepted: 05/16/2023 - 0ms beats 100% - 7.5MB beats 88.23%

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* current = head;
        ListNode* first = current;
        current = current->next;
        ListNode* second = current;
        head = current;

        if (current->next == nullptr) {
            second->next = first;
            first->next = nullptr;
            return head;
        }

        current = current->next;
        ListNode* prev = first;
        second->next = first;

        while (current->next != nullptr) {
            first = current;
            current = current->next;
            second = current;

            if (current->next == nullptr) {
                second->next = first;
                first->next = nullptr;
                prev->next = second;
                return head;
            }

            current = current->next;
            second->next = first;
            prev->next = second;
            prev = first;
        }

        if (first->next = second) first->next = current;

        return head;
    }
};