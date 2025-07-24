//FormAI DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main()
{
    char* fileName = "example.txt";
    FILE* filePtr;

    // Open file for writing
    filePtr = fopen(fileName, "w");

    // Check if file exists and can be opened
    if (filePtr == NULL)
    {
        printf("Failed to open file \"%s\" for writing.\n", fileName);
        exit(1);
    }

    // Write some data to the file
    fprintf(filePtr, "Hello, world!\n");

    // Close the file
    fclose(filePtr);

    // Open file for reading
    filePtr = fopen(fileName, "r");

    // Check if file exists and can be opened
    if (filePtr == NULL)
    {
        printf("Failed to open file \"%s\" for reading.\n", fileName);
        exit(1);
    }

    // Read data from the file and print it to stdout
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), filePtr) != NULL)
    {
        printf("Line: %s", line);
    }

    // Close the file
    fclose(filePtr);

    // Delete the file
    int status = remove(fileName);
    if (status == 0)
    {
        printf("File \"%s\" deleted successfully!\n", fileName);
    }
    else
    {
        printf("Failed to delete file \"%s\".\n", fileName);
    }

    return 0;
}