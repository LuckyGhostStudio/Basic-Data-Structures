#pragma once
#include<iostream>
#define MaxVertexNum 100
#define Infinity 2147483647
using namespace std;

class Vertex	//顶点
{
public:
	int index;	//顶点编号

	int inDegree, outDegree;	//入度 出度

	Vertex(int index)
	{
		this->index = index;
		this->inDegree = 0;
		this->outDegree = 0;
	}

	Vertex(int index, int inDeg, int outDeg)
	{
		this->index = index;
		this->inDegree = inDeg;
		this->outDegree = outDeg;
	}

	/// <summary>
	/// 获得顶点度数
	/// </summary>
	/// <returns></returns>
	int getDegree()
	{
		return this->inDegree + this->outDegree;
	}
};

template<class T, class W>
class Graph 
{
	Vertex vertex[MaxVertexNum];	//顶点表
	W edge[MaxVertexNum][MaxVertexNum];	//邻接矩阵 类型：权值类型

	int vertexNum, edgeNum;		//顶点数，边数

	Graph(W** edge)
	{
		this->vertexNum = MaxVertexNum;

		//初始化邻接矩阵
		for (int i = 0; i < MaxVertexNum; i++)
		{
			for (int j = 0; j < MaxVertexNum; j++)
			{
				edge[i][j] = edge[i][j];
			}
		}

		for (int i = 0; i < MaxVertexNum; i++)
		{
			this->vertex[i] = Vertex(i);	//顶点编号初始化
			this->setIndegree(this->vertex[i]);		//设置入度
			this->setOutdegree(this->vertex[i]);	//设置出度
			this->edgeNum += this->vertex[i].getDegree();	//求图的总度数
		}
		this->edgeNum /= 2;		//边数=总度数/2
	}

	/// <summary>
	/// 设置顶点入度
	/// </summary>
	/// <param name="vertex">顶点</param>
	void setIndegree(Vertex vertex)
	{
		//该顶点所在列的非0个数
		for (int i = 0; i < MaxVertexNum; i++)
		{
			if (edge[i][vertex.index] != 0 && edge[i][vertex.index] != Infinity) {	//非0 非∞
				vertex.inDegree++;	//入度++
			}
		}
	}

	/// <summary>
	/// 设置顶点出度
	/// </summary>
	/// <param name="vertex">顶点</param>
	void setOutdegree(Vertex vertex)
	{
		//该顶点所在行的非0个数
		for (int i = 0; i < MaxVertexNum; i++)
		{
			if (edge[vertex.index][i] != 0 && edge[vertex.index][i] != Infinity) {	//非0 非∞
				vertex.outDegree++;	//出度++
			}
		}
	}

	/// <summary>
	/// 获得顶点入度
	/// </summary>
	/// <param name="vertex">顶点</param>
	/// <returns>入度</returns>
	int getIndegree(Vertex vertex)
	{
		return vertex.inDegree;
	}

	/// <summary>
	/// 获得顶点出度
	/// </summary>
	/// <param name="vertex">顶点</param>
	/// <returns>出度</returns>
	int getOutdegree(Vertex vertex)
	{
		return vertex.outDegree;
	}
};
