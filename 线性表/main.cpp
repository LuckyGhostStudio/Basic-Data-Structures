#include<iostream>
#include"list.hpp"
using namespace std;

int main()
{
	List<int> list = List<int>();

	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}

	list.insert(2, 100);
	list.removeAt(5);

	cout << "ָ��������ֵ��" << list.getValueOfIndex(2) << endl;
	cout << "ָ��ֵ��������" << list.getIndexOfValue(100) << endl;

	list.remove(100);


	cout << "����" << list.length << endl;

	for (int i = 0; i < list.length; i++)
	{
		cout << list.getValueOfIndex(i) << endl;
	}
}