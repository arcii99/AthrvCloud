//FormAI DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the contents of a file
void displayFileContents(FILE *fptr)
{
    char c;

    printf("\nContents of the file are:\n");
    while ((c = fgetc(fptr)) != EOF)
    {
        putchar(c);
    }
}

int main()
{
    // Opening the file in write mode
    FILE *fptr = fopen("sample.txt", "w");

    // Checking if the file was successfully opened
    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    // Writing the contents to the file
    char *content = "Hello World!";
    int len = strlen(content);
    fwrite(content, sizeof(char), len, fptr);

    // Closing the file
    fclose(fptr);

    // Opening the file in read mode
    fptr = fopen("sample.txt", "r");

    // Checking if the file was successfully opened
    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    // Displaying the contents of the file
    displayFileContents(fptr);

    // Closing the file
    fclose(fptr);

    return 0;
}