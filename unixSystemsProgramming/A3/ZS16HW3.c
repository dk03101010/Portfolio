#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGE_NUMBERS 1
#define MESSAGE_LENGTH 94

void encrypter(char message[MESSAGE_NUMBERS][MESSAGE_LENGTH], int key){
    //initialize to 0
    char *i = &message[0][0];
    char *shift = &message[0][0];

    while(*shift != 0) {
        *shift = *shift + key;
        shift++;
    }
     i = i + 32;
    shift = i;
}

void decrypter(char message[MESSAGE_NUMBERS][MESSAGE_LENGTH], int key){
    //initialize to 0
    char *i = &message[0][0];
    char *shift = &message[0][0];

    while(*shift !=0) {
        *shift = *shift - key;
        shift++;
    }
    i = i + 32;
    shift = i;
}

int asciiVal(char message[]){
    int sum = 0, i, len;
    len = strlen(message);

    for (i = 0; i < len; i++)
    {
        sum = sum + message[i];
    }
    return sum;
}

void copyString(char s1[], char s2[]){
    int i;
    i=0;
    while (s1[i] != '\0'){
        s2[i] = s1[i];
        i++;
    }
    s2[i]= '\0';
    }
 void charConverter(char message[]){
    int n = 0;

    while(message[n] !='\0'){
        if (message[n] >= 'A' && message[n] <= 'Z'){
            message[n] = message[n] +32;
        }else if(message[n] >= 'a' && message[n] <= 'z'){
                message[n] = message[n] - 32;
        }
        n++;
    }
    printf("Converting Letters %s\n", message);
}

charCount(char message[]){
    int digitCount, upperCase, lowerCase, alphaCount, specialChar, i;

    digitCount = 0;
    upperCase = 0;
    lowerCase = 0;
    alphaCount = 0;
    specialChar = 0;

    for (i = 0; message[i] != '\0'; i++){
        if (message[i] >= '0' && message[i] <= '9'){
            digitCount++;
        }else if (message[i] >= 'A' && message[i] <= 'Z'){
            upperCase++;
        }else if(message[i] >= 'a' && message[i] <= 'z'){
            lowerCase++;
        } else{
            specialChar++;
        }
    }
    alphaCount = lowerCase + upperCase;
    printf("\n Number of Capital Letters: %d \n"
           "Number of Small Letters: %d\n"
           "Number of Digits: %d\n"
           "Number of Symbols: %d\n"
           "Number of Characters in message: %d \n",
           upperCase, lowerCase, digitCount,specialChar, alphaCount);
}
void concat(char m1[], char m2[]){
    int i, j;
    i = strlen(m1);

    for(j = 0; m2[j] != '\0'; i++, j++) {
        m1[i] = m2[i];
    }
    m1[i] = '\0';
    printf("Concatenation of original and encrypted text: %s \n", m1 ,"\n");
}
int main() {
    int choice[10];
    int key;
    char input[MESSAGE_LENGTH];
    char stringCopy[MESSAGE_LENGTH];
    char strings[MESSAGE_NUMBERS][MESSAGE_LENGTH];
    char strings2[MESSAGE_NUMBERS][MESSAGE_LENGTH];

    printf("NAME: Dillon Kern CS 4350 - Unix System Programming\n");
    printf("Serial Number: 16\n");
    printf("Assignment Number: 03\n");
    printf("Due Date: 3/04/2020\n");
    printf("Welcome to cryptography\n\n");

    do {
        printf("What would you like to do to a message? (encrypt, decrypt, exit)?\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf(" %[^\n]s", choice);
        getchar();

        int asciiInt = asciiVal(choice);

        switch (asciiInt) {
            case 773:
                printf("\n Enter your message: \n");
                fgets(input, sizeof(input), stdin);
                input[strlen(input) - 1] = '\0';
                copyString(input, strings[0]);
                copyString(input, strings2[0]);

                printf("\n Enter the key number (1-93) \n");
                scanf("%d", &key);

                if (key <= 1 || key >= 93) {
                    printf("\nInvalid key, try again \n");
                    break;
                }
                charCount(input);
                charConverter(input);

                encrypter(strings, key);
                printf("The decrypted message is: \n");
                printf("%s \n", strings);

                concat(strings2, strings);
                break;
            case 763:
                printf("\nEnter the key number (1-93)");
                scanf("%d", &key);
                if (key <= 1 || key >= 93) {
                    printf("\nInvalid key, try again \n");
                    break;
                }
                getchar();

                printf("\nEnter your message: \n");
                fgets(input, sizeof(input), stdin);
                input[strlen(input) - 1] = '\0';
                copyString(input, strings[0]);
                copyString(input, strings2[0]);

                charCount(input);

                charConverter(input);
                decrypter(strings, key);
                printf("%s\n", strings);
                concat(strings2, strings);

                break;
            case 442:
                printf("\nDillon Kern Security Systems\n");
                printf("3-04-2020");
                exit(0);
                break;
            default:
                printf("Invalid Input\n");
        }
    } while (1);
}