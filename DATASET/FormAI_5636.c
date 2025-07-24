//FormAI DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>

// function to copy contents from one file to another
void copyFile(FILE *source, FILE *destination) {
    char character;

    while ((character = fgetc(source)) != EOF) {
        fputc(character, destination);
    }

    printf("File copied successfully!\n");
}

int main() {
    // opening source file
    FILE *sourceFile = fopen("input.txt", "r");

    // check if file exists
    if (sourceFile == NULL) {
        printf("Source file not found.\n");
        return 0;
    }

    // opening destination file
    FILE *destinationFile = fopen("output.txt", "w");

    // check if file exists
    if (destinationFile == NULL) {
        printf("Unable to create output file.\n");
        return 0;
    }

    // call function to copy files
    copyFile(sourceFile, destinationFile);

    // close files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}