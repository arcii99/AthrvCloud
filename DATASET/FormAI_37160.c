//FormAI DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fileptr;
    char filename[] = "example.txt";
    char ch;

    // create and write to a file
    fileptr = fopen(filename, "w");
    if (fileptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fprintf(fileptr, "This is an example program for file handling in C.\n");
    fprintf(fileptr, "We will be reading this file and printing its contents.\n");
    fprintf(fileptr, "We will also be appending some text to it.\n");
    fclose(fileptr); // close the file

    // read and print contents of the file
    fileptr = fopen(filename, "r");
    if (fileptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("Printing contents of %s:\n", filename);
    while ((ch = fgetc(fileptr)) != EOF) {
        printf("%c", ch);
    }
    fclose(fileptr); // close the file

    // append text to the file
    fileptr = fopen(filename, "a");
    if (fileptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fprintf(fileptr, "This is the appended text.\n");
    fclose(fileptr); // close the file

    // read and print contents of the file again
    fileptr = fopen(filename, "r");
    if (fileptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("\nPrinting updated contents of %s:\n", filename);
    while ((ch = fgetc(fileptr)) != EOF) {
        printf("%c", ch);
    }
    fclose(fileptr); // close the file

    return 0;
}