#pragma once
#include<iostream>
#include<string>
#include<queue>
#define Capacity 10
using namespace std;

template<class T>
class Queue
{
	T* data;
	int front, rear;	//队头指针，队尾指针
	int capacity;

	/// <summary>
	/// 增加容量
	/// </summary>
	void increaseCapacity()
	{
		T* p = this->data;	//记录data的初始位置
		this->data = new T[this->capacity * 2];	//申请内存空间：容量翻倍

		//将原来的内存数据复制到新申请的空间
		for (int i = this->front; i != this->rear; i = (i + 1) % this->capacity)
		{
			this->data[i] = p[i];
		}

		this->capacity *= 2;		//最大容量+额外申请的长度

		delete(p);	//释放原来的内存空间
	}

public:
	Queue()
	{
		this->data = new T[Capacity];
		this->front = this->rear = 0;
		this->capacity = Capacity;
	}

	/// <summary>
	/// 队尾入队
	/// </summary>
	/// <typeparam name="T">入队元素</typeparam>
	void push(T value)
	{
		if ((this->rear + 1) % this->capacity == this->front) {	//队列满（尾指针+1=头指针）
			increaseCapacity();		//扩容
		}
		this->data[this->rear] = value;	//队尾入队
		this->rear = (this->rear + 1) % this->capacity;		//队尾指针后移 对容量取余（实现循环队列）
	}

	/// <summary>
	/// 队头元素出队
	/// </summary>
	T pop()
	{
		if (this->front == this->rear) {
			throw "Queue is empty!";
		}

		int value = this->data[this->front];	//获得队头元素
		this->front = (this->front + 1) % this->capacity;	//头指针循环后移

		return value;
	}

	/// <summary>
	/// 获得队头元素
	/// </summary>
	/// <returns>队头元素</returns>
	T getFrontValue()
	{
		if (this->front == this->rear) {
			throw "Queue is empty!";
		}

		return this->data[this->front];	//获得队头元素
	}

	int getCapacity()
	{
		return this->capacity;
	}

	int size()
	{
		return (this->rear + this->capacity - this->front) % this->capacity;
	}

	void clear()
	{
		this->capacity = Capacity;
		this->front = this->rear = 0;
		delete[] this->data;
		this->data = nullptr;
	}

	bool empty()
	{
		return this->front == this->rear;
	}

	string toString()
	{
		string queue = "[";

		for (int i = this->front; i!=this->rear; i = (i + 1) % this->capacity)
		{
			queue += to_string(this->data[i]);
			if (i != this->rear - 1)
				queue += ",";
		}

		return queue + "]";
	}
};