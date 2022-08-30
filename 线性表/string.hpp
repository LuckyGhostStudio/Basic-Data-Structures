#pragma once
#include<iostream>
using namespace std;

/// <summary>
/// �ַ���
/// </summary>
class String
{
	char data[255];
	int len;

public:
	String(const char* value)
	{
		this->len = 0;

		while(value[this->len]!='\0')
		{
			this->data[this->len] = value[this->len];
			this->len++;
		}
	}

	/// <summary>
	/// ����[]�����
	/// </summary>
	/// <param name="i">����</param>
	/// <returns>����λ�ö�Ӧ�ַ�</returns>
	char& operator[](int i)
	{
		if (i < 0) return this->data[0];
		if (i >= this->len) return this->data[this->len - 1];
		return this->data[i];
	}

	/// <summary>
	/// ����<<�����
	/// </summary>
	/// <param name="output">���������</param>
	/// <param name="str">Ҫ������ַ�������</param>
	/// <returns>���������</returns>
	friend ostream& operator<<(ostream& output,const String& str)
	{
		for (int i = 0; i < str.len; i++)
		{
			output << str.data[i];
		}

		return output;
	}

	/// <summary>
	/// ���ش�pos��ʼcount���ַ�
	/// </summary>
	/// <param name="pos">��ʼλ��</param>
	/// <param name="count">�ַ�����</param>
	/// <returns></returns>
	String subString(int pos, int count)
	{
		if (pos + count - 1 > this->len) {
			throw "�������Ϸ���";
		}

		String subStr = "";

		for (int i = pos; i < pos + count; i++)
		{
			subStr.data[i - pos] = this->data[i];
			subStr.len++;
		}

		return subStr;
	}

	/// <summary>
	/// �Ƚ������ַ�����С��>0:this>str =0:this=str <0:this<str��
	/// </summary>
	/// <param name="str1"></param>
	/// <param name="str2"></param>
	/// <returns></returns>
	int compare(String str)
	{
		//�����Ƚ��ַ���С
		for (int i = 0; i < this->len && i < str.length(); i++)
		{
			if (this->data[i] != str[i]) {
				return this->data[i] - str[i];
			}
		}

		return this->len - str.length();	//�ַ������ �����ȱȽ�
	}

	/// <summary>
	/// ���Ӵ���λ�ã�����������
	/// </summary>
	/// <param name="str"></param>
	/// <returns></returns>
	int find(String str)
	{
		int pos = 0;	//�Ӵ�λ��
		int j = 0;

		for (int i = 0; i < this->len && j < str.length(); )
		{
			if (this->data[i] == str[j]) {
				i++;
				j++;
			}
			else {
				pos++;
				i = pos;
				j = 0;
			}
		}

		if (j >= str.length()) {
			return pos;
		}
		return -1;
	}

	int length()
	{
		return this->len;
	}

	void clear()
	{
		this->len = 0;
	}
};