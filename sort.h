#pragma once
#ifndef SORT_H
#define SORT_H
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

// Sorting algorithm --------------------------------------------------------------------------------------
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

// Quick sort
int index_compare(int *a, int low, int high, long long &count_compare)
{
    int pi = a[(high + low) / 2];
    int l = low;
    int r = high;
    while (++count_compare && l <= r)
    {
        while ((++count_compare && l <= r) && (++count_compare && a[l] < pi))
            l++;
        while ((++count_compare && l <= r) && (++count_compare && a[r] > pi))
            r--;
        if (++count_compare && l <= r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    return l;
}
void QuickSort_compare(int *a, int low, int high, long long &count_compare)
{
    int pi = index_compare(a, low, high, count_compare);
    if (++count_compare && low < pi - 1)
        QuickSort_compare(a, low, pi - 1, count_compare);
    if (++count_compare && pi < high)
        QuickSort_compare(a, pi, high, count_compare);
}

int index_time(int *a, int low, int high)
{
    int pi = a[(high + low) / 2];
    int l = low;
    int r = high;
    while (l <= r)
    {
        while (l <= r && a[l] < pi)
            l++;
        while (l <= r && a[r] > pi)
            r--;
        if (l <= r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    return l;
}
void QuickSort_time(int *a, int low, int high)
{
    int pi = index_time(a, low, high);
    if (low < pi - 1)
        QuickSort_time(a, low, pi - 1);
    if (pi < high)
        QuickSort_time(a, pi, high);
}

// Counting sort
void CountingSort_compare(int *a, int n, long long &count_compare)
{
    int max = *max_element(a, a + n);
    int min = *min_element(a, a + n);
    vector<int> count(max - min + 1);
    vector<int> res(n);
    for (int i = 0; ++count_compare && i < n; i++)
    {
        count[a[i] - min]++;
    }
    for (int i = 1; ++count_compare && i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; ++count_compare && i >= 0; i--)
    {
        res[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }
    for (int i = 0; ++count_compare && i < n; i++)
    {
        a[i] = res[i];
    }
}
void CountingSort_time(int *a, int n)
{
    int max = *max_element(a, a + n);
    int min = *min_element(a, a + n);
    vector<int> count(max - min + 1);
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        count[a[i] - min]++;
    }
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        res[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = res[i];
    }
}

// Flash sort
void FlashSort_compare(int *a, int n, long long &count_compare)
{
    if (++count_compare && n <= 1)
        return;
    int m = n * 0.43;
    if (++count_compare && m <= 2)
        m = 2;
    vector<int> __L(m);
    // int m = n;
    for (int i = 0; ++count_compare && i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; ++count_compare && i < n; ++i)
    {
        if (++count_compare && Mx < a[i])
            Mx = a[i];
        if (++count_compare && Mn > a[i])
            Mn = a[i];
    }
    if (++count_compare && Mx == Mn)
        return;

#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)

    for (int i = 0; ++count_compare && i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; ++count_compare && i < m; ++i)
        __L[i] += __L[i - 1];
    //step 2
    int count = 0;
    int i = 0;
    while (++count_compare && count < n)
    {
        int k = getK(a[i]);
        while (++count_compare && i >= __L[k])
            k = getK(a[++i]);
        int z = a[i];
        while (++count_compare && i != __L[k])
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    //step 3
    for (int k = 1; ++count_compare && k < m; ++k)
    {
        for (int i = __L[k] - 2; ++count_compare && i >= __L[k - 1]; --i)
            if (++count_compare && a[i] > a[i + 1])
            {
                int t = a[i], j = i;
                while (++count_compare && t > a[j + 1])
                {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
    }
}
void FlashSort_time(int a[], int n)
{
    if (n <= 1)
        return;
    int m = n * 0.43;
    if (m <= 2)
        m = 2;
    vector<int> __L(m);
    // int m = n;
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (Mx < a[i])
            Mx = a[i];
        if (Mn > a[i])
            Mn = a[i];
    }
    if (Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];
    //step 2
    int count = 0;
    int i = 0;
    while (count < n)
    {
        int k = getK(a[i]);
        while (i >= __L[k])
            k = getK(a[++i]);
        int z = a[i];
        while (i != __L[k])
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    //step 3
    for (int k = 1; k < m; ++k)
    {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
            if (a[i] > a[i + 1])
            {
                int t = a[i], j = i;
                while (t > a[j + 1])
                {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
    }
}

//shell sort
void shellSort_compare(int a[], int n, long long &count_compare)
{
    int step, i, j, temp;
    for (step = n / 3; ++count_compare && step > 0; step /= 2)
    {
        for (i = step; ++count_compare && i < n; i++)
        {
            temp = a[i];
            for (j = i; ++count_compare && j >= step && ++count_compare && a[j - step] > temp; j -= step)
            {
                a[j] = a[j - step];
            }
            a[j] = temp;
        }
    }
}
void shellSort_time(int a[], int n)
{
    int step, i, j, temp;
    for (step = n / 3; step > 0; step /= 2)
    {
        for (i = step; i < n; i++)
        {
            temp = a[i];
            for (j = i; j >= step && a[j - step] > temp; j -= step)
            {
                a[j] = a[j - step];
            }
            a[j] = temp;
        }
    }
}

//radix sort
void countSort_compare(int arr[], int n, int exp, long long &compare)
{
    vector<int> output(n);
    int i, count[10] = {0};

    for (i = 0; ++compare && i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; ++compare && i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; ++compare && i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; ++compare && i < n; i++)
        arr[i] = output[i];
}
void radixSort_compare(int a[], int n, long long &compare)
{
    int m = *max_element(a, a + n);
    for (int exp = 1; ++compare && m / exp > 0; exp *= 10)
        countSort_compare(a, n, exp, compare);
}

void countSort_time(int arr[], int n, int exp)
{
    vector<int> output(n);
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort_time(int a[], int n)
{
    int m = *max_element(a, a + n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort_time(a, n, exp);
}

//heap sort
void heapify_compare(int a[], int n, int i, long long &compare)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (++compare && left < n && ++compare && a[left] > a[largest])
        largest = left;
    if (++compare && right < n && ++compare && a[right] > a[largest])
        largest = right;
    if (++compare && largest != i)
    {
        swap(a[i], a[largest]);
        heapify_compare(a, n, largest, compare);
    }
}
void heapSort_compare(int a[], int n, long long &compare)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_compare(a, n, i, compare);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify_compare(a, i, 0, compare);
    }
}

void heapify_time(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify_time(a, n, largest);
    }
}
void heapSort_time(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_time(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify_time(a, i, 0);
    }
}

// Shaker Sort
void ShakerSort_time(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    for (int i = left; i <= right; ++i)
    {
        bool swapped = false;
        for (int j = left; j < right; ++j)
            if (a[j] > a[j + 1])
            {
                swapped = true;
                HoanVi(a[j], a[j + 1]);
                k = j;
            }
        if (!swapped)
            return;
        right = k;
        swapped = false;
        for (int j = right; j > left; --j)
            if (a[j] < a[j - 1])
            {
                swapped = true;
                HoanVi(a[j], a[j - 1]);
                k = j;
            }
        if (!swapped)
            return;
        left = k;
    }
}
void ShakerSort_compare(int a[], int n, long long &count_compare)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    for (int i = left; ++count_compare && i <= right; ++i)
    {
        bool swapped = false;
        for (int j = left; ++count_compare && j < right; ++j)
            if (++count_compare && a[j] > a[j + 1])
            {
                swapped = true;
                HoanVi(a[j], a[j + 1]);
                k = j;
            }
        if (!swapped)
            return;
        right = k;
        swapped = false;
        for (int j = right; ++count_compare && j > left; --j)
            if (++count_compare && a[j] < a[j - 1])
            {
                swapped = true;
                HoanVi(a[j], a[j - 1]);
                k = j;
            }
        if (++count_compare && !swapped)
            return;

        left = k;
    }
}

// Merge Sort
void Merge_time(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int ii = 0; ii < n1; ++ii)
        L[ii] = arr[left + ii];
    for (int jj = 0; jj < n2; ++jj)
        R[jj] = arr[mid + 1 + jj];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
void MergeSort_time(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort_time(arr, left, mid);
        MergeSort_time(arr, ++mid, right);
        Merge_time(arr, left, mid, right);
    }
}

void Merge_compare(int arr[], int left, int mid, int right, long long &count_compare)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int ii = 0; ++count_compare && ii < n1; ++ii)
        L[ii] = arr[left + ii];
    for (int jj = 0; ++count_compare && jj < n2; ++jj)
        R[jj] = arr[mid + 1 + jj];

    int i = 0;
    int j = 0;
    int k = left;
    while (++count_compare && i < n1 && j < n2)
    {
        ++count_compare;
        if (++count_compare && L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (++count_compare && i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (++count_compare && j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
void MergeSort_compare(int arr[], int left, int right, long long &count_compare)
{
    if (++count_compare && left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort_compare(arr, left, mid, count_compare);
        MergeSort_compare(arr, ++mid, right, count_compare);
        Merge_compare(arr, left, mid, right, count_compare);
    }
}

// Bubble Sort
void BubbleSort_time(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}
void BubbleSort_compare(int a[], int n, long long &count_compare)
{
     for (int i = 0; ++count_compare && i < n - 1; i++)
    {
        for (int j = 0; ++count_compare && j < n - i - 1; j++){
            if (++count_compare && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

//SelectionSort
void SelectionSort_compare(int *a, int n, long long &count_compare)
{
    for (int i = 0; ++count_compare && i < n; i++)
    {
        int mIndex = i;
        for (int j = i; ++count_compare && j < n; j++)
            if (++count_compare && a[j] < mIndex)
            {
                mIndex = j;
            }
        swap(a[i], a[mIndex]);
    }
}
void SelectionSort_time(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int mIndex = i;
        for (int j = i; j < n; j++)
            if (a[j] < mIndex)
            {
                mIndex = j;
            }
        swap(a[i], a[mIndex]);
    }
}

//InsertionSort
void InsertionSort_compare(int *a, int n, long long &count_compare)
{
    for (int i = 1; ++count_compare && i < n; i++)
    {
        int k = i - 1;
        int key = a[i];
        while (++count_compare && a[k] > key && ++count_compare && k >= 0)
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = key;
    }
}
void InsertionSort_time(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = i - 1;
        int key = a[i];
        while (a[k] > key && k >= 0)
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = key;
    }
}

// Binary Insertion Sort
void BinaryInsertionSort_time(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int left = 0;
        int right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (temp < a[mid])
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--)
        {
            a[j + 1] = a[j];
        }
        a[left] = temp;
    }
}
void BinaryInsertionSort_compare(int *a, int n, long long &count_compare)
{
    for (int i = 1; ++count_compare && i < n; i++)
    {
        int temp = a[i];
        int left = 0;
        int right = i - 1;
        while (++count_compare && left <= right)
        {
            int mid = (left + right) / 2;
            if (++count_compare && temp < a[mid])
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        for (int j = i - 1; ++count_compare && j >= left; j--)
        {
            a[j + 1] = a[j];
        }
        a[left] = temp;
    }
}
#endif