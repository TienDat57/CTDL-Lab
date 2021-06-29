#pragma once
#ifndef SORT_H
#define SORT_H
#include <iostream>
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
    int minVal = *min_element(a, a + n);
    int maxVal = *max_element(a, a + n);
    if (++count_compare && maxVal == minVal)
        return;
    int maxIndex = 0;
    int bucket = int(0.45 * n);

    vector<int> L(bucket);

    for (int i = 0; ++count_compare && i < n; i++)
    {
        if (++count_compare && a[i] == maxVal)
        {
            maxIndex = i;
            break;
        }
    }

    double x = double((bucket - 1) / (a[maxIndex] - minVal));

    for (int i = 0; ++count_compare && i < n; i++)
    {
        int k = int(x * (a[i] - minVal));
        ++L[k];
    }
    // find the last element for each bucket
    for (int i = 1; ++count_compare && i < bucket; i++)
    {
        L[i] += L[i - 1];
    }

    int hold = a[maxIndex];
    int move = 0;
    int flash = 0;
    int k = bucket - 1;
    int t = 0;
    int j = 0;
    while (++count_compare && move < n - 1)
    {
        while (++count_compare && j > L[k] - 1)
        {
            ++j;
            k = int(x * (a[j] - minVal));
        }
        flash = a[j];
        if (++count_compare && k < 0)
            break;
        while (++count_compare && j != L[k])
        {
            k = int(x * (flash - minVal));
            hold = a[t = --L[k]];
            a[t] = flash;
            flash = hold;
            ++move;
        }
    }
    // use Insertion Sort
    int vt, nam;
    for (int i = 1; ++count_compare && i < n; i++)
    {
        nam = a[i];
        vt = i;
        while ((++count_compare && vt > 0) && (++count_compare && nam < a[vt - 1]))
        {
            a[vt] = a[vt - 1];
            vt--;
        }
        a[vt] = nam;
    }
}
void FlashSort_time(int *a, int n)
{
    int minVal = *min_element(a, a + n);
    int maxVal = *max_element(a, a + n);
    if (maxVal == minVal)
        return;
    int maxIndex = 0;
    int bucket = int(0.45 * n);

    vector<int> L(bucket);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == maxVal)
        {
            maxIndex = i;
            break;
        }
    }

    double x = double((bucket - 1) / (a[maxIndex] - minVal));
    for (int i = 0; i < n; i++)
    {
        int k = int(x * (a[i] - minVal));
        ++L[k];
    }
    // find the last element for each bucket
    for (int i = 1; i < bucket; i++)
    {
        L[i] += L[i - 1];
    }

    int hold = a[maxIndex];
    int move = 0;
    int flash = 0;
    int k = bucket - 1;
    int t = 0;
    int j = 0;
    while (move < n - 1)
    {
        while (j > L[k] - 1)
        {
            ++j;
            k = int(x * (a[j] - minVal));
        }
        flash = a[j];
        if (k < 0)
            break;
        while (j != L[k])
        {
            k = int(x * (flash - minVal));
            hold = a[t = --L[k]];
            a[t] = flash;
            flash = hold;
            ++move;
        }
    }
    // use Insertion Sort
    int vt, nam;
    for (int i = 1; i < n; i++)
    {
        nam = a[i];
        vt = i;
        while (vt > 0 && nam < a[vt - 1])
        {
            a[vt] = a[vt - 1];
            vt--;
        }
        a[vt] = nam;
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
void countSort_compare(int arr[], int n, int exp,long long &compare)
{
    vector <int> output(n); 
    int i, count[10] = { 0 };

    for (i = 0; ++compare && i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; ++compare && i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; ++compare && i >= 0; i--) {
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
    vector <int> output(n); 
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
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
void ShakerSort_compare(int a[], int n,long long& count_compare)
{
	int left = 0;
	int right = n - 1;
	int k = 0;
	for (int i = left;++count_compare && i <= right; ++i)
	{
		bool swapped = false;
		for (int j = left;++count_compare && j < right; ++j)
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
		for (int j = right;++count_compare && j > left; --j)
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
    int n2 =  right - mid;
 
    int* L = new int[n1];
    int* R = new int [n2];
 
    for (int ii = 0; ii < n1; ++ii)
        L[ii] = arr[left + ii];
    for (int jj = 0; jj < n2; ++jj)
        R[jj] = arr[mid + 1+ jj];
 
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
        int mid = left +(right -left)/2;
        MergeSort_time(arr, left, mid);
        MergeSort_time(arr, ++mid , right);
        Merge_time(arr, left, mid, right);
    }
}

void Merge_compare(int arr[], int left, int mid, int right,long long& count_compare)
{
    int n1 = mid - left + 1;
    int n2 =  right - mid;
 
    int* L = new int[n1];
    int* R = new int [n2];
 
    for (int ii = 0; ++count_compare && ii < n1; ++ii)
        L[ii] = arr[left + ii];
    for (int jj = 0; ++count_compare && jj < n2; ++jj)
        R[jj] = arr[mid + 1+ jj];
 
    int i = 0;
    int j = 0;
    int k = left;
    while (++count_compare && i < n1 && j < n2)
    {
        ++count_compare ;
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
void MergeSort_compare(int arr[], int left, int right,long long& count_compare)
{
    if (++count_compare && left < right)
    {
        int mid = left +(right -left)/2;
        MergeSort_compare(arr, left, mid, count_compare);
        MergeSort_compare(arr, ++mid , right, count_compare);
        Merge_compare(arr, left, mid, right, count_compare);
    }
}

// Bubble Sort
void BubbleSort_time(int a[], int n)
{
	for (int i = n - 1; i >= 0; --i)
	{
		bool swapped = false;
		for (int j = 0; j < i; ++j)
			if (a[j] > a[j + 1])
			{
				swapped = true;
				HoanVi(a[j], a[j + 1]);
			}
		if (!swapped)
			return;
	}
}
void BubbleSort_compare(int a[], int n,long long& count_compare)
{
	for (int i = n - 1; i >= 0; --i)
	{
		bool swapped = false;
		for ( int j = 0;++count_compare && j < i; ++j)
			if (++count_compare && a[j] > a[j + 1])
			{
				swapped = true;
				HoanVi(a[j], a[j + 1]);
			}
		if (++count_compare && !swapped)
			return;
	}
}

#endif