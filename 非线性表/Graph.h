#pragma once
#include<iostream>
#define MaxVertexNum 100
#define Infinity 2147483647
using namespace std;

class Vertex	//����
{
public:
	int index;	//������

	int inDegree, outDegree;	//��� ����

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
	/// ��ö������
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
	Vertex vertex[MaxVertexNum];	//�����
	W edge[MaxVertexNum][MaxVertexNum];	//�ڽӾ��� ���ͣ�Ȩֵ����

	int vertexNum, edgeNum;		//������������

	Graph(W** edge)
	{
		this->vertexNum = MaxVertexNum;

		//��ʼ���ڽӾ���
		for (int i = 0; i < MaxVertexNum; i++)
		{
			for (int j = 0; j < MaxVertexNum; j++)
			{
				edge[i][j] = edge[i][j];
			}
		}

		for (int i = 0; i < MaxVertexNum; i++)
		{
			this->vertex[i] = Vertex(i);	//�����ų�ʼ��
			this->setIndegree(this->vertex[i]);		//�������
			this->setOutdegree(this->vertex[i]);	//���ó���
			this->edgeNum += this->vertex[i].getDegree();	//��ͼ���ܶ���
		}
		this->edgeNum /= 2;		//����=�ܶ���/2
	}

	/// <summary>
	/// ���ö������
	/// </summary>
	/// <param name="vertex">����</param>
	void setIndegree(Vertex vertex)
	{
		//�ö��������еķ�0����
		for (int i = 0; i < MaxVertexNum; i++)
		{
			if (edge[i][vertex.index] != 0 && edge[i][vertex.index] != Infinity) {	//��0 �ǡ�
				vertex.inDegree++;	//���++
			}
		}
	}

	/// <summary>
	/// ���ö������
	/// </summary>
	/// <param name="vertex">����</param>
	void setOutdegree(Vertex vertex)
	{
		//�ö��������еķ�0����
		for (int i = 0; i < MaxVertexNum; i++)
		{
			if (edge[vertex.index][i] != 0 && edge[vertex.index][i] != Infinity) {	//��0 �ǡ�
				vertex.outDegree++;	//����++
			}
		}
	}

	/// <summary>
	/// ��ö������
	/// </summary>
	/// <param name="vertex">����</param>
	/// <returns>���</returns>
	int getIndegree(Vertex vertex)
	{
		return vertex.inDegree;
	}

	/// <summary>
	/// ��ö������
	/// </summary>
	/// <param name="vertex">����</param>
	/// <returns>����</returns>
	int getOutdegree(Vertex vertex)
	{
		return vertex.outDegree;
	}
};
