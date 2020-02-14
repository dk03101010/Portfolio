//Author: Dillon Kern
#include <stdio.h>
#include <string.h>

int main(){
  //Stuct to store state abbreviation and population
  typedef struct{
    char state[3];
    int pop;
  } statePop;

  //Create struct array to hold entered values
  statePop enteredVals[10];

  //Initialize array index 0 to initial values
  strcpy(enteredVals[0].state, "ZZ");
  enteredVals[0].pop = -1;

  //Use i as counter
  int i;

  //Initialize remaining array elements to initial values
  for(i = 1; i < 10; i++)
    enteredVals[i] = enteredVals[0];

  //Reset counter
  i = 0;

  //printf("Enter state abbreviations and their populations:\n");

  //Read user input until EOF or 10 elements are entered
  while( (scanf("%s %d", &enteredVals[i].state, &enteredVals[i].pop)) != EOF && i < 10)
    i++;

  //Reset counter
  i = 0;

  //printf("States with populations greater than 10 million:\n");

  while( (i < 10) && enteredVals[i].pop != -1){
    if (enteredVals[i].pop > 10)
      printf("%s\n", enteredVals[i].state);

    i++;
  }
}
