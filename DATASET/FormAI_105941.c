//FormAI DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
    // creating file pointer
    FILE *fp;

    // opening file
    fp = fopen("example.txt", "w");

    // handling file opening errors
    if (fp == NULL) {
        printf("Error opening file");
        exit(1);
    }

    // writing to file
    fprintf(fp, "This is an example file.\n");
    fprintf(fp, "It demonstrates file handling with C.\n");

    // closing file
    fclose(fp);

    // reopening file in read mode
    fp = fopen("example.txt", "r");

    // handling file opening errors
    if (fp == NULL) {
        printf("Error opening file");
        exit(1);
    }

    // reading from file and printing to console
    char c;
    printf("File contents:\n");
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    // closing file
    fclose(fp);

    return 0;
}