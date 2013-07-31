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
    // 当start,end值很大时可能start+end可能溢出
    // 考虑 int mid = start + (end - start)/2;
    int mid = (start + end) / 2;
    int pivot = a[mid];
    // 从子数组两端进行扫描，不断进行元素交换
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
//    // 子数组为单一元素，停止递归
//    if(length == 1)
//        return ;
//    // 选择数组中间的元素作为比较对象
//    int mid = length / 2;
//
//    int start = a[0];
//    int end   = a[length-1];
//
//    // 从头尾两端同时扫描数组，交换元素。
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



// 基本原理：选择任一元素，扫描一遍数组，大于它的放在它的右边（升序）
//           小于它的放在它的右边。然后对扫描一遍后的数组左右部分递归。
//
// 终止条件：递归划分的子数组长度为1，即只有一个元素。
//
// 复杂度：  nlog(n)
//           最差情况：数组已经有序
//           最好情况：
// trick:    在对子数组进行扫描交换的时候，用头尾两个指针同时进行
// 其他：    不稳定的排序

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


/** 基本原理：从左向右扫描，将当前元素放入前面已经有序的数组中
 *  复杂度：  n^2
 *            最好情况：已经为升序排列，需要移动元素个数为0
 *            最差情况：为降序排列，需要移动元素个数为1+2+...+n-1=n(n-1)/2
    细节：    移动元素时要后向前移动，否则会出现元素变成一样的情况。
 *  trick:
 *  其他 :
 */
template <typename T>
void InsertSort(T* a, const int length)
{
    for(int i = 1; i < length; ++i) {
        // 扫描已经有序的子数组，找是否有大于当前元素的
        for(int j = 0; j < i; ++j) {
            // 如果有，则从第一个大于当前元素的元素开始。逐一向后移动。
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
   将任意数组变成最大堆，采用自底向上的方法。

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
     原理：   堆，可看成是一棵二叉树，每个节点的值大于其左右子节点（最大堆），反之为
              最小堆。
              可以使用递归实现。
 *   复杂度： nlogn
 *            最好情况：
 *            最差情况：
     细节：
     trick:
 *   其他：
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
