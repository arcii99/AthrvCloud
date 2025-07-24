//FormAI DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    // Open file for writing
    fp = fopen("testfile.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Writing to file
    fprintf(fp, "The quick brown fox jumps over the lazy dog.");

    // Closing file
    fclose(fp);

    // Reopening file for reading
    fp = fopen("testfile.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Reading from file
    char str[50];
    fscanf(fp, "%[^\n]", str);
    printf("The content of the file is: %s\n", str);

    // Closing file
    fclose(fp);

    return 0;
}