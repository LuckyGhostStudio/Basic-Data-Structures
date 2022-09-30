#pragma once
#include<iostream>
#include<string>
#define Length 83	//���� �ɱ�ʾΪ4k+3

using namespace std;

class HashTable
{
public:
	string values[Length];	//ֵ
	int length;				//����

	HashTable()
	{
		this->length = Length;

		for (int i = 0; i < this->length; i++)
		{
			values[i] = "";
		}
	}

	/// <summary>
	/// ��ɢ�е�ַ
	/// </summary>
	/// <param name="key">��</param>
	/// <returns>ɢ�е�ַ</returns>
	int hash(int key)
	{
		return key % this->length;
	}

	void put(int key, string value)
	{
		int address = hash(key);	//��ɢ�е�ַ

		for (int i = 0; i < this->length; i++)
		{
			if (this->values[address] == "")	//�ҵ���λ
			{
				break;
			}
			address = (hash(key) + i) % this->length;	//����̽��
		}

		this->values[address] = value;
	}
};
