//FormAI DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char file_name[MAX_LEN];
    FILE *fp;

    printf("Enter the name of the file to read: ");
    fgets(file_name, MAX_LEN, stdin);

    // Removing the newline character from the end of the file name
    file_name[strcspn(file_name, "\n")] = 0;

    // Opening the file in read mode
    fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("File content:\n");

    // Reading the file content character by character
    int c;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);

    // Opening the file in append mode
    fp = fopen(file_name, "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\nEnter text to append to the file: ");
    char input[MAX_LEN];
    fgets(input, MAX_LEN, stdin);

    // Removing the newline character from the end of the input
    input[strcspn(input, "\n")] = 0;

    // Writing the input to the file
    fputs(input, fp);

    fclose(fp);

    return 0;
}