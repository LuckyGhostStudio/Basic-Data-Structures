#pragma once
#include<iostream>
#include<string>
#define Capacity 10
using namespace std;

template<class T>
class Stack
{
	T* data;
	int capacity;	//����
	int top;		//ջ��ָ��

	/// <summary>
	/// ��������
	/// </summary>
	void increaseCapacity()
	{
		T* p = this->data;	//��¼data�ĳ�ʼλ��
		this->data = new T[this->capacity * 2];	//�����ڴ�ռ䣺��������

		//��ԭ�����ڴ����ݸ��Ƶ�������Ŀռ�
		for (int i = 0; i < this->top + 1; i++) {
			this->data[i] = p[i];
		}

		this->capacity *= 2;		//�������+��������ĳ���

		delete(p);	//�ͷ�ԭ�����ڴ�ռ�
	}

public:
	Stack()
	{
		this->data = new T[Capacity];
		this->top = -1;
		this->capacity = Capacity;
	}

	/// <summary>
	/// ��ջ
	/// </summary>
	/// <param name="value">Ԫ��</param>
	/// <returns></returns>
	bool push(T value)
	{
		if (this->top == this->capacity - 1) {	//ջ��
			this->increaseCapacity();	//����
		}

		data[++this->top] = value;	//ջ��ָ����++�ٸ�ֵ

		return true;
	}

	/// <summary>
	/// ջ��Ԫ�س�ջ
	/// </summary>
	/// <returns>ջ��Ԫ��</returns>
	T pop()
	{
		if (this->top == -1) throw "Stack is Empty!";

		this->length--;

		return data[this->top--];
	}

	/// <summary>
	/// ��ȡջ��Ԫ��
	/// </summary>
	/// <returns></returns>
	T peek()
	{
		if (this->top == -1) throw "Stack is Empty!";
		return data[this->top];
	}

	int size()
	{
		return this->top + 1;
	}

	/// <summary>
	/// ���ջԪ��
	/// </summary>
	void clear()
	{
		this->capacity = Capacity;
		this->top = -1;
		delete[] this->data;
		this->data = nullptr;
	}

	bool empty()
	{
		return this->top == -1;
	}

	string toString()
	{
		string stack = "[";
		for (int i = 0; i < this->top + 1; i++)
		{
			stack += to_string(this->data[i]);
			if (i != this->top)
				stack += ",";
		}

		return stack + "]";
	}
};