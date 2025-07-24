//FormAI DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp; // file pointer
    char filename[100]; // file name input buffer
    char ch; // character input buffer

    // prompt user for file name
    printf("Enter a filename to create or open: ");
    scanf("%s", filename);

    // open the file in "w+" mode for write/update access
    fp = fopen(filename, "w+");

    if (fp == NULL) // check if file was opened successfully
    {
        printf("Error opening file!");
        exit(1);
    }

    // write some text to the file
    fprintf(fp, "This file was created using C file handling operations.\n");

    // move the file pointer to the beginning of the file
    rewind(fp);

    // read and print the contents of the file
    printf("\nContents of file '%s':\n", filename);
    while ((ch = fgetc(fp)) != EOF) // fgetc reads file one character at a time
    {
        putchar(ch); // print character
    }

    // close the file
    fclose(fp);

    return 0;
}