//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr; //initialize file pointer
    char filename[20], ch;

    printf("Enter the filename to open for reading: \n");
    scanf("%s", filename);

    // Open file
    fptr = fopen(filename, "r");

    // Error handling
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Get file contents character by character
    ch = fgetc(fptr);
    printf("The contents of %s file are: \n", filename);

    while (ch != EOF)
    {
        putchar(ch);
        ch = fgetc(fptr);
    }

    // Close file
    fclose(fptr);

    return 0;
}