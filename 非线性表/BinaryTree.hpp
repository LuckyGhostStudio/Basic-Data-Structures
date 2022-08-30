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
class BinarySearchTree	//����������
{
public:
	TreeNode<T>* root;

	BinarySearchTree()
	{
		this->root = nullptr; 
	}

	/// <summary>
	/// ����ڵ�
	/// </summary>
	/// <param name="value">ֵ</param>
	bool insert(T value)
	{
		TreeNode<T>* p = new TreeNode<T>(value, nullptr, nullptr);

		if (this->root == nullptr) {
			this->root = p;
			return true;
		}

		TreeNode<T>* temp = this->root;

		while (temp != nullptr) {
			if (temp->value == value) return false;		//�����ֵ�Ľ�㣬����ʧ��
			else if (temp->value > value) {
				if (temp->left != nullptr) {	//��������Ϊ��
					temp = temp->left;
				}
				else {
					temp->left = p;		//�������գ������½ڵ�
					return true;
				}
			}
			else {
				if (temp->right != nullptr) {	//��������Ϊ��
					temp = temp->right;
				}
				else {
					temp->right = p;		//�������գ������½ڵ�
					return true;
				}
			}
		}
	}

	/// <summary>
	/// ����ֵ
	/// </summary>
	/// <param name="value">ֵ</param>
	/// <returns>���ҽ��</returns>
	bool find(T value) 
	{
		return search(value) == nullptr ? false : true;
	}

	/// <summary>
	/// ���ҽ��
	/// </summary>
	/// <param name="value">ֵ</param>
	/// <returns>�ҵ��Ľ��</returns>
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
	/// ���������������
	/// </summary>
	/// <param name="root">���ڵ�</param>
	void preOrder(TreeNode<T>* root)
	{
		if (root != nullptr) {
			visit(root);
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	/// <summary>
	/// ��������������
	/// </summary>
	/// <param name="root">���ڵ�</param>
	void inOrder(TreeNode<T>* root)
	{
		if (root != nullptr) {
			inOrder(root->left);
			visit(root);
			inOrder(root->right);
		}
	}

	/// <summary>
	/// ������������Ҹ�
	/// </summary>
	/// <param name="root">���ڵ�</param>
	void postOrder(TreeNode<T>* root)
	{
		if (root != nullptr) {
			postOrder(root->left);
			postOrder(root->right);
			visit(root);
		}
	}

	/// <summary>
	/// �������
	/// </summary>
	/// <param name="root">���ڵ�</param>
	void levelOrder(TreeNode<T>* root)
	{
		queue<TreeNode<T>*> levelQueue = queue<TreeNode<T>*>();

		levelQueue.push(root);

		while (!levelQueue.empty()) {	//���зǿ�
			TreeNode<T>* head = levelQueue.front();		//��ö�ͷԪ��
			levelQueue.pop();	//��ͷԪ�س���
			visit(head);		//���ʶ�ͷԪ��
			
			if (head->left != nullptr) {
				levelQueue.push(head->left);	//�������
			}
			if (head->right != nullptr) {
				levelQueue.push(head->right);	//�Һ������
			}
		}
	}

	/// <summary>
	/// �����
	/// </summary>
	/// <param name="root">���ڵ�</param>
	/// <returns>���</returns>
	int getDepth(TreeNode<T>* root)
	{
		if (root == nullptr) {
			return 0;
		}

		int leftDepth = getDepth(root->left);		//�����������
		int rightDepth = getDepth(root->right);		//���������

		return leftDepth > rightDepth ? leftDepth : rightDepth;		//������������������ֵ
	}

	/// <summary>
	/// ��ӡ����������
	/// </summary>
	/// <param name="mode">����ģʽ��0 ���������1 ���������2 ���������3 �������</param>
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