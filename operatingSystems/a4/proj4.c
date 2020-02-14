Project 4

#include <stdio.h>
#include <stdlib.h> 
#include<time.h> 

#define NUMOFPAGES 5
#define REFSTRINGLENGTH 20

void randomizer(int *arr);
void display(int *arr);
void fifo(int *arr, int numFrames);
int lru(int *arr, int numFrames);
int optimal(int *arr, int numFrames);
int findLRU(int *arr, int numFrames){
    int i, minimum = arr[0], pos = 0;
    for(i = 1; i < numFrames; ++i){
        if(arr[i] < minimum){
            minimum = arr[i];
            pos = i;
        }
    }
    return pos;
}

int main(){
   int numFrames = 0;
   int lruOptimal = 0;
   int optimalFaults = 0;
   int refString[20];


   printf("Welcome to Page Replacement Algorithm Tester.\n");
   printf("Please Enter The Number of Frames: ");
   scanf("%d",&numFrames);
   printf("The Number of Frames: %d\n", numFrames);
   printf("The Referene String: ");
   randomizer(refString);
   lruOptimal = lru(refString, numFrames);
   display(refString);
   optimalFaults = optimal(refString, numFrames);
   if(lruOptimal == optimalFaults){
       display(refString);
       fifo(refString, numFrames);
   }

}

void randomizer(int *arr){
    
    srand(time(0));
    int i = 0;
    for(i = 0; i < REFSTRINGLENGTH; i++){
        arr[i] = (rand() % (5 - 1 + 1)) + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void display(int *arr){
    
    int i = 0;
    printf("The Referene String: ");
    for(i = 0; i < REFSTRINGLENGTH; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void fifo(int *arr, int numFrames){

    int temp[numFrames];
    int i,j,s,fifoFaults=0;
    
    /*  Creates a temp array of size equal to the number of frames.
        and sets the temp indexes equal to -1. This allows us to 
        check for page faults. 
    */
    for(i = 0; i < numFrames; i++){
        temp[i] = -1;
    }
    printf("\n\t  FIFO Page Replacement Algorithm\n");
    printf("\n Page | \t Frame content \t | \tPage Faults ");
    printf("\n------------------------------------------------------");
    for(i = 0; i < REFSTRINGLENGTH; i++){
        s = 0;
        for(j = 0; j < numFrames; j++){
            if(arr[i] == temp[j]){
                s++;
                fifoFaults--;
            }
        }
    
    fifoFaults++;
    if((fifoFaults <= numFrames) && (s==0)){
        temp[i] = arr[i];
    }else if(s == 0){
        temp[(fifoFaults -1) % numFrames] = arr[i];
    }
    printf("\n");
    printf("\n %d    |",arr[i]);
    for(j = 0; j < numFrames; j++){
        printf("\t  %d", temp[j]);
    }
    printf("\t |    %d", fifoFaults);

    }
 printf("\n------------------------------------------------------");
 printf("\n FIFO: Total Number of Page Faults: %d\n\n\n",fifoFaults);

}
int lru(int *arr, int numFrames){
    
    int temp[numFrames];
    int usedPage[numFrames];
    int i,j,s,k,l,pos,counter = 0,minimum;
    int flag = 0, flag2 = 0,lruFaults = 0;
    
    /*  Creates a temp array of size equal to the number of frames.
        and sets the temp indexes equal to -1. This allows us to 
        check for page faults. 
    */
    for(i = 0; i < numFrames; i++){
        temp[i] = -1;
    }
    printf("\n\t  LRU Page Replacement Algorithm\n");
    printf("\n Page | \t Frame content \t | \tPage Faults ");
    printf("\n------------------------------------------------------");
    for(i = 0; i < REFSTRINGLENGTH; i++){
        flag = flag2 = 0;

        for(j = 0; j < numFrames; j++){
            if(temp[j] == arr[i]){
                counter++;
                usedPage[j] = counter;
                flag = flag2 = 1;
                break;
            }
        }
        if(flag == 0){
            for(j = 0; j < numFrames; j++){
                if(temp[j] == -1){
                    counter++;
                    lruFaults++;
                    temp[j] = arr[i];
                    usedPage[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
         if(flag2 == 0){
            
            pos = findLRU(usedPage,numFrames);
            counter++;
            lruFaults++;
            temp[pos] = arr[i];
            usedPage[pos] = counter;
        }
        printf("\n");
        printf("\n %d    |",arr[i]);
        for(j = 0; j < numFrames; j++){
            printf("\t %d", temp[j]);
        }
        printf("\t |    %d", lruFaults);
    }
    printf("\n------------------------------------------------------");
    printf("\n LRU: Total Number of Page Faults: %d\n\n\n",lruFaults);
    return lruFaults;
}
int optimal(int *arr, int numFrames){
    
    int temp[numFrames];
    int i,j,k,l,pos,max;
    int flag = 0,flag2 = 0,flag3 = 0,optimalFaults = 0;
    
    /*  Creates a temp array of size equal to the number of frames.
        and sets the temp indexes equal to -1. This allows us to 
        check for page faults. 
    */
    for(i = 0; i < numFrames; i++){
        temp[i] = -1;
    }
    printf("\n\t  Optimal Page Replacement Algorithm\n");
    printf("\n Page | \t Frame content \t | \tPage Faults ");
    printf("\n------------------------------------------------------");
    for(i = 0; i < REFSTRINGLENGTH; i++){
        flag = flag2 = 0;
        for(j = 0; j < numFrames; j++){
            if(temp[j] == arr[i]){
                flag = flag2 = 1;
                break;
            }
        }
        if(flag == 0){
            for(j = 0; j < numFrames; j++){
                if(temp[j] == -1){
                    optimalFaults++;
                    temp[j] = arr[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if(flag2 == 0){
            flag3 = 0;
            for(j = 0; j < numFrames; j++){
                temp[j] = -1;
                for(k = i + 1; k < numFrames; k++){
                    if(temp[j] == arr[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }
            for(j = 0; j < numFrames; j++){
                if(temp[j] == -1){
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            if(flag3 == 0){
                max = temp[0];
                pos = 0;
                for(j = 1; j < numFrames; j++){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            temp[pos] = arr[i];
            optimalFaults++;
        }
        printf("\n");
        printf("\n %d    |",arr[i]);
        for(j = 0; j < numFrames; j++){
            printf("\t %d", temp[j]);
        }
        printf("\t |    %d", optimalFaults);
    }
    printf("\n------------------------------------------------------");
    printf("\n Optimal: Total Number of Page Faults: %d\n\n\n",optimalFaults);
    return optimalFaults;
}



