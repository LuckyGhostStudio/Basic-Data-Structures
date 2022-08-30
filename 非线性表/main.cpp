#include<iostream>
#include<string>
#include<queue>
#include"BinaryTree.hpp"
#include"HuffmanTree.h"
using namespace std;

void treeTest()
{
	BinarySearchTree<int> tree = BinarySearchTree<int>();

	for (int i = 0; i < 10; i++)
	{
		tree.insert(i);
	}

	tree.print(2);
}

class Node
{
public:
	int step;
	int x, y;

	Node(int step, int x, int y)
	{
		this->step = step;
		this->x = x;
		this->y = y;
	}

	void set(int step, int x, int y)
	{
		this->step = step;
		this->x = x;
		this->y = y;
	}
};

void BFSTest()
{
	string map[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = " ";
		}
	}

	map[1][2] = "S";	//起点
	map[4][7] = "E";	//终点

	queue<Node> stepQueue = queue<Node>();	//存放当前访问节点的子节点（相邻节点）
	Node node = Node(0, 1, 2);	//当前步数，坐标
	stepQueue.push(node);
	//广度优先搜索
	while (!stepQueue.empty()) {
		Node current = stepQueue.front();
		Node temp = current;
		stepQueue.pop();

		if (map[temp.x][temp.y] == "E") break;	//找到终点 结束遍历
		if (map[temp.x][temp.y] != "S") {
			map[current.x][current.y] = "o";	//访问当前节点
		}

		//依次遍历当前节点的子节点，并入队：上右左下相邻的节点
		if (current.y + 1 < 10 && map[current.x][current.y + 1] != "o") {
			temp.set(current.step + 1, current.x, current.y + 1);
			stepQueue.push(temp);
		}
		if (current.x + 1 < 10 && map[current.x + 1][current.y] != "o") {
			temp.set(current.step + 1, current.x + 1, current.y);
			stepQueue.push(temp);
		}
		if (current.y - 1 >= 0 && map[current.x][current.y - 1] != "o") {
			temp.set(current.step + 1, current.x, current.y - 1);
			stepQueue.push(temp);
		}
		if (current.x - 1 >= 0 && map[current.x - 1][current.y] != "o") {
			temp.set(current.step + 1, current.x - 1, current.y);
			stepQueue.push(temp);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << " +---+---+---+---+---+---+---+---+---+---+" << endl;
		for (int j = 0; j < 10; j++)
		{
			//cout << "--" << endl;
			cout << " | " << map[i][j];
			if (j == 9) {
				cout << " |";
			}
		}
		cout << endl;
		if (i == 9) {
			cout << " +---+---+---+---+---+---+---+---+---+---+" << endl;
		}
	}
}

int main()
{
	int a[] = { 1,2,2,3,7 };
	HuffmanTree<int> huffman = HuffmanTree<int>(a,5);

	huffman.print(3);
}