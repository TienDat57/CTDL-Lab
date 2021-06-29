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
void radixSort_compare(int a[], int n, long long &count_compare)
{
    int b[5], m = a[0], exp = 1;

    for (int i = 0; ++count_compare && i < n; i++)
        if (++count_compare && a[i] > m)
            m = a[i];

    while (++count_compare && m / exp > 0)
    {
        int bucket[10] = {0};
        for (int i = 0; ++count_compare && i < n; i++)
            bucket[a[i] / exp % 10]++;
        for (int i = 1; ++count_compare && i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; ++count_compare && i >= 0; i--)
            b[--bucket[a[i] / exp % 10]] = a[i];
        for (int i = 0; ++count_compare && i < n; i++)
            a[i] = b[i];
        exp *= 10;
    }
}
void radixSort_time(int a[], int n)
{
    int b[5], max = a[0], exp = 1;

    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];

    while (max / exp > 0)
    {
        int bucket[10] = {0};
        for (int i = 0; i < n; i++)
            bucket[a[i] / exp % 10]++;
        for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; i--)
            b[--bucket[a[i] / exp % 10]] = a[i];
        for (int i = 0; i < n; i++)
            a[i] = b[i];
        exp *= 10;
    }
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

#endif