#pragma once
#include<iostream>
#define Capacity 10
using namespace std;

template<class T>
class Stack
{
	T data[Capacity];
	int top;		//ջ��ָ��

public:
	
	Stack()
	{
		this->top = -1;
	}

	/// <summary>
	/// ��ջ
	/// </summary>
	/// <param name="value">Ԫ��</param>
	/// <returns></returns>
	bool push(T value)
	{
		if (this->top == Capacity - 1) return false;

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

	bool empty()
	{
		return this->top == -1;
	}
};