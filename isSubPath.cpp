/*solution for singly-linked list.
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
    
    bool isSamePath(ListNode* head, TreeNode* root) {
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(root->val == head->val){
            head = head->next;
            return (isSamePath(head, root->left))||(isSamePath(head, root->right));
        }
        return false;
        
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) return false;
        return isSamePath(head, root)||isSubPath(head, root->left)||isSubPath(head, root->right);
    }
};
