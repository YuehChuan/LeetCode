class Solution {
public:
    vector<int>tem;
    vector<vector<int>>res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	pathSumHelper(root, sum);
    	return res;
    }
    
    void pathSumHelper(TreeNode* root, int sum) {
    	if (root == NULL)
    		return;
    	tem.push_back(root->val);
    	if (root->left == NULL&&root->right == NULL&&root->val == sum) {
    		res.push_back(tem);
    	}
    	pathSumHelper(root->left, sum - root->val);
    	pathSumHelper(root->right, sum - root->val);
    	tem.pop_back();
    }
};
//其实我还是不会
//几号，回溯中间不能有return，的
//我想我这属于瞎总结啊，加油啊
//  还是没有完全掌握
