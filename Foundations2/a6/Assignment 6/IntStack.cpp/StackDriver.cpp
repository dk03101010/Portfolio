// File Name: assign6_dbk22.cpp
//
// Author: Dillon Kern
// Date: 12/06/2017
// Assignment Number: 6
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//
// given a text file, the program will determine
// all the parenthesis, braces, and square brackets match
// and are nested properly.

#include <iostream>
#include "IntStack.h"
#include <fstream>

using namespace std;
//***********************************************************
//char review(char c)
//
//helper function that is used to check.
//***********************************************************

char review(char c)
{
    if (c == '{') return '}';
    if (c == '(') return ')';
    if (c == '[') return ']';
    return '@';
}

//***********************************************************
//Main
//
//Implements the input file
//***********************************************************
int main()
{
    cout << "Enter filename to check: ";
    string filename;
    cin >> filename;



    ifstream fin;

    fin.open(filename.c_str());

    if (!fin)
    {
        cout << "ERROR - File failed to open" << endl;
        fin.close();

        return -1;
    }
    IntStack Stack;
    char nextChar;

    while (fin >> nextChar)
    {
        char checker;
        switch (nextChar)
        {

        case '{':
        case '[':
        case '(':
            if (!Stack.isFull())
                Stack.push(nextChar);
            else
            {
                cout << "Error: Size reached"<<endl;
                return -1;
            }
            break;
        case '}':

            if (Stack.isEmpty())
            {
                cout << "Error: unmatched }" << endl;
                fin.close();
                return -1;
            }

            checker = Stack.pop();
            if (checker != '{')
            {
                cout << "Error: expected " << review(checker) << " but found }" << endl;
                fin.close();
                return -1;
            }
            break;
        case ']':

            if (Stack.isEmpty())
            {
                cout << "Error: unmatched ]" << endl;
                fin.close();
                return -1;
            }

            checker = Stack.pop();
            if (checker != '[')
            {
                cout << "Error: expected " << review(checker) << " but found ]" << endl;
                fin.close();
                return -1;
            }
            break;


        case ')':

            if (Stack.isEmpty())
            {
                cout << "Error: unmatched )" << endl;
                fin.close();
                return -1;
            }

            checker = Stack.pop();
            if (checker != '(')
            {
                cout << "Error: expected " << review(checker) << " but found )" << endl;
                fin.close();
                return -1;

            }
            break;
        default:
            break;
        }
    }
    if (!Stack.isEmpty())
    {
        char top;
        while (!Stack.isEmpty())
        {
            top = Stack.pop();
            switch(top)
            {
            case '{':
                cout<< "Error: missing }" <<endl;
                break;
            case '[':
                cout<< "Error: missing ]" << endl;
                break;
            case '(':
                cout<< "Error: missing )" <<endl;
                break;
            }
        }
    }
// closing files
    fin.close();
    return 0;
}





