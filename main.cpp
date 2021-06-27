#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

int index(int *a, int low, int high, int &cc){
    int pi = a[high];
    int l = low;
    int r = high - 1;
    while (true){
        while ((++cc && l <= r) && (++cc && a[l] < pi)) l++;
        while ((++cc && l <= r) && (++cc && a[r] > pi)) r--;
        if (++cc && l >= r) break;
        swap(a[l],a[r]);
        l++;
        r--;
    }
    swap(a[l], a[high]);
    return l;
}

void QuickSort(int*a, int low, int high, int &count_compare){
    if (low < high){
        int i = index(a, low, high, count_compare);
        QuickSort(a, low, i - 1, count_compare);
        QuickSort(a, i + 1, high, count_compare);
    }
}

void CountingSort(int *a, int n, int &count_compare){
    int max = *max_element(a, a+n);
    int min = *min_element(a, a+n);
    vector <int> count(max - min + 1);
    vector <int> res(n);
    for (int i = 0; ++count_compare && i < n; i++){
        count[a[i] - min]++;
    }
    for (int i = 1; ++count_compare && i < count.size(); i++){
        count[i] += count[i - 1]; 
    }
    for (int i = n - 1; ++count_compare && i >= 0; i--){
        res[count[a[i] - min] -1] = a[i];
        count[a[i] - min]--;
    }
    for (int i = 0; ++count_compare && i < n ; i++){
        a[i] = res[i];
    }
}

void FlashSort(int*a, int n, int &count_compare){
    int minVal = *min_element(a, a+n);
    int maxVal = *max_element(a, a+n);
    if (++count_compare && maxVal == minVal) return;
    int maxIndex = 0;
    int bucket = int(0.45*n);

    vector <int> L(bucket);

    for (int i = 0;++count_compare && i < n; i++){
        if (++count_compare && a[i] == maxVal){
            maxIndex = i;
            break;
        }
    }

    for (int i = 0; ++count_compare && i < n; i++){
        int k = int((bucket - 1) * (a[i] - minVal) / (maxVal - minVal));
        ++L[k];
    }
    // find the last element for each bucket
    for (int i = 1; ++count_compare && i < bucket; i++ ){
        L[i] += L[i - 1];
    }

    int hold = a[0];
    int move = 0;
    int flash = 0;
    int k = 0;
    int t = 0;
    int j = 0;
    while (++count_compare && move < n - 1){
        while (++count_compare && j > L[k] -1){
            j++;
            k = int((bucket - 1) * (a[j] - minVal) / (maxVal - minVal));
        }
        flash = a[j];
        if (++count_compare && k < 0) break;
        while (++count_compare && j != L[k]){
            k = int((bucket - 1) * (a[j] - minVal) / (maxVal - minVal));
            hold = a[t = --L[k]];
            a[t] = flash;
            flash = hold;
            move++;
        }
    }
    // use Insertion Sort
    int vt, x;
	for (int i = 1; ++count_compare && i < n; i++) {
		x = a[i];
		vt = i;
		while ((++count_compare && vt > 0) && (++count_compare && x < a[vt - 1])) {
			a[vt] = a[vt - 1];
			vt--;
		}
		a[vt] = x;
	}
}

void Output_res_a(string para, double time, int comp) {
    int mode = 0;
    if (para == "-time") mode = 1;
    if (para == "-comp") mode = 2;
    if (para == "-both") mode = 3;
    cout << "--------------------------" << endl;
    switch (mode)
    {
    case 1:
        cout << "Running time: " << time << 's' << endl;
        break;
    case 2:
        cout << "Comparisions: " << comp << endl;
        break;
    case 3:
        cout << "Running time: " << time << 's' << endl;
        cout << "Comparisions: " << comp << endl;
        break;
    }
}

