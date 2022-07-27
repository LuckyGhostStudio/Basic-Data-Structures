#include<iostream>
#include<string>
#include"list.hpp"
#include"linkedList.hpp"
#include"stack.hpp"
using namespace std;



int main()
{
	cout << "-----顺序表-----" << endl;
	List<int> list = List<int>();

	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}

	List<int> list1 = List<int>(list);

	list.reverse();
	//list.clear();

	list1 = list;

	cout << list.toString() << endl;
	cout << list1.toString() << endl;

	cout << endl << "-----单链表-----" << endl;

	LinkedList<int> linkedList = LinkedList<int>();

	for (int i = 0; i < 10; i++)
	{
		linkedList.add(i);
	}

	linkedList.insert(10, 10);
	linkedList.insert(3, 30);

	linkedList.removeAt(11);
	linkedList.remove(30);

	//linkedList.clear();
	
	cout << linkedList.toString() << endl;
	cout << linkedList.getIndexOfValue(5) << endl;
	cout << linkedList.getValueOfIndex(6) << endl;
	cout << "长度" << linkedList.length << endl;
	cout << linkedList.empty();

	cout << endl << "-----栈（静态）-----" << endl;

	Stack<int> stack = Stack<int>();

	for (int i = 0; i < 10; i++)
	{
		stack.push(i);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << stack.pop() << endl;
	}
}