#pragma once
#include<iostream>
#include<string>
#define Capacity 10
using namespace std;

template<class T>
class Stack
{
	T* data;
	int capacity;	//容量
	int top;		//栈顶指针

	/// <summary>
	/// 增加容量
	/// </summary>
	void increaseCapacity()
	{
		T* p = this->data;	//记录data的初始位置
		this->data = new T[this->capacity * 2];	//申请内存空间：容量翻倍

		//将原来的内存数据复制到新申请的空间
		for (int i = 0; i < this->top + 1; i++) {
			this->data[i] = p[i];
		}

		this->capacity *= 2;		//最大容量+额外申请的长度

		delete(p);	//释放原来的内存空间
	}

public:
	Stack()
	{
		this->data = new T[Capacity];
		this->top = -1;
		this->capacity = Capacity;
	}

	/// <summary>
	/// 入栈
	/// </summary>
	/// <param name="value">元素</param>
	/// <returns></returns>
	bool push(T value)
	{
		if (this->top == this->capacity - 1) {	//栈满
			this->increaseCapacity();	//扩容
		}

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

		this->length--;

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

	int size()
	{
		return this->top + 1;
	}

	/// <summary>
	/// 清空栈元素
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