#pragma once
#include<iostream>
using namespace std;

/// <summary>
/// 对称矩阵：按下三角存储
/// </summary>
class SymmetricMatrix
{
	int* data;
	int n;	//维度

	SymmetricMatrix(int n)
	{
		this->n = n;
		this->data = new int[n * (n + 1) / 2];
	}

	/// <summary>
	/// 获得矩阵元素
	/// </summary>
	/// <param name="i">行号</param>
	/// <param name="j">列号</param>
	/// <returns></returns>
	int getValue(int i, int j)
	{
		int index = i >= j ? i * (i - 1) / 2 + j - 1 : j * (j - 1) / 2 + i - 1;
		return this->data[index];
	}
};
