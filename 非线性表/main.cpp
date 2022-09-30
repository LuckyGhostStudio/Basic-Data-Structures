#include<iostream>
#include<string>
#include<queue>
#include"BinaryTree.hpp"
#include"HuffmanTree.h"
#include"GraphAdjacencyMatrix.h"
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
	int preX, preY;	//前驱坐标
	int x, y;		//当前坐标

	Node(int step, int preX, int preY, int x, int y)
	{
		this->step = step;
		this->preX = preX;
		this->preY = preY;
		this->x = x;
		this->y = y;
	}

	void set(int step, int preX, int preY, int x, int y)
	{
		this->step = step;
		this->preX = preX;
		this->preY = preY;
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

	vector<Node> vertexes;
	queue<Node> stepQueue = queue<Node>();	//存放当前访问节点的子节点（相邻节点）
	Node startNode = Node(0, -1, -1, 1, 2);	//起点：当前步数，前驱坐标，坐标
	stepQueue.push(startNode);
	//广度优先搜索
	while (!stepQueue.empty()) {
		Node current = stepQueue.front();
		Node temp = current;
		vertexes.push_back(current);
		stepQueue.pop();

		if (map[temp.x][temp.y] == "E") {	//找到终点 回溯最短路 结束遍历
			//找E的前驱，直到起点S
			/*while (map[temp.x][temp.y] != "S") {
				for (int i = 0; i < vertexes.size(); i++)
				{
					if (vertexes[i].x == temp.x && vertexes[i].y == temp.y) {
						temp = vertexes[i];
						break;
					}
				}
				temp.x = temp.preX;
				temp.y = temp.preY;
				map[temp.x][temp.x] = "*";
			}*/
			break;
		}
		if (map[temp.x][temp.y] != "S") {
			map[current.x][current.y] = "o";	//访问当前节点
		}

		//依次遍历当前节点的子节点，并入队：上右左下相邻的节点
		if (current.y + 1 < 10 && map[current.x][current.y + 1] != "o") {
			temp.set(current.step + 1, current.x, current.y, current.x, current.y + 1);
			stepQueue.push(temp);
			vertexes.push_back(temp);
		}
		if (current.x + 1 < 10 && map[current.x + 1][current.y] != "o") {
			temp.set(current.step + 1, current.x, current.y, current.x + 1, current.y);
			stepQueue.push(temp);
			vertexes.push_back(temp);
		}
		if (current.y - 1 >= 0 && map[current.x][current.y - 1] != "o") {
			temp.set(current.step + 1, current.x, current.y, current.x, current.y - 1);
			stepQueue.push(temp);
			vertexes.push_back(temp);
		}
		if (current.x - 1 >= 0 && map[current.x - 1][current.y] != "o") {
			temp.set(current.step + 1, current.x, current.y, current.x - 1, current.y);
			stepQueue.push(temp);
			vertexes.push_back(temp);
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

void HuffmanTreeTest()
{
	int a[] = { 1,2,2,3,7 };
	HuffmanTree<int> huffman = HuffmanTree<int>(a, 5);

	huffman.print(3);
}

void GraphTest()
{
	//邻接矩阵
	int edge[5][5] = {
		{0, 1, 1, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 0, 1, 0},
		{0, 1, 1, 0, 1},
		{1, 1, 0, 1, 0}
	};

	int* edgePointer = &edge[0][0];

	string infos[5] = { "A","B","C","D","E" };	//顶点信息

	MGraph<string, int> graph = MGraph<string, int>(infos, edgePointer, 5);
	graph.print("DFS");
}

int main()
{
	//GraphTest();
	BFSTest();
}