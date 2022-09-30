#include<iostream>
#include"Sort.h"
#include"Heap.h"
using namespace std;

/// <summary>
/// 插入排序
/// </summary>
/// <param name="array">待排数组</param>
/// <param name="length">长度</param>
void InsertSort(int array[], int length)
{
	int j = 0;

	for (int i = 1; i < length; i++)
	{
		if (array[i] < array[i - 1]) {
			int temp = array[i];	//待插入元素
			for (j = i - 1; j >= 0 && array[j] > temp; j--)		//将待插入元素前的 大于该元素的项后移一位
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