#pragma once
#include<iostream>
#include<queue>
#define MaxVertexNum 100
#define Infinity 2147483647
using namespace std;

template<class T>
class Vertex	//����
{
public:
	int index;	//������
	T info;	//������Ϣ

	int inDegree, outDegree;	//��� ����

	bool visited = false;	//�Ƿ񱻷���

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
	/// ��ö������
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
	Vertex<T>* vertexes;		//�����
	W** edge;	//�ڽӾ��� ��ű�Ȩֵ��Ϣ

	int vertexNum, edgeNum;		//������������

	MGraph(T* vertexInfos, W* edge, int vertexNum)
	{
		this->vertexNum = vertexNum;

		//edge���������ڴ�
		this->edge = new W*[vertexNum];	//����W*�����ڴ�ռ�
		for (int i = 0; i < vertexNum; i++)
		{
			this->edge[i] = new W[vertexNum];	//����W�����ڴ�ռ�
		}

		//��ʼ���ڽӾ���
		for (int i = 0; i < vertexNum; i++)
		{
			for (int j = 0; j < vertexNum; j++)
			{
				this->edge[i][j] = edge[i * vertexNum + j];
			}
		}

		this->vertexes = new Vertex<T>[vertexNum];	//�������������ڴ�

		for (int i = 0; i < vertexNum; i++)
		{
			this->vertexes[i] = Vertex<T>(i, vertexInfos[i]);	//�����ʼ��(��ţ���Ϣ)
			this->setIndegree(this->vertexes[i]);		//�������
			this->setOutdegree(this->vertexes[i]);	//���ó���
			this->edgeNum += this->vertexes[i].getDegree();	//��ͼ���ܶ���
		}
		this->edgeNum /= 2;		//����=�ܶ���/2

		/*for (int i = 0; i < vertexNum; i++)
		{
			visit(this->vertexes[i]);
		}*/
	}

	/// <summary>
	/// ��i->j�Ƿ����
	/// </summary>
	/// <param name="i">ǰ����</param>
	/// <param name="j">�󶥵�</param>
	/// <returns></returns>
	bool edgeExist(int i, int j)
	{
		return this->edge[i][j] != 0 && this->edge[i][j] != Infinity;	//��0 �� ������
	}

	/// <summary>
	/// ���ö������
	/// </summary>
	/// <param name="vertex">����</param>
	void setIndegree(Vertex<T> vertex)
	{
		//�ö��������еķ�0����
		for (int i = 0; i < this->vertexNum; i++)
		{
			if (edgeExist(i, vertex.index)) {	//��i->vertex.index����
				vertex.inDegree++;	//���++
			}
		}
	}

	/// <summary>
	/// ���ö������
	/// </summary>
	/// <param name="vertex">����</param>
	void setOutdegree(Vertex<T> vertex)
	{
		//�ö��������еķ�0����
		for (int i = 0; i < this->vertexNum; i++)
		{
			if (edgeExist(vertex.index, i)) {	//��vertex.index->i����
				vertex.outDegree++;	//����++
			}
		}
	}

	/// <summary>
	/// ��ö������
	/// </summary>
	/// <param name="vertex">����</param>
	/// <returns>���</returns>
	int getIndegree(Vertex<T> vertex)
	{
		return vertex.inDegree;
	}

	/// <summary>
	/// ��ö������
	/// </summary>
	/// <param name="vertex">����</param>
	/// <returns>����</returns>
	int getOutdegree(Vertex<T> vertex)
	{
		return vertex.outDegree;
	}

	/// <summary>
	/// ����vertex�ĵ�һ���ڽӵ�
	/// </summary>
	/// <param name="vertex">����</param>
	/// <returns></returns>
	Vertex<T> firstNeighbor(Vertex<T> vertex)
	{
		for (int i = 0; i < this->vertexNum; i++)
		{
			//�ҵ���һ��Ȩֵ���ڵıߣ���ǰ������ ��vertex.index->i����
			if (edgeExist(vertex.index, i)) {
				return this->vertexes[i];		//��i�Ŷ���
			}
		}

		return Vertex<T>(-1);	//û�ҵ�
	}

	/// <summary>
	/// ����vertex�ĳ�v֮�����һ���ڽӵ�
	/// </summary>
	/// <param name="vertex">����</param>
	/// <param name="v"></param>
	/// <returns></returns>
	Vertex<T> nextNeighbor(Vertex<T> vertex, Vertex<T> v)
	{
		if (v.index == this->vertexNum - 1) return Vertex<T>(-1);		//v�����һ���ڽӵ�
		//��v�ı�ſ�ʼ��
		for (int i = v.index + 1; i < this->vertexNum; i++)
		{
			//��vertex.index->i����
			if (edgeExist(vertex.index, i)) {
				return this->vertexes[i];		//��i�Ŷ���
			}
		}

		return Vertex<T>(-1);	//û�ҵ�
	}

	void visit(Vertex<T>& vertex)
	{
		cout << vertex.index << " : " << vertex.info << this->vertexes[vertex.index].visited << endl;
		this->vertexes[vertex.index].visited = true;	//�ѷ���
	}

	/// <summary>
	/// ����ͼ
	/// </summary>
	/// <param name="mode">������ʽ��BFS/DFS</param>
	void Traverse(string mode)
	{
		for (int i = 0; i < this->vertexNum; i++)
		{
			this->vertexes[i].visited = false;	//��ʼ�����ʱ�־
		}

		//����ÿ����ͨ����
		for (int i = 0; i < this->vertexNum; i++)
		{
			if (!this->vertexes[i].visited) {
				if (mode == "BFS") {
					this->BFS(this->vertexes[i]);	//�������
				}
				else {
					this->DFS(this->vertexes[i]);	//�������
				}
			}
		}
	}

	/// <summary>
	/// �Ӷ���start��ʼ������ȱ���ͼ��һ����ͨ����
	/// </summary>
	/// <param name="startVertex">��ʼ����</param>
	void BFS(Vertex<T> startVertex)
	{
		queue<Vertex<T>> queueVertex = queue<Vertex<T>>();
		queueVertex.push(this->vertexes[startVertex.index]);	//���ʿ�ʼ����

		while (!queueVertex.empty()) {
			Vertex<T> tempVertex = queueVertex.front();
			queueVertex.pop();

			if (!this->vertexes[tempVertex.index].visited) {	//δ����
				visit(this->vertexes[tempVertex.index]);		//���ʶ�ͷ����
			}

			//����tempVertex�������ڽӵ�
			for (Vertex<T> v = firstNeighbor(tempVertex); v.index >= 0; v = nextNeighbor(tempVertex, v))
			{
				if(!this->vertexes[v.index].visited)	//δ����
					queueVertex.push(this->vertexes[v.index]);	//�ڽӵ����
			}
		}
	}

	/// <summary>
	/// �Ӷ���start��ʼ������ȱ���ͼ��һ����ͨ����
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
	/// �����������
	/// </summary>
	/// <param name="mode">����ģʽ��DFS/BFS</param>
	void print(string mode)
	{
		Traverse(mode);
	}
};
