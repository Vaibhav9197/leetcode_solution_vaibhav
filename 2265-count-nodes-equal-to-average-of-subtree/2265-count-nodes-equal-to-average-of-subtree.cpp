/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int ans =0;
    pair<int,int> postorder(TreeNode* root){
        if(!root) return {0,0};

        auto[ls,lc] = postorder(root->left);
        auto[rs,rc] = postorder(root->right);

        int sum = ls+rs+root->val;
        int count = lc+rc+1;

        if(sum/count == root->val)ans++;
        return {sum,count};

    }
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return ans;   
    }
};