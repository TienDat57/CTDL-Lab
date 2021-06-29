#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void _cmd_1(char* Algorithm, string given_Input, string Output_parameter)
{
    cout << "loading command line 1..." << endl;
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
            if (strcmp(argv[1], "-a") == 0)
                _algorithm(argv[2], argv[3], argv[4], argv[5]);
            else
                _comparasion(argv[2], argv[3], argv[4], argv[5]);
        }
    }
    return 0;
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