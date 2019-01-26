// findMatchForSingleCol.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <atlstr.h>
#include <string>
#include <list>

using namespace std; 
int main()
{
    string line;
    string inputFileNameA;
    string inputFileNameB;
    list<CStringA> inputsFromFileA; 

    cout << "Please provide the name of first input file and make sure it is at the current directory (eg: inputA.txt): ";
    cin >> inputFileNameA;
    cout << "Please provide the name of 2nd input file and make sure it is at the current directory (eg: inputB.txt): ";;
    cin >> inputFileNameB;

    ifstream inputFileA(inputFileNameA);
    if (inputFileA.is_open())
    {
        while (getline(inputFileA, line))
        {
            CStringA CLine = line.c_str();
            CLine.Trim(); 
            list<CStringA>::iterator findIter = find(inputsFromFileA.begin(), inputsFromFileA.end(), CLine);
            if (findIter == inputsFromFileA.end())
            {
                inputsFromFileA.push_back(CLine); 
            }
        }
    }
    else
    {
        std::cout << "The 1st input file " << inputFileNameA << " can not open, exiting \n";
    }

    ifstream inputFileB(inputFileNameB);
    if (inputFileA.is_open())
    {
        while (getline(inputFileB, line))
        {
            CStringA CLine = line.c_str();
            CLine.Trim();
            list<CStringA>::iterator findIter = find(inputsFromFileA.begin(), inputsFromFileA.end(), CLine);
            if (findIter == inputsFromFileA.end())
            {
                cout << "The 2nd file " << inputFileNameA << " does not contain " << CLine << "\n";
            }
        }
    }
    else
    {
        std::cout << "The 1st input file " << inputFileNameA << " can not open, exiting \n";
    }
}
