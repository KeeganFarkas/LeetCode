// Given the head of a singly linked list, return true if it is a 
// palindrome or false otherwise.


// 1->2->2->1

// Example 1:
// Input: head = [1,2,2,1]
// Output: true


// 1->2

// Example 2:
// Input: head = [1,2]
// Output: false
 

// Constraints:
// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9

// Accepted: 12/14/2022 - 270ms beats 20.69% - 132.6MB beats 8.28%

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        vector<int> reverse_nums;

        while (true){
            nums.push_back(head->val);
            if (!head->next)
                break;
            head = head->next;
        }

        reverse_nums = nums;
        reverse(reverse_nums.begin(), reverse_nums.end());

        if (nums == reverse_nums)
            return true;
        else
            return false;
    }
};
