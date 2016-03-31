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
	vector<TreeNode*>res;
	void flatten(TreeNode* root) {
		if (root==NULL){
			return;
		}
		preorderHelper(root);
		TreeNode* dummy=root;
		
		for (int i=0;i<res.size();i++){
			root->left=NULL;
			root->right=res[i];
			root=root->right;
		}
		root->left=NULL;
		root->right=NULL;
		root=dummy;
	}
	void preorderHelper(TreeNode* root){
		if (root==NULL){
			return;
		}
		res.push_back(root);
		preorderHelper(root->left);
		preorderHelper(root->right);
	}
};
// 依然有一丢丢问题
class Solution {
public:
    vector<TreeNode*>res;
    void flatten(TreeNode* root) {
    	if (root==NULL){
    		return;
    	}
    	pregenerateTreeNode(root);
    	for (int i=1;i<res.size();i++){
    		root->left=NULL;root->right=res[i];
    		root=root->right;
    	}
    	root->left=NULL;root->right=NULL;
    }
    
    void pregenerateTreeNode(TreeNode* root){
    	if (root==NULL){
    		return;
    	}
    	res.push_back(root);
    	pregenerateTreeNode(root->left);
    	pregenerateTreeNode(root->right);
    }
};
//这条题目有问题，上面的答案能够通过！！！？
