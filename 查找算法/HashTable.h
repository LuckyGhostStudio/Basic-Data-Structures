#pragma once
#include<iostream>
#include<string>
#define Length 83	//素数 可表示为4k+3

using namespace std;

class HashTable
{
public:
	string values[Length];	//值
	int length;				//长度

	HashTable()
	{
		this->length = Length;

		for (int i = 0; i < this->length; i++)
		{
			values[i] = "";
		}
	}

	/// <summary>
	/// 求散列地址
	/// </summary>
	/// <param name="key">键</param>
	/// <returns>散列地址</returns>
	int hash(int key)
	{
		return key % this->length;
	}

	void put(int key, string value)
	{
		int address = hash(key);	//求散列地址

		for (int i = 0; i < this->length; i++)
		{
			if (this->values[address] == "")	//找到空位
			{
				break;
			}
			address = (hash(key) + i) % this->length;	//线性探测
		}

		this->values[address] = value;
	}
};
