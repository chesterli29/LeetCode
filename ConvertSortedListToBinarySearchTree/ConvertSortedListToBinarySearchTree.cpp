/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
        	return nullptr;
        if(head -> next == nullptr)
        	return new TreeNode(head->val);
        ListNode * fast = head->next->next, * slow = head;
        while(fast != nullptr && fast ->next != nullptr) {
        	fast = fast->next->next;
        	slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->next->val);
        root->right = sortedListToBST(slow->next->next);
        slow->next = nullptr;
        root->left = sortedListToBST(head);
        return root;
    }
};