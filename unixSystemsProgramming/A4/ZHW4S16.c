/** NAME: Dillon Kern  CS 4350 – Unix Systems Programming
Serial Number: 16
Assignment Number: 4
Due Date: 4/6/2020
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define NUM_COUNT 7

void done();

int main() {
    FILE *fp;
    FILE *op;
    FILE *op2;

    int n, i;
    char str[100];
    char str1;
    char character;

    fp = fopen("zp4in.txt", "w+");
    if (fp == NULL) {
        perror("Error in opening file");
        return (-1);
    }

    system("echo File Manipulation Program; echo");

        printf("please enter number of blank lines to input\n");
        scanf("%d%c", &n, &character);
        printf("input the contents of each line:\n");
        for (i = 0; i < n; i++) {
            fgets(str, sizeof str, stdin);
            fputs(str, fp);
        }
    fclose(fp);

    fp = fopen("zp4in.txt", "r");
    printf("The contents of file %s is:\n", "zp4in.txt");

    str1 = fgetc(fp);
    while (str1 != EOF){
        printf("%c", str1);
        str1 = fgetc(fp);
    }

    fclose(fp);

    system("wc -l < zp4in.txt > info.txt");
    system("wc -w < zp4in.txt >> info.txt");
    system("grep -o [a-z] < zp4in.txt | tr -d \"\n\" | wc -m >> info.txt");
    system("grep -o [A-Z] < "
           "zp4in.txt | tr -d \"\n\" | wc -m >> info.txt");
    system("grep -o \"[[:digit:]]\" < zp4in.txt | wc -l >> info.txt");
    system("grep -o ' ' < zp4in.txt | wc -l >> info.txt");
    system("grep -o \"[[:punct:]]\" < zp4in.txt | wc -l >> info.txt");

    //Get all data from created file.
    fp = fopen("info.txt", "r");
    int numList[NUM_COUNT];
    for (i = 0; i < NUM_COUNT; i++)
        fscanf(fp, "%d", &numList[i]);

    // Display data gathered from file
    printf("\nNumber of lines in the input file zp4in.txt: %d\n", numList[0]);
    printf("Number of words in the input file zp4in.txt: %d\n", numList[1]);
    printf("Number of small letters in the input file zp4in.txt: %d\n", numList[2]);
    printf("Number of capital letters in the input file zp4in.txt: %d\n", numList[3]);
    printf("Number of digits in the input file zp4in.txt: %d\n", numList[4]);
    printf("Number of spaces in the input file zp4in.txt: %d\n", numList[5]);
    printf("Number of special symbols in the input file zp4in.txt: %d\n", numList[6]);

    fclose(fp);

    fp = fopen("zp4in.txt", "r");
    op = fopen("zp4out1.txt", "w");
    op2 = fopen("zp4out2.txt", "w");


    //Convert small to capital letters and vise versa
    //then output to zp4out1.txt
    char ch;
    while ((ch = getc(fp)) != EOF) {
        if ('a' <= ch && ch <= 'z') {
            ch = toupper(ch);
            fprintf(op, "%c", ch);
        } else if ('A' <= ch && ch <= 'Z') {
            ch = tolower(ch);
            fprintf(op, "%c", ch);
        } else if (ch == ' ') {
            continue;
        } else {
            fprintf(op, "%c", ch);
        }
    }

    //pointer to top of program
    fseek(fp, 0, SEEK_SET);


    // Read file, then write to zp4out2.txt add numbers to each line.
    char line[255];
    i = 1;
    while (fgets(line, 255, fp) != NULL) {
        fprintf(op2, "%d. ", i);
        fputs(line, op2);
        i++;
    }

    //Display contents of zp4out1.txt with system command
    fseek(op, 0, SEEK_SET);
    fseek(op2, 0, SEEK_SET);
    system("echo; echo The contents of zp4out1.txt:;");
    system("cat zp4out1.txt;");
    system("echo; echo The contents of zp4out2.txt:; echo;");
    system("cat zp4out2.txt;");
    system("echo; echo Implemented by Dillon Kern;");
    system("echo 03 - 30 - 2020; echo;");

    // close all files
    fclose(fp);
    fclose(op);
    fclose(op2);

    if (atexit(done) != 0)
        printf("\nerror with atexit\n");

    return EXIT_SUCCESS;
}

// removes all created files from directory.
void done() {
    system("rm info.txt");
    system("rm zp4in.txt");
    system("rm zp4out1.txt");
    system("rm zp4out2.txt");
}