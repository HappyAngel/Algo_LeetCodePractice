/*
	Problem: 
	Given a complete binary tree, count the number of nodes.
	Definition of a complete binary tree from Wikipedia:In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

	Solution:
	Key idea is Binary Search! 
	3 actions:
		1 calcuate the height of the tree (marked as h), by keep traversing left from the root until the leaf, as this is a complete binary tree, the height is the depth;
		2 Split, we take root node and go right and then keep traversing to the left child until leaf, where we compare current height with tree's height h-loopindex;
		we can say if current height x < h, then the right part is a complete binary tree otherwise the left is;
		3 when to stop? at most h times split could lead to end;
*/

#include <allocators>
#include <string>
#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
	int GetCompleteBinaryTreeCount(TreeNode* root) {
		// breath first traverse
		if (root == NULL)
		{
			return 0;
		}

		TreeNode* currentNode = root;
		int count = 0;
		int level = GetHeight(root);
			
		for (int i = level; i > 0; i--)
		{
			int tmpLevel = 0;

			if (currentNode != NULL)
			{
				tmpLevel = GetHeight(currentNode->right) + 1;
			}

			if (tmpLevel == i)
			{
				currentNode = currentNode->right;
				count += pow(2, i - 1) - 1 + 1;
			}
			else if (tmpLevel < i)
			{
				currentNode = currentNode->left;
				count += pow(2, i - 2) - 1 + 1;
			}
		}

		return count;
	}

	int GetHeight(TreeNode* node)
	{
		if (node == NULL)
			return 0;

		int level = 1;

		while (node->left != NULL)
		{
			node = node->left;
			level++;
		}

		return level;
	}
};

int main()
{
	TreeNode root(4);
	
	TreeNode leftChildOfRoot(2);
	TreeNode rightChildOfRoot(7);
	root.left = &leftChildOfRoot;
	root.right = &rightChildOfRoot;

	TreeNode leftChildOfLeft(1);
	TreeNode rightChildOfLeft(3);
	leftChildOfRoot.left = &leftChildOfLeft;
	leftChildOfRoot.right = &rightChildOfLeft;

	TreeNode leftChildOfRight(6);
	TreeNode rightChildOfRight(9);
	rightChildOfRoot.left = &leftChildOfRight;
	rightChildOfRoot.right = &rightChildOfRight;

	Solution s;

	int c = s.GetCompleteBinaryTreeCount(&root);

	cout << c << endl;

	int a = 1;
	cin >> a;

	return 0;
}