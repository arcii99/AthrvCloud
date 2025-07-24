//FormAI DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <ctype.h>

// This is a program that reads a file and splits it into two files, one containing only the uppercase characters
// and the second containing only the lowercase characters.

int main() {
    FILE *inputFile, *upperCaseFile, *lowerCaseFile;
    char current, upper, lower;
    inputFile = fopen("example.txt", "r");
    upperCaseFile = fopen("uppercase.txt", "w");
    lowerCaseFile = fopen("lowercase.txt", "w");

    // Check if any of the files failed to open
    if (inputFile == NULL || upperCaseFile == NULL || lowerCaseFile == NULL) {
        printf("Failed to open one or more files.\n");
        return 1;
    }

    while ((current = fgetc(inputFile)) != EOF) {
        if (isupper(current)) {
            fputc(current, upperCaseFile);
        } else if (islower(current)) {
            fputc(current, lowerCaseFile);
        }
    }

    // Let's close all the files
    fclose(inputFile);
    fclose(upperCaseFile);
    fclose(lowerCaseFile);

    printf("File processing complete.\n");

    return 0;
}