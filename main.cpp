#include "data.h"
#include "sort.h"
#include <iomanip>

using namespace std;

// Display Functions
void show_Order(string input_order)
{
    cout << "Input order: ";
    bool check = 0;
    if (input_order == "-rand")
    {
        cout << "Randomized" << endl;
        check = 1;
    }
    if (input_order == "-nsorted")
    {
        cout << "Nearly sorted" << endl;
        check = 1;
    }
    if (input_order == "-sorted")
    {
        cout << "Sorted" << endl;
        check = 1;
    }
    if (input_order == "-rev")
    {
        cout << "Reversed" << endl;
        check = 1;
    }
    // if (check == 0) cout << "Can't operate " << input_order << endl;
}

void showAlgorithm(string algo)
{
    bool check = 0;
    if (algo == "selection-sort")
    {
        cout << "Selection Sort";
        check = 1;
    }
    if (algo == "insertion-sort")
    {
        cout << "Insertion Sort";
        check = 1;
    }
    if (algo == "bubble-sort")
    {
        cout << "Bubble Sort";
        check = 1;
    }
    if (algo == "shaker-sort")
    {
        cout << "Shaker Sort";
        check = 1;
    }
    if (algo == "shell-sort")
    {
        cout << "Shell Sort";
        check = 1;
    }
    if (algo == "heap-sort")
    {
        cout << "Heap Sort";
        check = 1;
    }
    if (algo == "merge-sort")
    {
        cout << "Merge Sort";
        check = 1;
    }
    if (algo == "quick-sort")
    {
        cout << "Quick Sort";
        check = 1;
    }
    if (algo == "counting-sort")
    {
        cout << "Counting Sort";
        check = 1;
    }
    if (algo == "radix-sort")
    {
        cout << "Radix Sort";
        check = 1;
    }
    if (algo == "flash-sort")
    {
        cout << "Flash Sort";
        check = 1;
    }
    if (check == 0)
        cout << "Error: unknown sorting algorithm!";
}

void WriteFile(string file_name, int *a, int n)
{
    ofstream f(file_name, ios::out);
    if (f.fail())
        cout << "Cannot open " << file_name << " file !" << endl;
    else
    {
        f << n << endl;
        for (int i = 0; i < n; i++)
            f << a[i] << " ";
        f.close();
    }
}

void Output_res_algorithm(string para, double time, long long comp)
{
    int mode = 0;
    if (para == "-time")
        mode = 1;
    if (para == "-comp")
        mode = 2;
    if (para == "-both")
        mode = 3;
    cout << "--------------------------" << endl;
    switch (mode)
    {
    case 1:
        cout << fixed << setprecision(3) << "Running time: " << time << 's' << endl;
        break;
    case 2:
        cout << "Comparisions: " << comp << endl;
        break;
    case 3:
        cout << fixed << setprecision(3) << "Running time: " << time << 's' << endl;
        cout << "Comparisions: " << comp << endl;
        break;
    default:
        cout << "Error: unknown output parameter!" << endl;
        break;
    }
}

void Output_res_compare(string para, double time1, long long comp1, double time2, long long comp2)
{
    int mode = 0;
    if (para == "-time")
        mode = 1;
    if (para == "-comp")
        mode = 2;
    if (para == "-both")
        mode = 3;
    cout << "--------------------------" << endl;
    switch (mode)
    {
    case 1:
        cout << fixed << setprecision(3) << "Running time: " << time1 << 's' << " | " << time2 << 's' << endl;
        break;
    case 2:
        cout << "Comparisions: " << comp1 << " | " << comp2 << endl;
        break;
    case 3:
        cout << fixed << setprecision(3) << "Running time: " << time1 << 's' << " | " << time2 << 's' << endl;
        cout << "Comparisions: " << comp1 << " | " << comp2 << endl;
        break;
    default:
        cout << "Error: unknown output parameter!" << para << endl;
        break;
    }
}

// Calculating Functions --------------------------------------------------------------------------------------
void generate_input_Order(int *a, int n, string input_Order)
{
    int mode = -1;
    if (input_Order == "-rand")
        mode = 0;
    if (input_Order == "-nsorted")
        mode = 1;
    if (input_Order == "-sorted")
        mode = 3;
    if (input_Order == "-rev")
        mode = 2;
    GenerateData(a, n, mode);
    if (mode == -1)
        a = NULL;
}

