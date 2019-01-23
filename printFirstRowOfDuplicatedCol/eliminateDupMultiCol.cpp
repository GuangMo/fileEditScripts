// eliminateDupMultiCol.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// printNoDup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <atlstr.h>
#include <string>
#include <list>

int main()
{
    std::string line;
    std::string inputFileName; 
    int colToNoDup;
    std::list<CStringA> noDupList;

    /* Get user inputs */
    std::cout << "Please provide the name of input file and make sure it is at the current directory (eg: input.txt): "; 
    std::cin >> inputFileName;
    std::cout << "Please provide the index of column that you want to get rid of duplicates, starting from 1: "; 
    std::cin >> colToNoDup; 

    std::ifstream inputFile(inputFileName); 
    /* Read the input file and store distinct values in the list */
    if (inputFile.is_open())
    {
        while (std::getline(inputFile, line))
        {
            if (!line.empty())
            {
                CStringA CLine = line.c_str();
                int pos = 0;
                CStringA colString;
                for (int i = 0; i < colToNoDup; i++)
                {
                    colString = CLine.Tokenize(",", pos);
                    /* handle case where the line is not normal */
                    if (colString.IsEmpty())
                    {
                        break; 
                    }
                }

                colString.Trim(); 
                std::list<CStringA>::iterator findIter = std::find(noDupList.begin(), noDupList.end(), colString);
                if (findIter == noDupList.end())
                {
                    noDupList.push_back(colString);
                    std::cout << line << "\n"; 
                }
            }
        }
    }
    else
    {
        std::cout << "The input file " << inputFileName << " can not open, exiting \n"; 
    }

    return 0;
} 
