#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Heap	//堆：大顶
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
	/// 建立大根堆
	/// </summary>
	/// <param name="array">待排序列</param>
	/// <param name="length">长度</param>
	static void BuildMaxHeap(vector<T>& array, int length)
	{
		//遍历所有分支结点
		for (int i = length / 2 - 1; i >= 0; i--)
		{
			HeadAdjust(array, i, length);	//调整以i为根的子树
			//for (int i = 0; i < 8; i++)
			//{
			//	cout << array[i] << " ";
			//}
			//cout << "i=" << i << endl;
		}
	}

	/// <summary>
	/// 建立大根堆
	/// </summary>
	/// <param name="array">待排序列</param>
	/// <param name="length">长度</param>
	static void BuildMaxHeap(T array[], int length)
	{
		//遍历所有分支结点
		for (int i = length / 2 - 1; i >= 0; i--)
		{
			HeadAdjust(array, i, length);	//调整以i为根的子树
		}
	}

	/// <summary>
	/// 调整大根堆
	/// </summary>
	/// <param name="array">待排序列</param>
	/// <param name="k">根结点编号</param>
	/// <param name="length">长度</param>
	static void HeadAdjust(vector<T>& array, int k, int length)
	{
		T temp = array[k];
		for (int i = 2 * k + 1; i < length; i = 2 * i + 1)	//从k的左孩子开始 每次移动到新的k的左孩子
		{
			if (i < length - 1 && array[i] < array[i + 1]) {	//i结点有右兄弟 k的左孩子小于右孩子
				i++;	//i指向k的右孩子
			}
			if (temp >= array[i]) break;	//k的值大于更大的孩子 k最大 结束
			else {	//孩子更大
				array[k] = array[i];	//右孩子移动到根节点
				k = i;		//向下筛选
			}
		}
		array[k] = temp;
	}

	/// <summary>
	/// 调整大根堆
	/// </summary>
	/// <param name="array">待排序列</param>
	/// <param name="k">根结点编号</param>
	/// <param name="length">长度</param>
	static void HeadAdjust(T array[], int k, int length)
	{
		T temp = array[k];
		for (int i = 2 * k + 1; i < length; i = 2 * i + 1)	//从k的左孩子开始 每次移动到新的k的左孩子
		{
			if (i < length - 1 && array[i] < array[i + 1]) {	//i结点有右兄弟 k的左孩子小于右孩子
				i++;	//i指向k的右孩子
			}
			if (temp >= array[i]) break;	//k的值大于更大的孩子 k最大 结束
			else {	//孩子更大
				array[k] = array[i];	//移动到根节点
				k = i;		//向下筛选
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
	/// 插入元素
	/// </summary>
	/// <param name="value">待插元素</param>
	void put(T value)
	{
		this->data.push_back(value);
		this->size++;

		int current = this->data.size() - 1;	//当前结点编号
		int parent = (current - 1) / 2;			//当前结点父结点编号

		while (this->data[current] > this->data[parent]) {	//当前结点值大于父结点
			//当前结点与父结点交换
			T temp = this->data[parent];
			this->data[parent] = this->data[current];
			this->data[current] = temp;

			current = parent;	//当前结点指针上移
			parent = (current - 1) / 2;	//父结点指针上移
		}
	}

	T get(int i)
	{
		return this->data[i];
	}

	/// <summary>
	/// 获得左孩子
	/// </summary>
	/// <param name="i">当前结点编号</param>
	/// <returns>左孩子</returns>
	T getLeftChild(int i)
	{
		return this->data[2 * i + 1];
	}

	/// <summary>
	/// 获得右孩子
	/// </summary>
	/// <param name="i">当前结点编号</param>
	/// <returns>右孩子</returns>
	T getRightChild(int i)
	{
		return this->data[2 * i + 2];
	}

	/// <summary>
	/// 获得父结点
	/// </summary>
	/// <param name="i">当前结点编号</param>
	/// <returns>父结点</returns>
	T getParent(int i)
	{
		return i != 0 ? this->data[(i - 1) / 2] : -1;
	}
};