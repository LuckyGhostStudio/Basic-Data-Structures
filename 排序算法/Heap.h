#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Heap	//�ѣ���
{
public:
	vector<T> data;
	int size;

	Heap()
	{
		this->data = vector<T>();
		this->size = this->data.size();
	}

	Heap(T array[], int length)
	{
		this->data = vector<T>();
		this->size = length;
		for (int i = 0; i < length; i++)
		{
			this->data.push_back(array[i]);
		}
		BuildMaxHeap(this->data, this->data.size());
	}

	/// <summary>
	/// ���������
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="length">����</param>
	static void BuildMaxHeap(vector<T>& array, int length)
	{
		//�������з�֧���
		for (int i = length / 2 - 1; i >= 0; i--)
		{
			HeadAdjust(array, i, length);	//������iΪ��������
			//for (int i = 0; i < 8; i++)
			//{
			//	cout << array[i] << " ";
			//}
			//cout << "i=" << i << endl;
		}
	}

	/// <summary>
	/// ���������
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="length">����</param>
	static void BuildMaxHeap(T array[], int length)
	{
		//�������з�֧���
		for (int i = length / 2 - 1; i >= 0; i--)
		{
			HeadAdjust(array, i, length);	//������iΪ��������
		}
	}

	/// <summary>
	/// ���������
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="k">�������</param>
	/// <param name="length">����</param>
	static void HeadAdjust(vector<T>& array, int k, int length)
	{
		T temp = array[k];
		for (int i = 2 * k + 1; i < length; i = 2 * i + 1)	//��k�����ӿ�ʼ ÿ���ƶ����µ�k������
		{
			if (i < length - 1 && array[i] < array[i + 1]) {	//i��������ֵ� k������С���Һ���
				i++;	//iָ��k���Һ���
			}
			if (temp >= array[i]) break;	//k��ֵ���ڸ���ĺ��� k��� ����
			else {	//���Ӹ���
				array[k] = array[i];	//�Һ����ƶ������ڵ�
				k = i;		//����ɸѡ
			}
		}
		array[k] = temp;
	}

	/// <summary>
	/// ���������
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="k">�������</param>
	/// <param name="length">����</param>
	static void HeadAdjust(T array[], int k, int length)
	{
		T temp = array[k];
		for (int i = 2 * k + 1; i < length; i = 2 * i + 1)	//��k�����ӿ�ʼ ÿ���ƶ����µ�k������
		{
			if (i < length - 1 && array[i] < array[i + 1]) {	//i��������ֵ� k������С���Һ���
				i++;	//iָ��k���Һ���
			}
			if (temp >= array[i]) break;	//k��ֵ���ڸ���ĺ��� k��� ����
			else {	//���Ӹ���
				array[k] = array[i];	//�ƶ������ڵ�
				k = i;		//����ɸѡ
			}
		}
		array[k] = temp;
	}

	void sort()
	{
		for (int i = size - 1; i > 0; i--)
		{
			T temp = this->data[i];
			this->data[i] = this->data[0];
			this->data[0] = temp;

			HeadAdjust(this->data, 0, i);
		}
	}

	T& operator[](int i)
	{
		return this->data[i];
	}

	/// <summary>
	/// ����Ԫ��
	/// </summary>
	/// <param name="value">����Ԫ��</param>
	void put(T value)
	{
		this->data.push_back(value);
		this->size++;

		int current = this->data.size() - 1;	//��ǰ�����
		int parent = (current - 1) / 2;			//��ǰ��㸸�����

		while (this->data[current] > this->data[parent]) {	//��ǰ���ֵ���ڸ����
			//��ǰ����븸��㽻��
			T temp = this->data[parent];
			this->data[parent] = this->data[current];
			this->data[current] = temp;

			current = parent;	//��ǰ���ָ������
			parent = (current - 1) / 2;	//�����ָ������
		}
	}

	T get(int i)
	{
		return this->data[i];
	}

	/// <summary>
	/// �������
	/// </summary>
	/// <param name="i">��ǰ�����</param>
	/// <returns>����</returns>
	T getLeftChild(int i)
	{
		return this->data[2 * i + 1];
	}

	/// <summary>
	/// ����Һ���
	/// </summary>
	/// <param name="i">��ǰ�����</param>
	/// <returns>�Һ���</returns>
	T getRightChild(int i)
	{
		return this->data[2 * i + 2];
	}

	/// <summary>
	/// ��ø����
	/// </summary>
	/// <param name="i">��ǰ�����</param>
	/// <returns>�����</returns>
	T getParent(int i)
	{
		return i != 0 ? this->data[(i - 1) / 2] : -1;
	}
};