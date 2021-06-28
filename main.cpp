#include "data.h"
#include "sort.h"

using namespace std;

// Display Functions
void show_Order(string input_order){
    cout << "Input order: ";
    if (input_order == "-rand") cout << "Randomized" << endl;
    if (input_order == "-nsorted") cout << "Nearly sorted" << endl;
    if (input_order == "-sorted") cout << "Sorted" << endl;
    if (input_order == "-rev") cout << "Reversed" << endl;
}

void showAlgorithm(string algo) {
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

    switch (mode)
    {
    case 1:
        cout << "Algorithm: Selection Sort" << endl;
        break;
    case 2:
        cout << "Algorithm: Insertion Sort" << endl;
        break;
    case 3:
        cout << "Algorithm: Bubble Sort" << endl;
        break;
    case 4:
        cout << "Algorithm: Shaker Sort" << endl;
        break;
    case 5:
        cout << "Algorithm: Shell Sort" << endl;
        break;
    case 6:
        cout << "Algorithm: Heap Sort" << endl;
        break;
    case 7:
        cout << "Algorithm: Merge Sort" << endl;
        break;
    case 8:
        cout << "Algorithm: Quick Sort" << endl;
        break;
    case 9:
        cout << "Algorithm: Counting Sort" << endl;
        break;
    case 10:
        cout << "Algorithm: Radix Sort" << endl;
        break;
    case 11:
        cout << "Algorithm: Flash Sort" << endl;
        break;
    }
}

void WriteFile(string file_name, int* a, int n) {
    ofstream f(file_name, ios::out);
    if (f.fail()) cout << "Cannot open " << file_name << " file !" << endl;
    else {
        f << n << endl;
        for (int i = 0; i < n; i++) f << a[i] << " ";
        f.close();
    }
}

// Calculating Functions --------------------------------------------------------------------------------------
void generate_input_Order(int* a, int n, string input_Order) {
    int mode = -1;
    if (input_Order == "-rand") mode = 0;
    if (input_Order == "-nsorted") mode = 1;
    if (input_Order == "-sorted") mode = 3;
    if (input_Order == "-rev") mode = 2;
    if (mode != -1) GenerateData(a, n, mode);
}

void Output_res_algorithm(string para, double time, long long comp) {
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

void solveAlgoritm(string algo, int* a, int n, double& time, long long& cc) {
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
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 2:
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 3:
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 4:
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 5:
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 6:
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 7:
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 8:
        start = clock();
        QuickSort(a, 0, n - 1, cc);
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 9:
        start = clock();
        CountingSort(a, n, cc);
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 10:
        start = clock();
        // ...
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    case 11:
        start = clock();
        FlashSort(a, n, cc);
        end = clock();
        time = double(end - start) / CLOCKS_PER_SEC;
        break;
    }
}

int* ReadFile(string file_name, int& n) {
    ifstream f(file_name, ios::in);
    if (f.fail()) {
        cout << "Cannot open " << file_name << " file" << endl;
        return NULL;
    }
    f >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) f >> a[i];
    f.close();
    return a;

}

// Command line -------------------------------------------------------------------------------------------
void _cmd_1(char* Algorithm, string given_Input, string Output_parameter) {
    int n;
    int* a = ReadFile(given_Input, n);
    string algo(Algorithm);
    double time = 0;
    long long count_compare = 0;
    showAlgorithm(algo);
    solveAlgoritm(algo, a, n, time, count_compare);
    cout << "Input file: " << given_Input << endl;
    cout << "Input size: " << n << endl;
    Output_res_algorithm(Output_parameter, time, count_compare);
    WriteFile("output.txt", a, n);
}

void _cmd_2(char* Algorithm, int input_size, string input_order, string Output_parameter)
{
    string algo(Algorithm);
    showAlgorithm(algo);
    cout << "Input size: " << input_size << endl;
    int n = input_size;
    int* a = new int[n];
    double time = 0;
    long long count_compare = 0;
    show_Order(input_order);

    generate_input_Order(a, n, input_order);
    WriteFile("input.txt", a, n);
    solveAlgoritm(algo, a, n, time, count_compare);
    WriteFile("output.txt", a, n);
    Output_res_algorithm(Output_parameter, time, count_compare);
    delete[] a;
}

void _cmd_3(char* Algorithm, int input_size, string Output_parameter)
{
    string algo(Algorithm);
    showAlgorithm(algo);
    cout << "Input size: " << input_size << endl << endl;
    int n = input_size;
    int* a = new int[n];
    double time;
    long long count_compare;

    // -rand
    string input_order = "-rand";
    show_Order(input_order);
    time = 0;
    count_compare = 0;
    generate_input_Order(a, n, input_order);
    WriteFile("input_1.txt", a, n);
    solveAlgoritm(algo, a, n, time, count_compare);
    Output_res_algorithm(Output_parameter, time, count_compare);
    cout << endl;

    // -nsorted
    input_order = "-nsorted";
    show_Order(input_order);
    time = 0;
    count_compare = 0;
    generate_input_Order(a, n, input_order);
    WriteFile("input_2.txt", a, n);
    solveAlgoritm(algo, a, n, time, count_compare);
    Output_res_algorithm(Output_parameter, time, count_compare);
    cout << endl;

    // -sorted
    input_order = "-sorted";
    show_Order(input_order);
    time = 0;
    count_compare = 0;
    generate_input_Order(a, n, input_order);
    WriteFile("input_3.txt", a, n);
    solveAlgoritm(algo, a, n, time, count_compare);
    Output_res_algorithm(Output_parameter, time, count_compare);
    cout << endl;

    // -rev
    input_order = "-rev";
    show_Order(input_order);
    time = 0;
    count_compare = 0;
    generate_input_Order(a, n, input_order);
    WriteFile("input_4.txt", a, n);
    solveAlgoritm(algo, a, n, time, count_compare);
    Output_res_algorithm(Output_parameter, time, count_compare);
    cout << endl;
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

// Main ---------------------------------------------------------------------------------------------------
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
