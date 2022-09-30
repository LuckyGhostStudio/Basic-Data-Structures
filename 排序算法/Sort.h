#pragma once
#include<iostream>
#include"Heap.h"
using namespace std;

template<class T>
class Sort
{
public:
	/// <summary>
	/// 交换
	/// </summary>
	static void Swap(T& val1, T& val2)
	{
		T temp = val1;
		val1 = val2;
		val2 = temp;
	}

	/// <summary>
	/// 二分插入排序：升序
	/// </summary>
	/// <param name="array">待排数组</param>
	/// <param name="length">长度</param>
	static void insertSort(T array[], int length)
	{
		for (int i = 1; i < length; i++)
		{
			T temp = array[i];		//待插元素
			int low = 0;
			int high = i - 1;	//二分查找范围[1, i-1]	待插元前面所有元素

			while (low <= high) {
				int mid = (low + high) / 2;
				if (array[mid] > temp) high = mid - 1;	//待插位置在左半区间 查找左半区间
				else low = mid + 1;		//待插位置在右半区间
			}

			for (int j = i - 1; j >= high + 1; j--)
			{
				array[j + 1] = array[j];	//将大于待插元素后移
			}
			array[high + 1] = temp;		//插入待插元素
		}
	}

	/// <summary>
	/// 希尔排序：升序
	/// </summary>
	/// <param name="array">待排数组</param>
	/// <param name="length">长度</param>
	static void ShellSort(T array[], int length)
	{
		int j = 0;

		for (int d = length / 2; d >= 1; d /= 2)
		{
			for (int i = d + 1; i < length; i++)
			{
				if (array[i] < array[i - d]) {	//小于前面的元素
					T temp = array[i];	//记录待插元素

					for (j = i - d; j >= 0 && temp < array[j]; j -= d)	//将待插元素前的 大于该元素的项后移d位
					{
						array[j + d] = array[j];
					}
					array[j + d] = temp;
				}
			}
		}
	}

	/// <summary>
	/// 冒泡排序：升序
	/// </summary>
	/// <param name="array">待排数组</param>
	/// <param name="length">长度</param>
	static void BubbleSort(T array[], int length)
	{
		for (int i = 0; i < length - 1; i++)
		{
			bool swap = false;	//此躺是否发生交换
			for (int j = 0; j < length - i - 1; j++)
			{
				if (array[j] > array[j + 1]) {	//逆序 交换
					Swap(array[j], array[j + 1]);
					swap = true;
				}
			}

			if (!swap) return;	//此趟未发生交换 序列已有序
		}
	}

	/// <summary>
	/// 快速排序：升序
	/// </summary>
	/// <param name="array">待排数组</param>
	/// <param name="length">长度</param>
	static void QuickSort(T array[], int length)
	{
		QuickSort(array, 0, length - 1);
	}

	/// <summary>
	/// 快速排序：升序
	/// </summary>
	/// <param name="array">待排数组</param>
	/// <param name="low">左边界</param>
	/// <param name="high">右边界</param>
	static void QuickSort(T array[], int low, int high)
	{
		if (low < high) {
			int pivotPos = Partition(array, low, high);	//划分 确定枢轴位置
			QuickSort(array, low, pivotPos - 1);	//对左子表进行快排
			QuickSort(array, pivotPos + 1, high);	//对右子表进行快排
		}
	}

	/// <summary>
	/// 划分：将[low,high]的元素划分为 左边小于枢轴 右边大于枢轴 返回枢轴位置
	/// </summary>
	/// <param name="array">待划分数组</param>
	/// <param name="low">左边界</param>
	/// <param name="high">右边界</param>
	/// <returns>枢轴位置</returns>
	static int Partition(T array[], int low, int high)
	{
		T pivot = array[low];	//将第一个元素作为枢轴
		while (low < high) {
			while (low < high && array[high] >= pivot) high--;	//找到一个小于pivot的元素
			array[low] = array[high];	//小于pivot的放在low位置
			while (low < high && array[low] <= pivot) low++;	//找到一个大于pivot的元素
			array[high] = array[low];	//大于pivot的放在high位置
		}
		array[low] = pivot;	//找到位置
		return low;
	}

	/// <summary>
	/// 简单选择排序：升序
	/// </summary>
	/// <param name="array">待排数组</param>
	/// <param name="length">长度</param>
	static void SelectSort(T array[], int length)
	{
		for (int i = 0; i < length - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < length; j++)
			{
				if (array[j] < array[min]) min = j;	//找到最小的
			}
			//交换
			Swap(array[i], array[min]);
		}
	}

	/// <summary>
	/// 堆排序：升序####有bug
	/// </summary>
	/// <param name="array">待排数组</param>
	/// <param name="length">长度</param>
	static void HeapSort(T array[], int length)
	{
		Heap<T>::BuildMaxHeap(array, length);	//建立大顶堆

		for (int i = length - 1; i > 0; i--)
		{
			Swap(array[i], array[0]);				//堆顶元素和堆底元素交换
			Heap<T>::HeadAdjust(array, 0, i);	//将剩余待排数组调整成大顶堆
		}
	}

	static void MergeSort(T array[], int low, int high)
	{

	}
};
