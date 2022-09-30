#pragma once
#include<iostream>
#include"Heap.h"
using namespace std;

template<class T>
class Sort
{
public:
	/// <summary>
	/// ����
	/// </summary>
	static void Swap(T& val1, T& val2)
	{
		T temp = val1;
		val1 = val2;
		val2 = temp;
	}

	/// <summary>
	/// ���ֲ�����������
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="length">����</param>
	static void insertSort(T array[], int length)
	{
		for (int i = 1; i < length; i++)
		{
			T temp = array[i];		//����Ԫ��
			int low = 0;
			int high = i - 1;	//���ֲ��ҷ�Χ[1, i-1]	����Ԫǰ������Ԫ��

			while (low <= high) {
				int mid = (low + high) / 2;
				if (array[mid] > temp) high = mid - 1;	//����λ����������� �����������
				else low = mid + 1;		//����λ�����Ұ�����
			}

			for (int j = i - 1; j >= high + 1; j--)
			{
				array[j + 1] = array[j];	//�����ڴ���Ԫ�غ���
			}
			array[high + 1] = temp;		//�������Ԫ��
		}
	}

	/// <summary>
	/// ϣ����������
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="length">����</param>
	static void ShellSort(T array[], int length)
	{
		int j = 0;

		for (int d = length / 2; d >= 1; d /= 2)
		{
			for (int i = d + 1; i < length; i++)
			{
				if (array[i] < array[i - d]) {	//С��ǰ���Ԫ��
					T temp = array[i];	//��¼����Ԫ��

					for (j = i - d; j >= 0 && temp < array[j]; j -= d)	//������Ԫ��ǰ�� ���ڸ�Ԫ�ص������dλ
					{
						array[j + d] = array[j];
					}
					array[j + d] = temp;
				}
			}
		}
	}

	/// <summary>
	/// ð����������
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="length">����</param>
	static void BubbleSort(T array[], int length)
	{
		for (int i = 0; i < length - 1; i++)
		{
			bool swap = false;	//�����Ƿ�������
			for (int j = 0; j < length - i - 1; j++)
			{
				if (array[j] > array[j + 1]) {	//���� ����
					Swap(array[j], array[j + 1]);
					swap = true;
				}
			}

			if (!swap) return;	//����δ�������� ����������
		}
	}

	/// <summary>
	/// ������������
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="length">����</param>
	static void QuickSort(T array[], int length)
	{
		QuickSort(array, 0, length - 1);
	}

	/// <summary>
	/// ������������
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="low">��߽�</param>
	/// <param name="high">�ұ߽�</param>
	static void QuickSort(T array[], int low, int high)
	{
		if (low < high) {
			int pivotPos = Partition(array, low, high);	//���� ȷ������λ��
			QuickSort(array, low, pivotPos - 1);	//�����ӱ���п���
			QuickSort(array, pivotPos + 1, high);	//�����ӱ���п���
		}
	}

	/// <summary>
	/// ���֣���[low,high]��Ԫ�ػ���Ϊ ���С������ �ұߴ������� ��������λ��
	/// </summary>
	/// <param name="array">����������</param>
	/// <param name="low">��߽�</param>
	/// <param name="high">�ұ߽�</param>
	/// <returns>����λ��</returns>
	static int Partition(T array[], int low, int high)
	{
		T pivot = array[low];	//����һ��Ԫ����Ϊ����
		while (low < high) {
			while (low < high && array[high] >= pivot) high--;	//�ҵ�һ��С��pivot��Ԫ��
			array[low] = array[high];	//С��pivot�ķ���lowλ��
			while (low < high && array[low] <= pivot) low++;	//�ҵ�һ������pivot��Ԫ��
			array[high] = array[low];	//����pivot�ķ���highλ��
		}
		array[low] = pivot;	//�ҵ�λ��
		return low;
	}

	/// <summary>
	/// ��ѡ����������
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="length">����</param>
	static void SelectSort(T array[], int length)
	{
		for (int i = 0; i < length - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < length; j++)
			{
				if (array[j] < array[min]) min = j;	//�ҵ���С��
			}
			//����
			Swap(array[i], array[min]);
		}
	}

	/// <summary>
	/// ����������####��bug
	/// </summary>
	/// <param name="array">��������</param>
	/// <param name="length">����</param>
	static void HeapSort(T array[], int length)
	{
		Heap<T>::BuildMaxHeap(array, length);	//�����󶥶�

		for (int i = length - 1; i > 0; i--)
		{
			Swap(array[i], array[0]);				//�Ѷ�Ԫ�غͶѵ�Ԫ�ؽ���
			Heap<T>::HeadAdjust(array, 0, i);	//��ʣ�������������ɴ󶥶�
		}
	}

	static void MergeSort(T array[], int low, int high)
	{

	}
};
