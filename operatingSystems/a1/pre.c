/*
* Author: Dillon Kern
*
* Professor: Dr. Xiao Chen
* The first program "pre.c"
* should read in a list of states and their populations. You can make up a list. To be simple, you
* can use the abbreviation for each state. Assume there are at most 10 states in the list.
* The input ends when an EOF is encountered. The output of the program should display the states
* whose population is above 10 million..
* */
#include <stdio.h>
#include <string.h>
typedef struct
{
    char stateAbr[10];
    int pop;

} State;

int main()
{
    State stateArr[9];
    int count = 0;
    int i;

    while (!feof(stdin))
    {
        scanf("%s %d", stateArr[count].stateAbr, &stateArr[count].pop);
        count++;
    }

    for (i = 0; i < count; i++)
    {
        if (stateArr[i].pop >= 10.0){
            printf("%s\n", stateArr[i].stateAbr);
        }
    }
    return 0;
}