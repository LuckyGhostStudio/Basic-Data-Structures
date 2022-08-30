#include<iostream>
#include<string>
#include"list.hpp"
#include"linkedList.hpp"
#include"stack.hpp"
#include"queue.hpp"
#include"string.hpp"
using namespace std;

/// <summary>
/// 计算数字签名
/// </summary>
/// <param name="message">消息内容</param>
/// <param name="privateKey">私钥</param>
/// <returns>数字签名（256bit）</returns>
string sign(string message, string privateKey)
{
	string signature = "";

	return signature;
}

/// <summary>
/// 验证签名真假
/// </summary>
/// <param name="message">消息内容</param>
/// <param name="signature">数字签名</param>
/// <param name="publicKey">公钥</param>
/// <returns></returns>
bool verify(string message, string signature, string publicKey)
{
	bool result = false;

	return result;
}

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
	cout << "长度" << linkedList.length << endl;
	cout << linkedList.empty() << endl;

	cout << endl << "-----栈-----" << endl;

	Stack<int> stack = Stack<int>();

	cout << stack.empty() << endl;

	for (int i = 0; i < 10; i++)
	{
		stack.push(i);
	}

	//stack.clear();

	cout << stack.toString() << endl;

	cout << endl << "-----队列-----" << endl;

	Queue<int> queue = Queue<int>();

	for (int i = 0; i < 10; i++)
	{
		queue.push(i);
	}

	queue.push(queue.pop());
	queue.push(queue.pop());
	queue.push(queue.pop());
	queue.push(20);

	cout << queue.getCapacity() << endl;
	cout << queue.toString() << endl;

	cout << endl << "-----字符串-----" << endl;

	String a = "c";
	String s = String("abcd");

	cout << s.length() << endl;
	cout << s.compare(a) << endl;
	cout << s.subString(1,3) << endl;
	cout << s.find(a) << endl;
}