#pragma once
#include<iostream>
#include<queue>
#define MaxVertexNum 100
#define Infinity 2147483647
using namespace std;

template<class T>
class Vertex	//顶点
{
public:
	int index;	//顶点编号
	T info;	//顶点信息

	int inDegree, outDegree;	//入度 出度

	bool visited = false;	//是否被访问

	Vertex(){}

	Vertex(int index)
	{
		this->index = index;
		//this->info = 0;
		this->inDegree = 0;
		this->outDegree = 0;
		this->visited = false;
	}

	Vertex(int index, T info)
	{
		this->index = index;
		this->info = info;
		this->inDegree = 0;
		this->outDegree = 0;
		this->visited = false;
	}

	Vertex(int index, T info, int inDeg, int outDeg)
	{
		this->index = index;
		this->info = info;
		this->inDegree = inDeg;
		this->outDegree = outDeg;
		this->visited = false;
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
class MGraph 
{
public:
	Vertex<T>* vertexes;		//顶点表
	W** edge;	//邻接矩阵 存放边权值信息

	int vertexNum, edgeNum;		//顶点数，边数

	MGraph(T* vertexInfos, W* edge, int vertexNum)
	{
		this->vertexNum = vertexNum;

		//edge矩阵申请内存
		this->edge = new W*[vertexNum];	//申请W*类型内存空间
		for (int i = 0; i < vertexNum; i++)
		{
			this->edge[i] = new W[vertexNum];	//申请W类型内存空间
		}

		//初始化邻接矩阵
		for (int i = 0; i < vertexNum; i++)
		{
			for (int j = 0; j < vertexNum; j++)
			{
				this->edge[i][j] = edge[i * vertexNum + j];
			}
		}

		this->vertexes = new Vertex<T>[vertexNum];	//顶点数组申请内存

		for (int i = 0; i < vertexNum; i++)
		{
			this->vertexes[i] = Vertex<T>(i, vertexInfos[i]);	//顶点初始化(编号，信息)
			this->setIndegree(this->vertexes[i]);		//设置入度
			this->setOutdegree(this->vertexes[i]);	//设置出度
			this->edgeNum += this->vertexes[i].getDegree();	//求图的总度数
		}
		this->edgeNum /= 2;		//边数=总度数/2

		/*for (int i = 0; i < vertexNum; i++)
		{
			visit(this->vertexes[i]);
		}*/
	}

	/// <summary>
	/// 边i->j是否存在
	/// </summary>
	/// <param name="i">前顶点</param>
	/// <param name="j">后顶点</param>
	/// <returns></returns>
	bool edgeExist(int i, int j)
	{
		return this->edge[i][j] != 0 && this->edge[i][j] != Infinity;	//非0 且 非无穷
	}

	/// <summary>
	/// 设置顶点入度
	/// </summary>
	/// <param name="vertex">顶点</param>
	void setIndegree(Vertex<T> vertex)
	{
		//该顶点所在列的非0个数
		for (int i = 0; i < this->vertexNum; i++)
		{
			if (edgeExist(i, vertex.index)) {	//边i->vertex.index存在
				vertex.inDegree++;	//入度++
			}
		}
	}

	/// <summary>
	/// 设置顶点出度
	/// </summary>
	/// <param name="vertex">顶点</param>
	void setOutdegree(Vertex<T> vertex)
	{
		//该顶点所在行的非0个数
		for (int i = 0; i < this->vertexNum; i++)
		{
			if (edgeExist(vertex.index, i)) {	//边vertex.index->i存在
				vertex.outDegree++;	//出度++
			}
		}
	}

	/// <summary>
	/// 获得顶点入度
	/// </summary>
	/// <param name="vertex">顶点</param>
	/// <returns>入度</returns>
	int getIndegree(Vertex<T> vertex)
	{
		return vertex.inDegree;
	}

	/// <summary>
	/// 获得顶点出度
	/// </summary>
	/// <param name="vertex">顶点</param>
	/// <returns>出度</returns>
	int getOutdegree(Vertex<T> vertex)
	{
		return vertex.outDegree;
	}

	/// <summary>
	/// 返回vertex的第一个邻接点
	/// </summary>
	/// <param name="vertex">顶点</param>
	/// <returns></returns>
	Vertex<T> firstNeighbor(Vertex<T> vertex)
	{
		for (int i = 0; i < this->vertexNum; i++)
		{
			//找到第一个权值存在的边：当前顶点行 边vertex.index->i存在
			if (edgeExist(vertex.index, i)) {
				return this->vertexes[i];		//第i号顶点
			}
		}

		return Vertex<T>(-1);	//没找到
	}

	/// <summary>
	/// 返回vertex的除v之外的下一个邻接点
	/// </summary>
	/// <param name="vertex">顶点</param>
	/// <param name="v"></param>
	/// <returns></returns>
	Vertex<T> nextNeighbor(Vertex<T> vertex, Vertex<T> v)
	{
		if (v.index == this->vertexNum - 1) return Vertex<T>(-1);		//v是最后一个邻接点
		//从v的编号开始找
		for (int i = v.index + 1; i < this->vertexNum; i++)
		{
			//边vertex.index->i存在
			if (edgeExist(vertex.index, i)) {
				return this->vertexes[i];		//第i号顶点
			}
		}

		return Vertex<T>(-1);	//没找到
	}

	void visit(Vertex<T>& vertex)
	{
		cout << vertex.index << " : " << vertex.info << this->vertexes[vertex.index].visited << endl;
		this->vertexes[vertex.index].visited = true;	//已访问
	}

	/// <summary>
	/// 遍历图
	/// </summary>
	/// <param name="mode">遍历方式：BFS/DFS</param>
	void Traverse(string mode)
	{
		for (int i = 0; i < this->vertexNum; i++)
		{
			this->vertexes[i].visited = false;	//初始化访问标志
		}

		//遍历每个连通分量
		for (int i = 0; i < this->vertexNum; i++)
		{
			if (!this->vertexes[i].visited) {
				if (mode == "BFS") {
					this->BFS(this->vertexes[i]);	//广度优先
				}
				else {
					this->DFS(this->vertexes[i]);	//深度优先
				}
			}
		}
	}

	/// <summary>
	/// 从顶点start开始广度优先遍历图的一个连通分量
	/// </summary>
	/// <param name="startVertex">开始顶点</param>
	void BFS(Vertex<T> startVertex)
	{
		queue<Vertex<T>> queueVertex = queue<Vertex<T>>();
		queueVertex.push(this->vertexes[startVertex.index]);	//访问开始顶点

		while (!queueVertex.empty()) {
			Vertex<T> tempVertex = queueVertex.front();
			queueVertex.pop();

			if (!this->vertexes[tempVertex.index].visited) {	//未访问
				visit(this->vertexes[tempVertex.index]);		//访问队头顶点
			}

			//查找tempVertex的所有邻接点
			for (Vertex<T> v = firstNeighbor(tempVertex); v.index >= 0; v = nextNeighbor(tempVertex, v))
			{
				if(!this->vertexes[v.index].visited)	//未访问
					queueVertex.push(this->vertexes[v.index]);	//邻接点入队
			}
		}
	}

	/// <summary>
	/// 从顶点start开始深度优先遍历图的一个连通分量
	/// </summary>
	/// <param name="startVertex"></param>
	void DFS(Vertex<T> startVertex)
	{
		visit(startVertex);

		for (Vertex<T> v = firstNeighbor(startVertex); v.index >= 0; v = nextNeighbor(startVertex, v)) {
			if (!this->vertexes[v.index].visited) {
				DFS(v);
			}
		}
	}

	/// <summary>
	/// 输出遍历序列
	/// </summary>
	/// <param name="mode">遍历模式：DFS/BFS</param>
	void print(string mode)
	{
		Traverse(mode);
	}
};
