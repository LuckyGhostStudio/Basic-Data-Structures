#pragma once
#include<iostream>
#include<queue>
using namespace std;

template<class T>
class TreeNode
{
public:
	T value;
	TreeNode* left, * right;

	TreeNode(T value, TreeNode* l, TreeNode* r)
	{
		this->value = value;
		this->left = l;
		this->right = r;
	}
};

template<class T>
class BinarySearchTree	//二叉搜索树
{
public:
	TreeNode<T>* root;

	BinarySearchTree()
	{
		this->root = nullptr; 
	}

	/// <summary>
	/// 插入节点
	/// </summary>
	/// <param name="value">值</param>
	bool insert(T value)
	{
		TreeNode<T>* p = new TreeNode<T>(value, nullptr, nullptr);

		if (this->root == nullptr) {
			this->root = p;
			return true;
		}

		TreeNode<T>* temp = this->root;

		while (temp != nullptr) {
			if (temp->value == value) return false;		//有相等值的结点，插入失败
			else if (temp->value > value) {
				if (temp->left != nullptr) {	//左子树不为空
					temp = temp->left;
				}
				else {
					temp->left = p;		//左子树空，插入新节点
					return true;
				}
			}
			else {
				if (temp->right != nullptr) {	//右子树不为空
					temp = temp->right;
				}
				else {
					temp->right = p;		//右子树空，插入新节点
					return true;
				}
			}
		}
	}

	/// <summary>
	/// 查找值
	/// </summary>
	/// <param name="value">值</param>
	/// <returns>查找结果</returns>
	bool find(T value) 
	{
		return search(value) == nullptr ? false : true;
	}

	/// <summary>
	/// 查找结点
	/// </summary>
	/// <param name="value">值</param>
	/// <returns>找到的结点</returns>
	TreeNode<T>* search(T value)
	{
		TreeNode<T>* temp = this->root;
		
		while (temp != nullptr && temp->value != value) {
			if (value < temp->value) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}

		return temp;
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
	/// 求深度
	/// </summary>
	/// <param name="root">根节点</param>
	/// <returns>深度</returns>
	int getDepth(TreeNode<T>* root)
	{
		if (root == nullptr) {
			return 0;
		}

		int leftDepth = getDepth(root->left);		//求左子树深度
		int rightDepth = getDepth(root->right);		//右子树深度

		return leftDepth > rightDepth ? leftDepth : rightDepth;		//返回左右子树深度最大值
	}

	/// <summary>
	/// 打印二叉搜索树
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