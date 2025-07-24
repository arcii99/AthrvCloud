//FormAI DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    // File pointer
    FILE *filePointer;

    // Open the file in write mode
    filePointer = fopen("example.txt", "w");

    // Write data to the file
    char data[MAX_SIZE];
    printf("Enter data to write to file: ");
    gets(data); // Warning: unsafe function, use fgets instead
    fprintf(filePointer, "%s", data);

    // Close the file
    fclose(filePointer);

    // Open the file in read mode
    filePointer = fopen("example.txt", "r");

    // Read data from the file
    char readData[MAX_SIZE];
    fscanf(filePointer, "%[^\n]", readData);
    printf("Data read from file: %s\n", readData);

    // Close the file
    fclose(filePointer);

    return 0;
}