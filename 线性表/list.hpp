#pragma once
#include<iostream>
#include<string>
using namespace std;

#define InitSize 10

/// <summary>
/// ˳���
/// </summary>
template<class T>
class List
{
private:
	T* data;		//��̬���������ָ��
	int initSize;	//��ʼ����
	int maxSize;	//�������

public:
	int length;		//�б�ǰ����

private:
	/// <summary>
	/// ��̬�����б�����
	/// </summary>
	void increaseSize();

public:
	/// <summary>
	/// ���캯��
	/// </summary>
	List();

	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="size">�б�����</param>
	List(int size);

	~List();

	/// <summary>
	/// ���Ԫ��
	/// </summary>
	/// <param name="value">��ӵ�Ԫ��</param>
	void add(T value);

	/// <summary>
	/// ����Ԫ��
	/// </summary>
	/// <param name="i">�����λ��</param>
	/// <param name="value">��ӵ�Ԫ��</param>
	/// <returns>��������Ľ��</returns>
	bool insert(int i, T value);		//ʱ�临�Ӷȣ����O(1)���O(n)��ƽ��O(n)

	/// <summary>
	/// �Ƴ�ָ��������Ԫ��
	/// </summary>
	/// <param name="i">�����±�</param>
	/// <returns>�Ƴ������Ľ��</returns>
	bool removeAt(int i);		//ʱ�临�Ӷȣ����O(1)���O(n)��ƽ��O(n)

	/// <summary>
	/// �Ƴ��б��һ����ֵԪ��
	/// </summary>
	/// <param name="value">Ԫ��ֵ</param>
	/// <returns>�Ƴ������Ľ��</returns>
	bool remove(T value);

	/// <summary>
	/// ����ָ��������ֵ
	/// </summary>
	/// <param name="i">�����±�</param>
	/// <returns>ֵ</returns>
	T getValueOfIndex(int i);		//ʱ�临�Ӷȣ�O(1)

	/// <summary>
	/// ����ָ��ֵ�ĵ�һ������
	/// </summary>
	/// <param name="value">ֵ</param>
	/// <returns>���ص�����</returns>
	int getIndexOfValue(T value);		//ʱ�临�Ӷȣ����O(1)���O(n)��ƽ��O(n)

	/// <summary>
	/// �б�����
	/// </summary>
	void reverse();

	/// <summary>
	/// �б�Ԫ����������
	/// </summary>
	/// <param name="desc">�Ƿ���</param>
	void sort(bool desc);

	/// <summary>
	/// ����б�
	/// </summary>
	void clear();

	string toString();
};

template<class T>
List<T>::List()
{
	this->initSize = InitSize;
	this->data = (T*)operator new(this->initSize * sizeof(T));	//�����ڴ�ռ䣺int���ͣ���С=��ʼ����*int��С
	this->length = 0;
	this->maxSize = this->initSize;	//�������Ϊ��ʼ����
}

template<class T>
List<T>::List(int size)
{
	this->data = (T*)operator new(size * sizeof(T));	//�����ڴ�ռ䣺int���ͣ���С=��ʼ����*int��С
	this->length = 0;
	this->maxSize = size;	//�������Ϊsize
}

template<class T>
List<T>::~List()
{
	
}

template<class T>
void List<T>::increaseSize()
{
	T* p = this->data;	//��¼data�ĳ�ʼλ��
	this->data = (T*)operator new(this->maxSize * 2 * sizeof(T));	//�����ڴ�ռ䣺��������

	//��ԭ�����ڴ����ݸ��Ƶ�������Ŀռ�
	for (int i = 0; i < this->length; i++) {
		this->data[i] = p[i];
	}

	this->maxSize *= 2;		//�������+��������ĳ���

	delete(p);	//�ͷ�ԭ�����ڴ�ռ�
}

template<class T>
void List<T>::add(T value)
{
	if (this->length == this->maxSize) {	//�б�����
		increaseSize();		//��������
	}

	this->data[length] = value;
	this->length++;
}

template<class T>
bool List<T>::insert(int i, T value)		//ʱ�临�Ӷȣ����O(1)���O(n)��ƽ��O(n)
{
	if (i<0 || i>this->length) {
		return false;
	}

	if (this->length == this->maxSize) {
		increaseSize();
	}

	//��iλ�ü��Ժ��Ԫ�غ���һλ
	for (int j = this->length; j > i; j--) {
		this->data[j] = this->data[j - 1];
	}

	this->data[i] = value;
	this->length++;

	return true;
}


template<class T>
bool List<T>::removeAt(int i)		//ʱ�临�Ӷȣ����O(1)���O(n)��ƽ��O(n)
{
	if (i<0 || i>this->length - 1) {
		return false;
	}

	//i�Ժ��Ԫ��ǰ��һλ
	for (int j = i; j < this->length - 1; j++) {
		this->data[j] = this->data[j + 1];
	}

	this->length--;	//����-1

	return true;
}

template<class T>
bool List<T>::remove(T value)
{
	int index = getIndexOfValue(value);		//���value������

	if (index == -1) return false;	//value������

	//index�Ժ��Ԫ��ǰ��һλ
	for (int i = index; i < this->length - 1; i++) {
		this->data[i] = this->data[i + 1];
	}

	this->length--;	//����-1

	return true;
}

template<class T>
T List<T>::getValueOfIndex(int i)		//ʱ�临�Ӷȣ�O(1)
{
	if (i<0 || i>this->length) {
		throw "����������Χ��";
	}

	return this->data[i];
}

template<class T>
int List<T>::getIndexOfValue(T value)		//ʱ�临�Ӷȣ����O(1)���O(n)��ƽ��O(n)
{
	//TODO:�ɸ���Ϊ���ֲ���
	for (int i = 0; i < this->length; i++)
	{
		if (value == this->data[i]) return i;
	}

	return -1;	//ֵ������
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
	this->maxSize = this->initSize;
	this->length = 0;
	delete[] this->data;
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