#pragma once
#include<iostream>
using namespace std;

/// <summary>
/// �Գƾ��󣺰������Ǵ洢
/// </summary>
class SymmetricMatrix
{
	int* data;
	int n;	//ά��

	SymmetricMatrix(int n)
	{
		this->n = n;
		this->data = new int[n * (n + 1) / 2];
	}

	/// <summary>
	/// ��þ���Ԫ��
	/// </summary>
	/// <param name="i">�к�</param>
	/// <param name="j">�к�</param>
	/// <returns></returns>
	int getValue(int i, int j)
	{
		int index = i >= j ? i * (i - 1) / 2 + j - 1 : j * (j - 1) / 2 + i - 1;
		return this->data[index];
	}
};
