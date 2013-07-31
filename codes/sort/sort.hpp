#ifndef _SORT_HPP_
#define _SORT_HPP_

#include <algorithm>


template <typename T>
void Swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}




template <typename T>
int FindPivot(T* a, int start, int end)
{
    if(start >= end) {
        return start;
    }
    // ��start,endֵ�ܴ�ʱ����start+end�������
    // ���� int mid = start + (end - start)/2;
    int mid = (start + end) / 2;
    int pivot = a[mid];
    // �����������˽���ɨ�裬���Ͻ���Ԫ�ؽ���
    while(start != end) {
        while(a[start] <= pivot && start < end) {
            ++start;
        }
        //Swap(a[start], a[mid]);
        a[mid] = a[start];
        while(a[end] >= pivot && start < end) {
            --end;
        }
        //Swap(a[end], a[mid]);
        a[mid] = a[end];
    }
    a[start] = pivot;
    return start;
}


//        if(a[start] > pivot) {
//            a[mid] = a[start];
//            mid = start;
//            // Swap(a[start], a[mid]);
//        }
//        ++start;
//        if(a[end] < pivot) {
//            a[mid] = a[end];
//            mid = end;
//            // Swap(a[mid], a[end]);
//        }
//        --end;
//    }
//    return mid;
//}

//int FindPovit(T* a, const int length, bool ascent = true)
//{
//    // ������Ϊ��һԪ�أ�ֹͣ�ݹ�
//    if(length == 1)
//        return ;
//    // ѡ�������м��Ԫ����Ϊ�Ƚ϶���
//    int mid = length / 2;
//
//    int start = a[0];
//    int end   = a[length-1];
//
//    // ��ͷβ����ͬʱɨ�����飬����Ԫ�ء�
//    while(start != end)
//    {
//        if(a[start] > a[mid])
//        {
//            Swap(a[start], a[mid]);
//            ++start;
//        }
//        if(a[end] < a[mid])
//        {
//            Swap(a[end], a[mid]);
//            --end;
//        }
//    }



//    for(int i = 0; i < length; ++i)
//    {
//        if(ascent)
//        {
//            if(a[i] > a[mid])
//            {
//                Swap(a[mid], a[i]);
//            }
//        }
//        else
//        {
//            if(a[i] < a[mid])
//            {
//                Swap(a[mid], a[i]);
//            }
//        }
//    }
//}



// ����ԭ��ѡ����һԪ�أ�ɨ��һ�����飬�������ķ��������ұߣ�����
//           С�����ķ��������ұߡ�Ȼ���ɨ��һ�����������Ҳ��ֵݹ顣
//
// ��ֹ�������ݹ黮�ֵ������鳤��Ϊ1����ֻ��һ��Ԫ�ء�
//
// ���Ӷȣ�  nlog(n)
//           �������������Ѿ�����
//           ��������
// trick:    �ڶ����������ɨ�轻����ʱ����ͷβ����ָ��ͬʱ����
// ������    ���ȶ�������

template <typename T>
void QuickSort(T* a, const int length)
{
    if(length <= 1) {
        return;
    }
    int pivot = FindPivot(a, 0, length-1);
    QuickSort(a, pivot);
    QuickSort(a+pivot+1, length-pivot-1);
    //QuickSort(a, 0, pivot);
    //QuickSort(a, pivot+1, length-1);
    //int piviot = FindPoivit(a, start, end);
    //QuickSort(a, piviot);
    //QuickSort(a+piviot+1, length-piviot);
}


/** ����ԭ����������ɨ�裬����ǰԪ�ط���ǰ���Ѿ������������
 *  ���Ӷȣ�  n^2
 *            ���������Ѿ�Ϊ�������У���Ҫ�ƶ�Ԫ�ظ���Ϊ0
 *            ��������Ϊ�������У���Ҫ�ƶ�Ԫ�ظ���Ϊ1+2+...+n-1=n(n-1)/2
    ϸ�ڣ�    �ƶ�Ԫ��ʱҪ����ǰ�ƶ�����������Ԫ�ر��һ���������
 *  trick:
 *  ���� :
 */
template <typename T>
void InsertSort(T* a, const int length)
{
    for(int i = 1; i < length; ++i) {
        // ɨ���Ѿ�����������飬���Ƿ��д��ڵ�ǰԪ�ص�
        for(int j = 0; j < i; ++j) {
            // ����У���ӵ�һ�����ڵ�ǰԪ�ص�Ԫ�ؿ�ʼ����һ����ƶ���
            if(a[i] < a[j]) {
                int cur = a[i];
//                 for(int k = j; k < i; ++k) {
//                    a[k+1] = a[k];
//                 }
                for(int k = i; k > j; --k) {
                    a[k] = a[k-1];
                }
                a[j] = cur;
                break;
            }
        }
        //std::for_each(a, a+length, [](T& t) {std::cout << t << " ";});
        //std::cout << "\n";
    }
}




/*
   ���������������ѣ������Ե����ϵķ�����

*/

template <typename T>
void MaxHeapify(T* a, int length)
{
    while(length != 0) {
        int left_child  = length-1;
        int right_child = length-2;
        int parent      = (length-1)/2;
        int max;
        if(a[parent] > a[left_child]) {
            max = parent;
        } else {
            max = left_child;
        }
        if(max < a[right_child]) {
            max = right_child;
        }
        Swap(a[max], a[parent]);
        length /= 2;
    }
}




/**
 *
     ԭ��   �ѣ��ɿ�����һ�ö�������ÿ���ڵ��ֵ�����������ӽڵ㣨���ѣ�����֮Ϊ
              ��С�ѡ�
              ����ʹ�õݹ�ʵ�֡�
 *   ���Ӷȣ� nlogn
 *            ��������
 *            ��������
     ϸ�ڣ�
     trick:
 *   ������
 */

template <typename T>
void HeapSort(T* a, const int length)
{
    //MaxHeapify(a, length-1);
    //HeapSort(a+1, length-2)
    for(int i = 0; i < length; ++i)
        MaxHeapify(a+i, length-i-1);
}

#endif // _SORT_HPP_
