#pragma once
#include<iostream>
#include<string>
using namespace std;

/// <summary>
/// 链表节点
/// </summary>
/// <typeparam name="T">模板类型</typeparam>
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
	/// 在p节点后插入值为value的节点
	/// </summary>
	/// <param name="p">p节点</param>
	/// <param name="">值</param>
	/// <returns></returns>
	bool insertNextNode(ListNode<T>* p, T value);

	/// <summary>
	/// 获得索引为i的节点
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	ListNode<T>* getNodeOfIndex(int i);

	/// <summary>
	/// 返回值为value的节点
	/// </summary>
	/// <param name="value">值</param>
	/// <param i="value">节点序号</param>
	/// <returns></returns>
	ListNode<T>* getNodeOfValue(T value, int& i);

	/// <summary>
	/// 返回值为value的节点
	/// </summary>
	/// <param name="value">值</param>
	/// <returns></returns>
	ListNode<T>* getNodeOfValue(T value);

public:
	int length;

	LinkedList();

	/// <summary>
	/// 在链表尾添加元素
	/// </summary>
	/// <param name="value">元素值</param>
	void add(T value);

	/// <summary>
	/// 插入元素
	/// </summary>
	/// <param name="i">插入的位置</param>
	/// <param name="value">添加的元素</param>
	/// <returns>插入操作的结果</returns>
	bool insert(int i, T value);			//平均时间复杂度：O(n)

	/// <summary>
	/// 移除指定索引的元素
	/// </summary>
	/// <param name="i">索引下标</param>
	/// <returns>移除操作的结果</returns>
	bool removeAt(int i);				//平均时间复杂度：O(n)

	/// <summary>
	/// 移除列表第一个值为value的元素
	/// </summary>
	/// <param name="value">元素值</param>
	/// <returns>移除操作的结果</returns>
	bool remove(T value);

	/// <summary>
	/// 返回指定索引的值
	/// </summary>
	/// <param name="i">索引下标</param>
	/// <returns>值</returns>
	T getValueOfIndex(int i);

	/// <summary>
	/// 返回指定值的第一个索引
	/// </summary>
	/// <param name="value">值</param>
	/// <returns>返回的索引</returns>
	int getIndexOfValue(T value);

	bool empty();

	bool clear();

	string toString();
};

template<class T>
bool LinkedList<T>::insertNextNode(ListNode<T>* p, T value)
{
	if (p == nullptr) return false;
	//新申请的节点插入p和p->next之间
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
	if (i < 0) return nullptr;	//位置不合法

	ListNode<T>* p = this->head;
	int j = -1;		//当前p指向的节点序号
	//找到第i个位置
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
	this->head = new ListNode<T>(); 	//头结点申请内存
	this->head->value = 0;
	this->head->next = nullptr;	//下一个节点（链表第一个节点）为空
	length = 0;
}

template<class T>
void LinkedList<T>::add(T value)
{
	ListNode<T>* p = this->head;

	while (p->next != nullptr) {
		p = p->next;
	}

	insertNextNode(p, value);	//在尾结点tail后插入元素值为value的节点

	length++;
}

template<class T>
bool LinkedList<T>::insert(int i, T value)			//平均时间复杂度：O(n)
{
	ListNode<T>* p = getNodeOfIndex(i - 1);		//获得第i-1个节点

	insertNextNode(p, value);	//在p后插入元素值为value的节点

	length++;

	return true;
}

template<class T>
bool LinkedList<T>::removeAt(int i)				//平均时间复杂度：O(n)
{
	ListNode<T>* p = getNodeOfIndex(i - 1);		//获得第i-1个节点

	if (p == nullptr) return false;

	//删除第i个节点
	ListNode<T>* q = p->next;
	p->next = q->next;
	delete(q);

	length--;

	return true;
}

template<class T>
bool LinkedList<T>::remove(T value)
{
	ListNode<T>* p = getNodeOfValue(value);		//获得值为value的第一个节点
	if (p == nullptr) return false;
	ListNode<T>* q = p->next;
	p->value = q->value;	//用q的值覆盖p的值
	p->next = q->next;

	delete(q);

	length--;

	return true;
}

template<class T>
T LinkedList<T>::getValueOfIndex(int i)
{
	return getNodeOfIndex(i) != nullptr ? getNodeOfIndex(i)->value : throw "索引超出范围！";
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
	return this->head->next == nullptr;		//头结点的下一个节点为空
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