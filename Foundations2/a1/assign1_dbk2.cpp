// File Name: assign1_dbk22.cpp
//
// Author: Dillon Kern
// Date: 09/20/2017
// Assignment Number: 1
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//
//initiatialize an structure array called Rat
//Then display the information, and tell the average weight,
// and display the slowest and the fastest rats.
#include <iostream>
#include <iomanip>

using namespace std;


struct Rat
{
    string name;
    double weight;
    int time;
};

double AverageWeight (const int, Rat[]);
void RatTime(const int NUM_RATS, Rat RatInfo[], int &fast, int &slow);

int main ()
{


const int NUM_RATS = 9;
    int f=0,s=0;
Rat RatInfo[NUM_RATS]= {
        {"Ben", 6.6, 29},
        {"Fred", 5.8, 31},
        {"Splinter", 7.7,33},
        {"Lima Bean", 6.5, 27},
        {"Black Bean", 5.8, 31},
        {"Pinto Bean", 7.7, 33},
        {"Skat", 6.5, 29},
        {"Big Pook", 9.8, 34},
        {"Tiger", 7.7, 33}
    };
double average= AverageWeight (NUM_RATS,RatInfo);
    RatTime(NUM_RATS, RatInfo,f,s);


    for (int i=0; i < NUM_RATS; i++){
        cout << RatInfo[i].name<< ",";
        cout << RatInfo[i].weight<<",";
        cout << RatInfo[i].time<<endl;
    }

    cout << "Average Weight:" <<average<<endl;
    cout << "Fastest Rat:"<<RatInfo[s].name<<RatInfo[s].time<<endl;
    cout << "Slowest Rat:"<<RatInfo[f].name <<RatInfo[f].time<<endl;



    return 0;
}


double AverageWeight (const int NUM_RATS, Rat RatInfo[])
{
    double average=0,total=0.0;
    for (int i=0; i < NUM_RATS; i++)
    {
        total= total +RatInfo[i].weight;
        average = total/9.0;


    }
    return total;
}




void RatTime(const int NUM_RATS, Rat RatInfo[], int &fast, int &slow ){

    for (int i=1; i < NUM_RATS; i++){
        if ( RatInfo[i].time>RatInfo[fast].time)
            fast=i;

        if ( RatInfo[i].time<RatInfo[slow].time)
            slow=i;


    }


}
