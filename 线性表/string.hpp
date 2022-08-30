#pragma once
#include<iostream>
using namespace std;

/// <summary>
/// 字符串
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
	/// 重载[]运算符
	/// </summary>
	/// <param name="i">索引</param>
	/// <returns>索引位置对应字符</returns>
	char& operator[](int i)
	{
		if (i < 0) return this->data[0];
		if (i >= this->len) return this->data[this->len - 1];
		return this->data[i];
	}

	/// <summary>
	/// 重载<<运算符
	/// </summary>
	/// <param name="output">输出流对象</param>
	/// <param name="str">要输出的字符串对象</param>
	/// <returns>输出流对象</returns>
	friend ostream& operator<<(ostream& output,const String& str)
	{
		for (int i = 0; i < str.len; i++)
		{
			output << str.data[i];
		}

		return output;
	}

	/// <summary>
	/// 返回从pos开始count个字符
	/// </summary>
	/// <param name="pos">起始位置</param>
	/// <param name="count">字符个数</param>
	/// <returns></returns>
	String subString(int pos, int count)
	{
		if (pos + count - 1 > this->len) {
			throw "索引不合法！";
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
	/// 比较两个字符串大小（>0:this>str =0:this=str <0:this<str）
	/// </summary>
	/// <param name="str1"></param>
	/// <param name="str2"></param>
	/// <returns></returns>
	int compare(String str)
	{
		//挨个比较字符大小
		for (int i = 0; i < this->len && i < str.length(); i++)
		{
			if (this->data[i] != str[i]) {
				return this->data[i] - str[i];
			}
		}

		return this->len - str.length();	//字符都相等 按长度比较
	}

	/// <summary>
	/// 求子串的位置：从左向右找
	/// </summary>
	/// <param name="str"></param>
	/// <returns></returns>
	int find(String str)
	{
		int pos = 0;	//子串位置
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