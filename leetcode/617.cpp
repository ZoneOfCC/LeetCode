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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        last_merge(&t1, &t2);
        return t1;
    }
    void last_merge(TreeNode **t1, TreeNode **t2) {
        if (*t1 != nullptr) {
            if (*t2 == nullptr) {
                TreeNode * tmp = nullptr;
                last_merge(&(*t1)->left, &tmp);
                last_merge(&(*t1)->right, &tmp);
            } else {
                last_merge(&(*t1)->left, &(*t2)->left);
                last_merge(&(*t1)->right, &(*t2)->right);
            }
        }
        if (*t1 != nullptr && *t2 != nullptr) {
            (*t1)->val += (*t2)->val;
        } else if (*t1 == nullptr && *t2 != nullptr) {
            *t1 = *t2;
        }
    }
};