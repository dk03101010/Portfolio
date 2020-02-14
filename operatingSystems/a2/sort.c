#include <stdio.h>
#include <string.h>

int main(){

  char state[10][3], temp[3];
  int i =0, j, k;

  //Initialize elements to a default value
  strcpy(temp, "  ");

  for (j = 0; j < 10; j++)
    strcpy(state[j], "  ");

  //printf("Enter states:\n");

  //Read states from stdin
  while( scanf("%s", &state[i]) != EOF && i < 10 )
    i++;

  //Sort the array in alphabetical order
  //Sort assumes all abbreviations are uppercase
  for (j = 0; j < i - 1; j++)
    for (k = j + 1; k < i; k++)
      if (strcmp(state[j], state[k]) > 0){
        strcpy(temp, state[j]);
        strcpy(state[j], state[k]);
        strcpy(state[k], temp);
      }

  i = 0;

  //Print the sorted array
  while(strcmp(state[i], "  ") && i < 10){
    printf("%s\n", state[i]);
    i++;
  }
}