void solveAlgoritm(string algo, int *a, int n, double &time, long long &cc, string para)
{
    int mode = 0;
    if (algo == "selection-sort")
        mode = 1;
    if (algo == "insertion-sort")
        mode = 2;
    if (algo == "bubble-sort")
        mode = 3;
    if (algo == "shaker-sort")
        mode = 4;
    if (algo == "shell-sort")
        mode = 5;
    if (algo == "heap-sort")
        mode = 6;
    if (algo == "merge-sort")
        mode = 7;
    if (algo == "quick-sort")
        mode = 8;
    if (algo == "counting-sort")
        mode = 9;
    if (algo == "radix-sort")
        mode = 10;
    if (algo == "flash-sort")
        mode = 11;

    int mode_para = 0;
    if (para == "-time")
        mode_para = 1;
    if (para == "-comp")
        mode_para = 2;
    if (para == "-both")
        mode_para = 3;

    int *temp = new int[n];
    for (int i = 0; i < n; i++)
        temp[i] = a[i];

    cc = 0;
    clock_t start, end;
    switch (mode)
    {
    case 1:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            SelectionSort_time(a, n);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2) SelectionSort_compare(temp, n, cc);
            break;
    case 2:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            InsertionSort_time(a, n);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2) InsertionSort_compare(temp, n, cc);
            break;
    case 3:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            BubbleSort_time(a, n);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2) BubbleSort_compare(temp, n, cc);
            break;
    case 4:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            ShakerSort_time(a, n);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2) 
            ShakerSort_compare(temp, n, cc);
            break;
    case 5:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            shellSort_time(a, n);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2)
            shellSort_compare(temp, n, cc);
        break;
    case 6:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            heapSort_time(a, n);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2)
            heapSort_compare(temp, n, cc);
        break;
    case 7:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            MergeSort_time(a, 0, n -1);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2) MergeSort_compare(temp, 0, n - 1, cc);
            break;
    case 8:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            QuickSort_time(a, 0, n - 1);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2)
            QuickSort_compare(temp, 0, n - 1, cc);
        break;
    case 9:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            CountingSort_time(a, n);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2)
            CountingSort_compare(temp, n, cc);
        break;
    case 10:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            radixSort_time(a, n);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2)
            radixSort_compare(temp, n, cc);
        break;
    case 11:
        if (mode_para == 3 || mode_para == 1)
        {
            start = clock();
            FlashSort_time(a, n);
            end = clock();
            time = double(end - start) / CLOCKS_PER_SEC;
            mode_para--;
        }
        if (mode_para == 2)
            FlashSort_compare(temp, n, cc);
        break;
    }
    delete[] temp;
}

int *ReadFile(string file_name, int &n)
{
    ifstream f(file_name, ios::in);
    if (f.fail())
    {
        cout << "Cannot open " << file_name << " file" << endl;
        return NULL;
    }
    f >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        f >> a[i];
    f.close();
    return a;
}

// Command line -------------------------------------------------------------------------------------------
void _cmd_1(char *Algorithm, string given_Input, string Output_parameter)
{
    cout << "Algorithm: ";
    string algo(Algorithm);
    showAlgorithm(algo);
    cout << endl;
    int n;
    int *a = ReadFile(given_Input, n);
    double time = 0;
    long long count_compare = 0;
    solveAlgoritm(algo, a, n, time, count_compare, Output_parameter);
    cout << "Input file: " << given_Input << endl;
    cout << "Input size: " << n << endl;
    Output_res_algorithm(Output_parameter, time, count_compare);
    WriteFile("output.txt", a, n);
}

void _cmd_2(char *Algorithm, int input_size, string input_order, string Output_parameter)
{
    cout << "Algorithm: ";
    string algo(Algorithm);
    showAlgorithm(algo);
    cout << endl;
    cout << "Input size: " << input_size << endl;
    int n = input_size;
    int *a = new int[n];
    double time = 0;
    long long count_compare = 0;
    show_Order(input_order);
    generate_input_Order(a, n, input_order);
    WriteFile("input.txt", a, n);
    solveAlgoritm(algo, a, n, time, count_compare, Output_parameter);
    WriteFile("output.txt", a, n);
    Output_res_algorithm(Output_parameter, time, count_compare);
    delete[] a;
}

