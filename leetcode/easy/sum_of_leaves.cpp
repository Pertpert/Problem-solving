#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

int traverse_node(TreeNode* root, bool is_left)
{
	if(root == nullptr)
		return 0;
	
	if(is_left && root->left == nullptr && root->right == nullptr)
		return root->val;
	
	return traverse_node(root->left, true) + traverse_node(root->right, false);
}

int sum_of_leaves(TreeNode* root)
{
	return traverse_node(root, false);
}

TreeNode* vec_to_tree(TreeNode* root, vector<int> &vec, int i, int n)
{
	if(i < n)
	{
		if(vec[i] == -1001) return nullptr;

		TreeNode* temp = new TreeNode(vec[i]);
		root = temp;
		root->left = vec_to_tree(root->left, vec, 2 * i + 1, n);
		root->right = vec_to_tree(root->right, vec, 2 * i + 2, n);
	}

	return root;
}

int main()
{
	vector<int> tree{3, 9, 20, -1001, -1001, 15, 7};

	TreeNode* root = vec_to_tree(root, tree, 0, tree.size());

	cout << sum_of_leaves(root) << '\n';

	return 0;
}