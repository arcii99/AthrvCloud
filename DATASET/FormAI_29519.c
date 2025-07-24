//FormAI DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>

int main() 
{
    printf("Welcome to my exciting example C program for file handling!\n");
    printf("I'm going to show you how to open and write to a file using C.\n");

    // Create a file pointer and a file name
    FILE *fp;
    char filename[] = "example.txt";

    // Try to open the file for writing
    fp = fopen(filename, "w");

    // If the file didn't open, print an error message and exit
    if (fp == NULL) 
    {
        printf("Something went wrong! Unable to open file\n");
        return -1;
    }
    else
    {
        printf("The file %s was opened successfully\n", filename);
    }

    // Write to the file
    fprintf(fp, "Hello, world! This is an example C program for file handling.\n");
    fprintf(fp, "We're writing text to a file using fprintf()\n");

    // Close the file
    fclose(fp);

    printf("File %s was closed successfully.\n", filename);

    return 0;
}