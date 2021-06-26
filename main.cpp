#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;


void Output_res_a(string para, double time, int comp) {
    int mode = 0;
    if (para == "-time") mode = 1;
    if (para == "-comp") mode = 2;
    if (para == "-both") mode = 3;
    cout << "--------------------------" << endl;
    switch (mode)
    {
    case 1:
        cout << "Running time: " << time << endl;
        break;
    case 2:
        cout << "Comparisions: " << comp << endl;
        break;
    case 3:
        cout << "Running time: " << time << endl;
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
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 9:
        cout << "Algorithm: Counting Sort" << endl;
        start = clock();
        // ...
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
        // ...
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

        if (fo.fail()) {
            cout << "Cannot open output.txt file !" << endl;
        }
        else {
            for (int i = 0; i < n; i++) {
                fo << a[i] << " ";
            }
        }
        Output_res_a(Output_parameter, time, count_compare);
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
