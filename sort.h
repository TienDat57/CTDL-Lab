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
void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

int index(int *a, int low, int high, long long & count_compare){
	int pi = a[(high + low) / 2];
	int l = low;
	int r = high;
	while (++count_compare && l <= r){
		while ((++count_compare && l <= r) && (++count_compare && a[l] < pi)) l++;
		while ((++count_compare && l <= r) && (++count_compare && a[r] > pi)) r--;
		if (++count_compare && l <= r) {
			swap(a[l],a[r]);
			l++; r--;
		}
	}
	return l;
}

void QuickSort(int* a, int low, int high, long long & count_compare){
	int pi = index(a, low, high, count_compare);
	if (++count_compare && low < pi - 1) QuickSort(a, low, pi - 1, count_compare);
	if (++count_compare && pi < high) QuickSort(a, pi, high, count_compare);
}

void CountingSort(int* a, int n, long long& count_compare) {
    int max = *max_element(a, a + n);
    int min = *min_element(a, a + n);
    vector <int> count(max - min + 1);
    vector <int> res(n);
    for (int i = 0; ++count_compare && i < n; i++) {
        count[a[i] - min]++;
    }
    for (int i = 1; ++count_compare && i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; ++count_compare && i >= 0; i--) {
        res[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }
    for (int i = 0; ++count_compare && i < n; i++) {
        a[i] = res[i];
    }
}

void FlashSort(int* a, int n, long long& count_compare) {int minVal = *min_element(a, a + n);
    int maxVal = *max_element(a, a + n);
    if (++count_compare && maxVal == minVal) return;
    int maxIndex = 0;
    int bucket = int(0.45 * n);

    vector <int> L(bucket);

    for (int i = 0; ++count_compare && i < n; i++) {
        if (++count_compare && a[i] == maxVal) {
            maxIndex = i;
            break;
        }
    }

    double x = double((bucket - 1) / (a[maxIndex] - minVal));
    for (int i = 0; ++count_compare && i < n; i++) {
        int k = int(x * (a[i] - minVal));
        ++L[k];
    }
    // find the last element for each bucket
    for (int i = 1; ++count_compare && i < bucket; i++) {
        L[i] += L[i - 1];
    }

    int hold = a[0];
    int move = 0;
    int flash = 0;
    int k = 0;
    int t = 0;
    int j = 0;
    while (++count_compare && move < n - 1) {
        while (++count_compare && j > L[k] - 1) {
            j++;
            k = int(x * (a[j] - minVal));
        }
        flash = a[j];
        if (++count_compare && k < 0) break;
        while (++count_compare && j != L[k]) {
            k = int(x * (a[j] - minVal));
            hold = a[t = --L[k]];
            a[t] = flash;
            flash = hold;
            move++;
        }
    }
    // use Insertion Sort
    int vt, nam;
    for (int i = 1; ++count_compare && i < n; i++) {
        nam = a[i];
        vt = i;
        while ((++count_compare && vt > 0) && (++count_compare && nam < a[vt - 1])) {
            a[vt] = a[vt - 1];
            vt--;
        }
        a[vt] = nam;
    }
}


#endif