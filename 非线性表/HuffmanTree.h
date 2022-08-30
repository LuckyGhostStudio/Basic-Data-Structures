#pragma once
#include<iostream>
#include<vector>
#include"BinaryTree.hpp"
using namespace std;

template<class T>
class Compare
{
public:
	bool operator()(TreeNode<T>* node1, TreeNode<T>* node2) const
	{
		return node1->value < node2->value;	//由小到大
	}
};

/// <summary>
/// 哈夫曼树
/// </summary>
template<class T>
class HuffmanTree
{
public:
	TreeNode<T>* root;

	/// <summary>
	/// 构造哈夫曼树
	/// </summary>
	/// <param name="weight">权重集合</param>
	/// <param name="n">集合初始大小</param>
	HuffmanTree(const T* weight, int n)
	{
		vector<TreeNode<T>*> weights = vector<TreeNode<T>*>();	//n个结点集合

		for (int i = 0; i < n; i++)
		{
			weights.push_back(new TreeNode<T>(weight[i], nullptr, nullptr));
		}

		if (n > 1) {
			while (weights.size() > 1) {
				sort(weights.begin(), weights.end(), Compare<T>());	//升序排序

				//权重最小的两个结点
				TreeNode<T>* min1Node = weights[0];
				TreeNode<T>* min2Node = weights[1];

				//构造新结点：权重=权重和
				TreeNode<T>* tempRoot = new TreeNode<T>(min1Node->value + min2Node->value, min1Node, min2Node);

				weights.erase(weights.begin(), weights.begin() + 2);	//移除选出的两个最小权重子树
				weights.push_back(tempRoot);							//添加新的结点到集合

				///*for (int i = 0; i < weights.size(); i++)
				//{
				//	cout << weights[i]->value << " ";
				//}
				//cout << endl;*/
			}
		}

		this->root = weights[0];
	}

	void visit(TreeNode<T>* root)
	{
		cout << root->value << " ";
	}

	/// <summary>
	/// 先序遍历：根左右
	/// </summary>
	/// <param name="root">根节点</param>
	void preOrder(TreeNode<T>* root)
	{
		if (root != nullptr) {
			visit(root);
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	/// <summary>
	/// 中序遍历：左根右
	/// </summary>
	/// <param name="root">根节点</param>
	void inOrder(TreeNode<T>* root)
	{
		if (root != nullptr) {
			inOrder(root->left);
			visit(root);
			inOrder(root->right);
		}
	}

	/// <summary>
	/// 后序遍历：左右根
	/// </summary>
	/// <param name="root">根节点</param>
	void postOrder(TreeNode<T>* root)
	{
		if (root != nullptr) {
			postOrder(root->left);
			postOrder(root->right);
			visit(root);
		}
	}

	/// <summary>
	/// 层序遍历
	/// </summary>
	/// <param name="root">根节点</param>
	void levelOrder(TreeNode<T>* root)
	{
		queue<TreeNode<T>*> levelQueue = queue<TreeNode<T>*>();

		levelQueue.push(root);

		while (!levelQueue.empty()) {	//队列非空
			TreeNode<T>* head = levelQueue.front();		//获得队头元素
			levelQueue.pop();	//队头元素出队
			visit(head);		//访问队头元素

			if (head->left != nullptr) {
				levelQueue.push(head->left);	//左孩子入队
			}
			if (head->right != nullptr) {
				levelQueue.push(head->right);	//右孩子入队
			}
		}
	}

	/// <summary>
	/// 打印哈夫曼树
	/// </summary>
	/// <param name="mode">遍历模式：0 先序遍历，1 中序遍历，2 后序遍历，3 层序遍历</param>
	void print(int mode)
	{
		switch (mode)
		{
		case 0:
			preOrder(this->root);
			break;
		case 1:
			inOrder(this->root);
			break;
		case 2:
			postOrder(this->root);
			break;
		case 3:
			levelOrder(this->root);
			break;
		default:
			inOrder(this->root);
		}
	}
};


