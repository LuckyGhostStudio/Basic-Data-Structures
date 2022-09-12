#pragma once
#include<iostream>
#define MaxVertexNum 100
using namespace std;


class ArcNode	//边表结点
{
public:
	int toIndex;		//该弧指向的顶点的编号
	ArcNode* next;		//指向下一条弧的指针;

	ArcNode(int toIndex, ArcNode* next)
	{
		this->toIndex = toIndex;
		this->next = next;
	}
};

template<class T>
class Vertex	//顶点表结点
{
public:
	int index;	//顶点编号
	T value;	//顶点信息
	ArcNode* first;		//指向第一条依附于该结点的弧的指针

	Vertex(int index,T value, ArcNode* first)
	{
		this->index = index;
		this->value = value;
		this->first = first;
	}
};

template<class T>
class AGraph	//图
{
public:
	Vertex<T>* vertices;	//顶点表
	int vertexNum, arcNum;	//顶点数 弧数

	AGraph(T* vertexValues)
	{
		//初始化顶点表
		this->vertices = new T[MaxVertexNum];	
		for (int i = 0; i < MaxVertexNum; i++)
		{
			this->vertices[i] = Vertex(i, vertexValues[i], nullptr);
		}
	}
};

int main()
{

}
