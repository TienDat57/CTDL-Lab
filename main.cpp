#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include"dataGenerator.h"

using namespace std;

enum PARAMETER{
    -comp = 1
}

void Ouput_res(char* para, double time, int comp){
    switch (para)
    {
        case "-comp":
    }
}

void solveAlgoritm(string algo, int*a , int n){
   // cout << 
}

void _cmd_1(char* Algorithm, string given_Input, string Output_parameter)
{
    ifstream fi(given_Input, ios::in);
    ofstream fo("output.txt", ios::out);
    if (fi.fail()){
        cout << "Cannot open " << given_Input << " file !" << endl;
    }
    else {
        int n;
        fi >> n;
        int *a=new int[n];
        for (int i=0; i<n; i++) fi >> a[i];

        string algo(Algorithm);
        solveAlgoritm(algo, a, n);
    
        if (fo.fail()){
            cout << "Cannot open output.txt file !" << endl;
        }
        else {
            for (int i=0;i<n;i++){
                fo << a[i] << " ";
            }
        }
        fi.close();

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
            if (strcmp(argv[1], "-a") == 0){
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
