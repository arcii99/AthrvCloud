//FormAI DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePtr;
    char fileName[] = "example.txt", ch;

    filePtr = fopen(fileName, "w"); // Create a new file or overwrite an existing one

    if (filePtr == NULL) {
        printf("Error opening file: %s\n", fileName);
        exit(1);
    } else {
        printf("%s file opened successfully!\n", fileName);
    }
  
    fputs("Hello, world!\n", filePtr);
    fputs("This is a test file.\n", filePtr);

    fclose(filePtr);
    printf("File saved and closed.\n");

    filePtr = fopen(fileName, "r"); // Open the file for reading

    if (filePtr == NULL) {
        printf("Error opening file: %s\n", fileName);
        exit(1);
    } else {
        printf("\n%s file opened successfully for reading!\n", fileName);
    }

    printf("\nContents of the file:\n");

    while ((ch = fgetc(filePtr)) != EOF) {
        putchar(ch);
    }

    fclose(filePtr);
    printf("File closed.\n");

    return 0;
}