void _cmd_3(char *Algorithm, int input_size, string Output_parameter)
{
    cout << "Algorithm: ";
    string algo(Algorithm);
    showAlgorithm(algo);
    cout << endl;
    cout << "Input size: " << input_size << endl
         << endl;
    int n = input_size;
    int *a = new int[n];
    double time;
    long long count_compare;

    // -rand
    string input_order = "-rand";
    show_Order(input_order);
    time = 0;
    count_compare = 0;
    generate_input_Order(a, n, input_order);
    WriteFile("input_1.txt", a, n);
    solveAlgoritm(algo, a, n, time, count_compare, Output_parameter);
    Output_res_algorithm(Output_parameter, time, count_compare);
    cout << endl;

    // -nsorted
    input_order = "-nsorted";
    show_Order(input_order);
    time = 0;
    count_compare = 0;
    generate_input_Order(a, n, input_order);
    WriteFile("input_2.txt", a, n);
    solveAlgoritm(algo, a, n, time, count_compare, Output_parameter);
    Output_res_algorithm(Output_parameter, time, count_compare);
    cout << endl;

    // -sorted
    input_order = "-sorted";
    show_Order(input_order);
    time = 0;
    count_compare = 0;
    generate_input_Order(a, n, input_order);
    WriteFile("input_3.txt", a, n);
    solveAlgoritm(algo, a, n, time, count_compare, Output_parameter);
    Output_res_algorithm(Output_parameter, time, count_compare);
    cout << endl;

    // -rev
    input_order = "-rev";
    show_Order(input_order);
    time = 0;
    count_compare = 0;
    generate_input_Order(a, n, input_order);
    WriteFile("input_4.txt", a, n);
    solveAlgoritm(algo, a, n, time, count_compare, Output_parameter);
    Output_res_algorithm(Output_parameter, time, count_compare);
    cout << endl;
}

void _cmd_4(char *Algorithm1, char *Algorithm2, string givenInput)
{
    cout << "Algorithm: ";
    string algo1(Algorithm1), algo2(Algorithm2);
    showAlgorithm(algo1);
    cout << " | ";
    showAlgorithm(algo2);
    cout << endl;
    cout << "Input file : " << givenInput << endl;

    int n = 0;
    int *a1 = ReadFile(givenInput, n);
    int *a2 = ReadFile(givenInput, n);
    long long compare1 = 0, compare2 = 0;
    double time1 = 0, time2 = 0;
    cout << "Input size : " << n << endl;

    solveAlgoritm(algo1, a1, n, time1, compare1, "-both");
    solveAlgoritm(algo2, a2, n, time2, compare2, "-both");
    Output_res_compare("-both", time1, compare1, time2, compare2);

    delete[] a1;
    delete[] a2;
}

void _cmd_5(char *Algorithm1, char *Algorithm2, int input_size, string input_order)
{
    cout << "Algorithm: ";
    string algo1(Algorithm1), algo2(Algorithm2);
    showAlgorithm(algo1);
    cout << " | ";
    showAlgorithm(algo2);
    cout << endl;
    show_Order(input_order);
    int n = input_size;
    int *a1 = new int[n];
    long long compare1 = 0, compare2 = 0;
    double time1 = 0, time2 = 0;
    generate_input_Order(a1, n, input_order);
    WriteFile("input.txt", a1, n);
    int *a2 = ReadFile("input.txt", n);
    solveAlgoritm(algo1, a1, n, time1, compare1, "-both");
    solveAlgoritm(algo2, a2, n, time2, compare2, "-both");
    Output_res_compare("-both", time1, compare1, time2, compare2);
    delete[] a1;
    delete[] a2;
}

void _algorithm(char *algorithm, char *s1, char *s2, char *s3 = NULL)
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

void _comparasion(char *algorithm1, char *algorithm2, char *s1, char *s2 = NULL)
{
    if (s1[0] < '0' || s1[0] > '9')
    {
        string givenInput(s1);
        _cmd_4(algorithm1, algorithm2, givenInput);
    }
    else
    {
        int size = atoi(s1);
        string order(s2);
        _cmd_5(algorithm1, algorithm2, size, order);
    }
}

// main ---------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    if (argc < 5)
        cout << "Invalid command - Too few arguments !" << endl;
    else
    {
        if (argc > 6)
            cout << "Invalid command - Too many arguments !" << endl;
        else
        {
            if (strcmp(argv[1], "-a") == 0)
            {
                cout << "ALGORITHM MODE" << endl;
                _algorithm(argv[2], argv[3], argv[4], argv[5]);
            }
            else
            {
                if (strcmp(argv[1], "-c") == 0)
                {
                    cout << "COMPARE MODE" << endl;
                    _comparasion(argv[2], argv[3], argv[4], argv[5]);
                }
                else
                    cout << "Error: unknown mode" << endl;
            }
        }
    }
    return 0;
}