#include<iostream>
#include"Sort.h"
#include"Heap.h"
using namespace std;

/// <summary>
/// ��������
/// </summary>
/// <param name="array">��������</param>
/// <param name="length">����</param>
void InsertSort(int array[], int length)
{
	int j = 0;

	for (int i = 1; i < length; i++)
	{
		if (array[i] < array[i - 1]) {
			int temp = array[i];	//������Ԫ��
			for (j = i - 1; j >= 0 && array[j] > temp; j--)		//��������Ԫ��ǰ�� ���ڸ�Ԫ�ص������һλ
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = temp;
		}
	}
}

int main()
{
	int a[8] = { 53,17,78,9,45,65,87,32 };
	//InsertSort(a, 8);
	//Sort<int>::insertSort(a, 8);
	//Sort<int>::ShellSort(a, 8);
	//Sort<int>::BubbleSort(a, 8);
	//Sort<int>::QuickSort(a, 8);
	//Sort<int>::SelectSort(a, 8);
	/*Sort<int>::HeapSort(a, 8);

	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

	int b[] = { 23,17,72,60,25,8,68,71,52 };
	Heap<int> heap = Heap<int>(b, 9);
	//heap.sort();
	for (int i = 0; i < heap.size; i++)
	{
		cout << heap[i] << " ";
	}
	cout << endl;
}