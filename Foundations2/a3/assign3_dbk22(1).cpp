// File Name: assign3_dbk22.cpp
//
// Author: Dillon Kern
// Date: 10/18/2017
// Assignment Number: 3
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//
// implements and tests 4 functions that use
// pointers, and dynamic memory Allocation.
//

#include <iostream>

using namespace std;

bool isSorted (int*, int);
int *duplicateArray (int*, int);
double chain(int,int*, int*);
int *grow(int*, int);
int *subArray(int*, int, int);


//***********************************************************
// function name: Main
// main is used as a driver. Every function
//is called within main and is outputted through
//main.
//
//**********************************************************

int main()
{
    int data[]= {1,2,3,4,5,6,7,8};


    cout << "test data array 1: 1,2,3,4,5,6,7,8"<<endl;
    cout << "Expected result: true" << endl;
    cout << "Actual Result: ";

    bool result= isSorted(data, 8);

    if (result == true)
    {
        cout << "True" << endl;
    }
    else
        cout << "False" <<endl;
//data2

    int data2[]= {8,7,6,5,4,3,2,1};


    cout << "test data array 1: 8,7,6,5,4,3,2,1"<<endl;
    cout << "Expected result: false" << endl;
    cout << "Actual Result: ";

    bool result2= isSorted(data2, 8);

    if (result2 == true)
    {
        cout << "True" << endl;
    }
    else
        cout << "False" <<endl;

//data 3

    int data3[]= {1,2,3,5,4,6,7,8};


    cout << "test data array 1: 1,2,3,5,4,6,7,8"<<endl;
    cout << "Expected result: false" << endl;
    cout << "Actual Result: ";

    bool result3= isSorted(data3, 8);

    if (result3 == true)
    {
        cout << "True" << endl;
    }
    else
        cout << "False" <<endl;



    int feet = 4;
    int inches =5;
    double totalInches;
// Chain

    double finalResult =  chain(53,&feet,&inches);

    cout << "Testing chain for 53 inches:"<<endl;
    cout << "Expected Result: 15.46 feet: 4 inches: 5"<<endl;
    cout << "Actual Results: " << finalResult << " feet: " << feet
         << " inches: " << inches <<endl;



//grow function
    const int SIZE = 9;
    int growData[SIZE]= {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *newgrowResult=  grow (growData,  9);
    cout << "Testing grow:" <<endl;
    cout << "Test data: 1 2 3 4 5 6 7 8 9" <<endl;
    cout << "Expected result: 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9" <<endl;
    cout << "Actual result: ";

    for (int i =0; i < 18; i++)
    {
        cout<<newgrowResult[i]<<" ";
    }
    cout << endl;

//subArray Function
    int len=4;
    int array[9]= {1,2,3,4,5,6,7,8,9};
    int start=5;

    int *subArrayResult=subArray( array, start,len);
    cout << "testing subArray: "<<endl;
    cout << "test data: 1 2 3 4 5 6 7 8 9"<<endl;
    cout << "start: 5 length: 4"<<endl;
    cout << "expected result : 6 7 8 9"<<endl;
    cout << "Actual result: ";
    for (int i =0; i < len; i++)
    {
        cout<<subArrayResult[i]<<" ";
    }



    return 0;


}

//***********************************************************
// function name: isSorted checks to see if the
// given data is sorted in Ascending order.
// param data: inputs the data being given from main
// param2 size: passes in the number of integers in the data
//
// returns: the result of true or false to main telling whether
// the data is properly sorted in ascending order.
//**********************************************************

bool isSorted (int *data, int size)
{
    int first;
    int second;
    bool result= true;

    for (int i=0; i < size; i++)
    {
        first= *(data + i);
        second= *(data + (i+1));

        if (first > second)
        {
            result = false;
        }


    }

    return result;


}
//***********************************************************
// chain: checks to see if the chain is 53 inches in length.
//
// param-1: total inches passes in the size of the chain total (53 inches)
// param-2 feet: points to the feet variable in main.
// param-3 inches: points to the inches variable in main and passes
// in the data.
// returns: the feet and inches.
//**********************************************************


double chain(int totalInches,int *feet, int *inches)
{

    *feet = totalInches/12;
    *inches = totalInches%12;

    return *feet*3.49+ *inches*.30;

}
//***********************************************************
// grow function: takes an array of integers and its size as
// arguments. creates an array that is twice the size of the array
// and creates a new array that's twice the size of the argument array.
// param-1 grow Data passes in the data from the array
// param-2 size passes in the number of elements that are being worked with.
//
// returns: returns the newGrowArray
//**********************************************************

int *grow (int *growData, int size)
{
    int *newgrowArray;

    newgrowArray = new int [(size * 2)];

    int k = 0;

    for (int i =0; i < size; i++)
    {
        newgrowArray[k] = growData[i];
        k++;
        newgrowArray[k] = growData[i];
        k++;
    }
    return newgrowArray;
}

//***********************************************************
// subArray: Creates a new arrray that is a copy of the elements
// from the original array starting at the start index.
// param-1 array points to the array in main and passes in the
// data.
// param-2 start passes in where the array should start.
// param-3 passes how long the array should print.
// returns: result of the array after it is duplicated.
//**********************************************************


int *subArray(int *array, int start, int length)
{

    int arr[length];
    for (int i=0; i<=length; i++)
    {
        arr[i]=array[start];
        start++;
    }

    int *result=duplicateArray(arr, length);

    return result;
}


//***********************************************************
// function name: dupluicate Array
// param-1 arr points to the array from subarray and passes in the
// elements.
// param-2 size passes in the number of elements that will be worked with
//
// returns: newArray returns the new array after duplication.
//**********************************************************


int *duplicateArray (int *arr, int size)
{

    int *newArray;
    if (size <= 0)
        return NULL;

    newArray = new int [size];

    for (int i = 0; i < size; i++)
        newArray[i] = arr[i];

    return newArray;
}



