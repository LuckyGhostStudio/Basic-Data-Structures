#pragma once
#include<iostream>
#define MaxVertexNum 100
using namespace std;


class ArcNode	//�߱���
{
public:
	int toIndex;		//�û�ָ��Ķ���ı��
	ArcNode* next;		//ָ����һ������ָ��;

	ArcNode(int toIndex, ArcNode* next)
	{
		this->toIndex = toIndex;
		this->next = next;
	}
};

template<class T>
class Vertex	//�������
{
public:
	int index;	//������
	T value;	//������Ϣ
	ArcNode* first;		//ָ���һ�������ڸý��Ļ���ָ��

	Vertex(int index,T value, ArcNode* first)
	{
		this->index = index;
		this->value = value;
		this->first = first;
	}
};

template<class T>
class AGraph	//ͼ
{
public:
	Vertex<T>* vertices;	//�����
	int vertexNum, arcNum;	//������ ����

	AGraph(T* vertexValues)
	{
		//��ʼ�������
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
