#pragma once
#include<iostream>
#define Capacity 10
using namespace std;

template<class T>
class Stack
{
	T data[Capacity];
	int top;		//栈顶指针

public:
	
	Stack()
	{
		this->top = -1;
	}

	/// <summary>
	/// 入栈
	/// </summary>
	/// <param name="value">元素</param>
	/// <returns></returns>
	bool push(T value)
	{
		if (this->top == Capacity - 1) return false;

		data[++this->top] = value;	//栈顶指针先++再赋值

		return true;
	}

	/// <summary>
	/// 栈顶元素出栈
	/// </summary>
	/// <returns>栈顶元素</returns>
	T pop()
	{
		if (this->top == -1) throw "Stack is Empty!";

		return data[this->top--];
	}

	/// <summary>
	/// 获取栈顶元素
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