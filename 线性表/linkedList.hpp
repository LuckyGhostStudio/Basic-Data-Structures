#pragma once
#include<iostream>
#include<string>
using namespace std;

/// <summary>
/// ����ڵ�
/// </summary>
/// <typeparam name="T">ģ������</typeparam>
template<class T>
class ListNode
{
public:
	T value;
	ListNode<T>* next;
};

template<class T>
class LinkedList
{
	ListNode<T>* head;

	/// <summary>
	/// ��p�ڵ�����ֵΪvalue�Ľڵ�
	/// </summary>
	/// <param name="p">p�ڵ�</param>
	/// <param name="">ֵ</param>
	/// <returns></returns>
	bool insertNextNode(ListNode<T>* p, T value);

	/// <summary>
	/// �������Ϊi�Ľڵ�
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	ListNode<T>* getNodeOfIndex(int i);

	/// <summary>
	/// ����ֵΪvalue�Ľڵ�
	/// </summary>
	/// <param name="value">ֵ</param>
	/// <param i="value">�ڵ����</param>
	/// <returns></returns>
	ListNode<T>* getNodeOfValue(T value, int& i);

	/// <summary>
	/// ����ֵΪvalue�Ľڵ�
	/// </summary>
	/// <param name="value">ֵ</param>
	/// <returns></returns>
	ListNode<T>* getNodeOfValue(T value);

public:
	int length;

	LinkedList();

	/// <summary>
	/// ������β���Ԫ��
	/// </summary>
	/// <param name="value">Ԫ��ֵ</param>
	void add(T value);

	/// <summary>
	/// ����Ԫ��
	/// </summary>
	/// <param name="i">�����λ��</param>
	/// <param name="value">��ӵ�Ԫ��</param>
	/// <returns>��������Ľ��</returns>
	bool insert(int i, T value);			//ƽ��ʱ�临�Ӷȣ�O(n)

	/// <summary>
	/// �Ƴ�ָ��������Ԫ��
	/// </summary>
	/// <param name="i">�����±�</param>
	/// <returns>�Ƴ������Ľ��</returns>
	bool removeAt(int i);				//ƽ��ʱ�临�Ӷȣ�O(n)

	/// <summary>
	/// �Ƴ��б��һ��ֵΪvalue��Ԫ��
	/// </summary>
	/// <param name="value">Ԫ��ֵ</param>
	/// <returns>�Ƴ������Ľ��</returns>
	bool remove(T value);

	/// <summary>
	/// ����ָ��������ֵ
	/// </summary>
	/// <param name="i">�����±�</param>
	/// <returns>ֵ</returns>
	T getValueOfIndex(int i);

	/// <summary>
	/// ����ָ��ֵ�ĵ�һ������
	/// </summary>
	/// <param name="value">ֵ</param>
	/// <returns>���ص�����</returns>
	int getIndexOfValue(T value);

	bool empty();

	bool clear();

	string toString();
};

template<class T>
bool LinkedList<T>::insertNextNode(ListNode<T>* p, T value)
{
	if (p == nullptr) return false;
	//������Ľڵ����p��p->next֮��
	ListNode<T>* q = new ListNode<T>();
	if (q == nullptr) return false;

	q->value = value;
	q->next = p->next;
	p->next = q;

	return true;
}

template<class T>
ListNode<T>* LinkedList<T>::getNodeOfIndex(int i)
{
	if (i < 0) return nullptr;	//λ�ò��Ϸ�

	ListNode<T>* p = this->head;
	int j = -1;		//��ǰpָ��Ľڵ����
	//�ҵ���i��λ��
	while (p != nullptr && j < i) {
		p = p->next;
		j++;
	}

	return p;
}

template<class T>
ListNode<T>* LinkedList<T>::getNodeOfValue(T value, int& i)
{
	ListNode<T>* p = this->head->next;

	while (p != nullptr && p->value != value) {
		p = p->next;
		i++;
	}

	return p;
}

template<class T>
ListNode<T>* LinkedList<T>::getNodeOfValue(T value)
{
	ListNode<T>* p = this->head->next;

	while (p != nullptr && p->value != value) {
		p = p->next;
	}

	return p;
}

template<class T>
LinkedList<T>::LinkedList()
{
	this->head = new ListNode<T>(); 	//ͷ��������ڴ�
	this->head->value = 0;
	this->head->next = nullptr;	//��һ���ڵ㣨�����һ���ڵ㣩Ϊ��
	length = 0;
}

template<class T>
void LinkedList<T>::add(T value)
{
	ListNode<T>* p = this->head;

	while (p->next != nullptr) {
		p = p->next;
	}

	insertNextNode(p, value);	//��β���tail�����Ԫ��ֵΪvalue�Ľڵ�

	length++;
}

template<class T>
bool LinkedList<T>::insert(int i, T value)			//ƽ��ʱ�临�Ӷȣ�O(n)
{
	ListNode<T>* p = getNodeOfIndex(i - 1);		//��õ�i-1���ڵ�

	insertNextNode(p, value);	//��p�����Ԫ��ֵΪvalue�Ľڵ�

	length++;

	return true;
}

template<class T>
bool LinkedList<T>::removeAt(int i)				//ƽ��ʱ�临�Ӷȣ�O(n)
{
	ListNode<T>* p = getNodeOfIndex(i - 1);		//��õ�i-1���ڵ�

	if (p == nullptr) return false;

	//ɾ����i���ڵ�
	ListNode<T>* q = p->next;
	p->next = q->next;
	delete(q);

	length--;

	return true;
}

template<class T>
bool LinkedList<T>::remove(T value)
{
	ListNode<T>* p = getNodeOfValue(value);		//���ֵΪvalue�ĵ�һ���ڵ�
	if (p == nullptr) return false;
	ListNode<T>* q = p->next;
	p->value = q->value;	//��q��ֵ����p��ֵ
	p->next = q->next;

	delete(q);

	length--;

	return true;
}

template<class T>
T LinkedList<T>::getValueOfIndex(int i)
{
	return getNodeOfIndex(i) != nullptr ? getNodeOfIndex(i)->value : throw "����������Χ��";
}

template<class T>
int LinkedList<T>::getIndexOfValue(T value)
{
	int i = 0;
	return getNodeOfValue(value, i) != nullptr ? i : -1;
}

template<class T>
bool LinkedList<T>::empty()
{
	return this->head->next == nullptr;		//ͷ������һ���ڵ�Ϊ��
}

template<class T>
bool LinkedList<T>::clear()
{
	while (this->head->next != nullptr) {
		ListNode<T>* p = this->head->next;
		if (p == nullptr) return false;
		this->head->next = p->next;
		delete p;
	}
	delete this->head;
	this->head = nullptr;
}

template<class T>
string LinkedList<T>::toString()
{
	string linkedList = "";
	ListNode<T>* p = this->head->next;

	while (p != nullptr) {
		linkedList += to_string(p->value);
		if (p->next != nullptr)
			linkedList += "->";
		p = p->next;
	}

	return linkedList;
}