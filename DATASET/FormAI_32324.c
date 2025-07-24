//FormAI DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables needed for file handling
    FILE *fp;
    char filename[50];
    char character;
    int count = 0;

    // Get file name from user
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Error: File does not exist.\n");
        exit(1);
    }

    // Read file character by character
    while ((character = fgetc(fp)) != EOF)
    {
        putchar(character);
        count++;
    }

    // Close file
    fclose(fp);

    // Output number of characters read
    printf("Number of characters read: %d\n", count);

    return 0;
}