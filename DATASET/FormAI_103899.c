//FormAI DATASET v1.0 Category: File handling ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char ch;

    fp = fopen("example.txt", "r");  // opens example.txt in read mode

    if (fp == NULL) {  // check if file exists and can be accessed
        printf("Error opening file.\n");
        exit(1);  // terminate program
    }

    while ((ch = fgetc(fp)) != EOF) {  // read character by character until end of file
        putchar(ch);  // output character to console
    }

    fclose(fp);  // close file

    return 0;
}