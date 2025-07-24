//FormAI DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE *fp;
    char *filename = "example.txt";
    char line[100];

    fp = fopen(filename, "r"); // open file for reading

    if (fp == NULL) // check if file was opened successfully
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno)); // print error message
        exit(EXIT_FAILURE); // terminate program with failure status
    }

    while (fgets(line, sizeof(line), fp)) // read file line by line
    {
        // do something with the line
        printf("%s", line);
    }

    if (ferror(fp)) // check for errors while reading file
    {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno)); // print error message
        exit(EXIT_FAILURE); // terminate program with failure status
    }

    if (fclose(fp) != 0) // close file
    {
        fprintf(stderr, "Error closing file: %s\n", strerror(errno)); // print error message
        exit(EXIT_FAILURE); // terminate program with failure status
    }

    return 0; // terminate program with success status
}