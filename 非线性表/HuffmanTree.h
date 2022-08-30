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
		return node1->value < node2->value;	//��С����
	}
};

/// <summary>
/// ��������
/// </summary>
template<class T>
class HuffmanTree
{
public:
	TreeNode<T>* root;

	/// <summary>
	/// �����������
	/// </summary>
	/// <param name="weight">Ȩ�ؼ���</param>
	/// <param name="n">���ϳ�ʼ��С</param>
	HuffmanTree(const T* weight, int n)
	{
		vector<TreeNode<T>*> weights = vector<TreeNode<T>*>();	//n����㼯��

		for (int i = 0; i < n; i++)
		{
			weights.push_back(new TreeNode<T>(weight[i], nullptr, nullptr));
		}

		if (n > 1) {
			while (weights.size() > 1) {
				sort(weights.begin(), weights.end(), Compare<T>());	//��������

				//Ȩ����С���������
				TreeNode<T>* min1Node = weights[0];
				TreeNode<T>* min2Node = weights[1];

				//�����½�㣺Ȩ��=Ȩ�غ�
				TreeNode<T>* tempRoot = new TreeNode<T>(min1Node->value + min2Node->value, min1Node, min2Node);

				weights.erase(weights.begin(), weights.begin() + 2);	//�Ƴ�ѡ����������СȨ������
				weights.push_back(tempRoot);							//����µĽ�㵽����

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
	/// ��ӡ��������
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


