#pragma once
#include<iostream>
#include<string>
using namespace std;

#define InitSize 10

/// <summary>
/// 顺序表
/// </summary>
template<class T>
class List
{
private:
	T* data;		//动态分配数组的指针
	int capacity;	//最大容量

public:
	int length;		//列表当前长度

private:
	/// <summary>
	/// 动态增加列表容量
	/// </summary>
	void increaseCapacity();

public:
	/// <summary>
	/// 构造函数
	/// </summary>
	List();

	/// <summary>
	/// 构造函数
	/// </summary>
	/// <param name="capacity">列表容量</param>
	List(int capacity);

	~List();

	/// <summary>
	/// 拷贝构造函数：深拷贝
	/// </summary>
	/// <param name="list">被拷贝的列表</param>
	List(const List& list);

	/// <summary>
	/// 重载=运算符
	/// </summary>
	/// <param name="list"></param>
	/// <returns></returns>
	List& operator=(const List& list);

	/// <summary>
	/// 添加元素
	/// </summary>
	/// <param name="value">添加的元素</param>
	void add(T value);

	/// <summary>
	/// 插入元素
	/// </summary>
	/// <param name="i">插入的位置</param>
	/// <param name="value">添加的元素</param>
	/// <returns>插入操作的结果</returns>
	bool insert(int i, T value);		//时间复杂度：最好O(1)，最坏O(n)，平均O(n)

	/// <summary>
	/// 移除指定索引的元素
	/// </summary>
	/// <param name="i">索引下标</param>
	/// <returns>移除操作的结果</returns>
	bool removeAt(int i);		//时间复杂度：最好O(1)，最坏O(n)，平均O(n)

	/// <summary>
	/// 移除列表第一个等值元素
	/// </summary>
	/// <param name="value">元素值</param>
	/// <returns>移除操作的结果</returns>
	bool remove(T value);

	/// <summary>
	/// 返回指定索引的值
	/// </summary>
	/// <param name="i">索引下标</param>
	/// <returns>值</returns>
	T getValueOfIndex(int i);		//时间复杂度：O(1)

	/// <summary>
	/// 返回指定值的第一个索引
	/// </summary>
	/// <param name="value">值</param>
	/// <returns>返回的索引</returns>
	int getIndexOfValue(T value);		//时间复杂度：最好O(1)，最坏O(n)，平均O(n)

	/// <summary>
	/// 列表逆序
	/// </summary>
	void reverse();

	/// <summary>
	/// 列表元素升序排序
	/// </summary>
	/// <param name="desc">是否降序</param>
	void sort(bool desc);

	/// <summary>
	/// 清空列表
	/// </summary>
	void clear();

	string toString();
};

template<class T>
List<T>::List()
{
	this->data = new T[InitSize];	//申请内存空间
	this->length = 0;
	this->capacity = InitSize;	//最大容量为初始容量
}

template<class T>
List<T>::List(int capacity)
{
	this->data = new T[InitSize];	//申请内存空间：int类型，大小=初始容量*int大小
	this->length = 0;
	this->capacity = capacity;	//最大容量为size
}

template<class T>
List<T>::~List()
{
	if (this->data != nullptr) {
		delete[] this->data;
		this->data = nullptr;
	}
}

template<class T>
List<T>::List(const List& list)
{
	this->capacity = list.capacity;
	this->length = list.length;

	this->data = new T[list.capacity];	//申请空间

	for (int i = 0; i < this->length; i++)
	{
		this->data[i] = list.data[i];
	}
}

template<class T>
List<T>& List<T>::operator=(const List& list)
{
	//释放原来的数据
	if (this->data != nullptr) {
		delete[] this->data;
		this->data = nullptr;
		this->capacity = 0;
		this->length = 0;
	}

	this->capacity = list.capacity;
	this->length = list.length;

	this->data = new T[list.capacity];	//申请空间

	for (int i = 0; i < this->length; i++)
	{
		this->data[i] = list.data[i];
	}

	return *this;
}

template<class T>
void List<T>::increaseCapacity()
{
	T* p = this->data;	//记录data的初始位置
	this->data = new T[this->capacity * 2];	//申请内存空间：容量翻倍

	//将原来的内存数据复制到新申请的空间
	for (int i = 0; i < this->length; i++) {
		this->data[i] = p[i];
	}

	this->capacity *= 2;		//最大容量+额外申请的长度

	delete(p);	//释放原来的内存空间
}

template<class T>
void List<T>::add(T value)
{
	if (this->length == this->capacity) {	//列表已满
		this->increaseCapacity();		//增加容量
	}

	this->data[length] = value;
	this->length++;
}

template<class T>
bool List<T>::insert(int i, T value)		//时间复杂度：最好O(1)，最坏O(n)，平均O(n)
{
	if (i<0 || i>this->length) {
		return false;
	}

	if (this->length == this->capacity) {
		increaseCapacity();
	}

	//将i位置及以后的元素后移一位
	for (int j = this->length; j > i; j--) {
		this->data[j] = this->data[j - 1];
	}

	this->data[i] = value;
	this->length++;

	return true;
}


template<class T>
bool List<T>::removeAt(int i)		//时间复杂度：最好O(1)，最坏O(n)，平均O(n)
{
	if (i<0 || i>this->length - 1) {
		return false;
	}

	//i以后的元素前移一位
	for (int j = i; j < this->length - 1; j++) {
		this->data[j] = this->data[j + 1];
	}

	this->length--;	//长度-1

	return true;
}

template<class T>
bool List<T>::remove(T value)
{
	int index = getIndexOfValue(value);		//获得value的索引

	if (index == -1) return false;	//value不存在

	//index以后的元素前移一位
	for (int i = index; i < this->length - 1; i++) {
		this->data[i] = this->data[i + 1];
	}

	this->length--;	//长度-1

	return true;
}

template<class T>
T List<T>::getValueOfIndex(int i)		//时间复杂度：O(1)
{
	if (i<0 || i>this->length) {
		throw "索引超出范围！";
	}

	return this->data[i];
}

template<class T>
int List<T>::getIndexOfValue(T value)		//时间复杂度：最好O(1)，最坏O(n)，平均O(n)
{
	//TODO:可更改为二分查找
	for (int i = 0; i < this->length; i++)
	{
		if (value == this->data[i]) return i;
	}

	return -1;	//值不存在
}

template<class T>
void List<T>::reverse()
{
	for (int i = 0; i < this->length / 2; i++)
	{
		T temp = this->data[i];
		this->data[i] = this->data[length - i - 1];
		this->data[length - i - 1] = temp;
	}
}

template<class T>
void List<T>::sort(bool desc)
{

}

template<class T>
void List<T>::clear()
{
	this->capacity = InitSize;
	this->length = 0;
	delete[] this->data;
	this->data = nullptr;
}

template<class T>
string List<T>::toString()
{
	string list = "[";

	for (int i = 0; i < this->length; i++)
	{
		list += to_string(this->data[i]);
		if (i != this->length - 1)
			list += ",";
	}

	return list + "]";
}