/*
* * Author: Dillon Kern
*
* Professor: Dr. Xiao Chen
* The second program "sort.c" reads in a list of states from stdin and
* outputs them in an alphabetical order. Assume there are no more than 10
* states and the sequence is read until an EOF is encountered.
* the output should be abbreviations
*
*
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char state[10];
}State;
int main() {


    State tempState,stateArr[10];
    int i,j,counter = 0;

    while(counter < 10 && !feof(stdin))
    {

        scanf("%s",stateArr[counter].state);
        counter++;
    }

    for (i = 0; i < counter; i++)
    {
        for(j = 0; j < counter; j++)
        {
            if (strcmp(stateArr[i].state, stateArr[j].state) < 0)
            {
                strcpy(tempState.state, stateArr[i].state);
                strcpy(stateArr[i].state, stateArr[j].state);
                strcpy(stateArr[j].state, tempState.state);
            }
        }
    }

    for (i = 0; i < counter; i++)
    {
        printf("%s\n",stateArr[i].state);
    }
    return 0;
}