void solveAlgoritm(string algo, int* a, int n, double& time, int& cc) {
    int mode = 0;
    if (algo == "selection-sort") mode = 1;
    if (algo == "insertion-sort") mode = 2;
    if (algo == "bubble-sort") mode = 3;
    if (algo == "shaker-sort") mode = 4;
    if (algo == "shell-sort") mode = 5;
    if (algo == "heap-sort") mode = 6;
    if (algo == "merge-sort") mode = 7;
    if (algo == "quick-sort") mode = 8;
    if (algo == "counting-sort") mode = 9;
    if (algo == "radix-sort") mode = 10;
    if (algo == "flash-sort") mode = 11;

    cc = 0;
    clock_t start, end;
    switch (mode)
    {
    case 1:
        cout << "Algorithm: Selection Sort" << endl;
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 2:
        cout << "Algorithm: Insertion Sort" << endl;
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 3:
        cout << "Algorithm: Bubble Sort" << endl;
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 4:
        cout << "Algorithm: Shaker Sort" << endl;
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 5:
        cout << "Algorithm: Shell Sort" << endl;
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 6:
        cout << "Algorithm: Heap Sort" << endl;
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 7:
        cout << "Algorithm: Merge Sort" << endl;
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 8:
        cout << "Algorithm: Quick Sort" << endl;
        start = clock();
        QuickSort(a, 0, n-1, cc);
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 9:
        cout << "Algorithm: Counting Sort" << endl;
        start = clock();
        CountingSort(a, n, cc);
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 10:
        cout << "Algorithm: Radix Sort" << endl;
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 11:
        cout << "Algorithm: Flash Sort" << endl;
        start = clock();
        FlashSort(a, n, cc);
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    }
}

void _cmd_1(char* Algorithm, string given_Input, string Output_parameter)
{
    ifstream fi(given_Input, ios::in);
    ofstream fo("output.txt", ios::out);
    if (fi.fail()) {
        cout << "Cannot open " << given_Input << " file !" << endl;
    }
    else {
        string algo(Algorithm);
        int n;
        fi >> n;
        int* a = new int[n];
        for (int i = 0; i < n; i++) fi >> a[i];
        
        double time = 0;
        int count_compare = 0;
        solveAlgoritm(algo, a, n, time, count_compare);

        cout << "Input file: " << given_Input << endl;
        cout << "Input size: " << n << endl;
        Output_res_a(Output_parameter, time, count_compare);

        if (fo.fail()) {
            cout << "Cannot open output.txt file !" << endl;
        }
        else {
            for (int i = 0; i < n; i++) fo << a[i] << " ";
        }
        fi.close();
        fo.close();
    }
}

void _cmd_2(char* Algorithm, int input_size, string input_order, string Output_parameter)
{
    cout << "loading command line 2..." << endl;
}

void _cmd_3(char* Algorithm, int input_size, string Ouput_parameter)
{
    cout << "loading command line 3..." << endl;
}

void _cmd_4(char* Algorithm1, char* Algorithm2, string givenInput) {
    cout << "loading command line 4..." << endl;
}

void _cmd_5(char* Algorithm1, char* Algorithm2, int intput_size, string input_order) {
    cout << "loading command line 5..." << endl;
}

void _algorithm(char* algorithm, char* s1, char* s2, char* s3 = NULL)
{
    if (s1[0] < '0' || s1[0] > '9')
    {
        string givenInput(s1);
        string Ouput_parameter(s2);
        _cmd_1(algorithm, s1, s2);
    }
    else
    {
        if (s3 != NULL)
        {
            // cmd 2
            int size = atoi(s1);
            string order(s2);
            string Ouput_parameter(s3);
            _cmd_2(algorithm, size, order, Ouput_parameter);
        }
        else
        {
            // cmd 3
            int size = atoi(s1);
            string Ouput_parameter(s2);
            _cmd_3(algorithm, size, Ouput_parameter);
        }
    }
}

void _comparasion(char* algorithm1, char* algorithm2, char* s1, char* s2 = NULL)
{
    if (s1[0] < '0' || s1[0] > '9')
    {
        string givenInput(s1);
        _cmd_4(algorithm1, algorithm2, givenInput);
    }
    else {
        int size = atoi(s1);
        string order(s2);
        _cmd_5(algorithm1, algorithm2, size, order);
    }
}

int main(int argc, char* argv[])
{
    if (argc < 5)
        cout << "Invalid command - Too few arguments !" << endl;
    else
    {
        if (argc > 6)
            cout << "Invalid command - Too many arguments !" << endl;
        else
        {
            if (strcmp(argv[1], "-a") == 0) {
                cout << "ALGORITHM MODE" << endl;
                _algorithm(argv[2], argv[3], argv[4], argv[5]);
            }

            else {
                cout << "COMPARE MODE" << endl;
                _comparasion(argv[2], argv[3], argv[4], argv[5]);
            }
        }
    }
    return 0;
}
