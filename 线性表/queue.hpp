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
	int front, rear;	//��ͷָ�룬��βָ��
	int capacity;

	/// <summary>
	/// ��������
	/// </summary>
	void increaseCapacity()
	{
		T* p = this->data;	//��¼data�ĳ�ʼλ��
		this->data = new T[this->capacity * 2];	//�����ڴ�ռ䣺��������

		//��ԭ�����ڴ����ݸ��Ƶ�������Ŀռ�
		for (int i = this->front; i != this->rear; i = (i + 1) % this->capacity)
		{
			this->data[i] = p[i];
		}

		this->capacity *= 2;		//�������+��������ĳ���

		delete(p);	//�ͷ�ԭ�����ڴ�ռ�
	}

public:
	Queue()
	{
		this->data = new T[Capacity];
		this->front = this->rear = 0;
		this->capacity = Capacity;
	}

	/// <summary>
	/// ��β���
	/// </summary>
	/// <typeparam name="T">���Ԫ��</typeparam>
	void push(T value)
	{
		if ((this->rear + 1) % this->capacity == this->front) {	//��������βָ��+1=ͷָ�룩
			increaseCapacity();		//����
		}
		this->data[this->rear] = value;	//��β���
		this->rear = (this->rear + 1) % this->capacity;		//��βָ����� ������ȡ�ࣨʵ��ѭ�����У�
	}

	/// <summary>
	/// ��ͷԪ�س���
	/// </summary>
	T pop()
	{
		if (this->front == this->rear) {
			throw "Queue is empty!";
		}

		int value = this->data[this->front];	//��ö�ͷԪ��
		this->front = (this->front + 1) % this->capacity;	//ͷָ��ѭ������

		return value;
	}

	/// <summary>
	/// ��ö�ͷԪ��
	/// </summary>
	/// <returns>��ͷԪ��</returns>
	T getFrontValue()
	{
		if (this->front == this->rear) {
			throw "Queue is empty!";
		}

		return this->data[this->front];	//��ö�ͷԪ��
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