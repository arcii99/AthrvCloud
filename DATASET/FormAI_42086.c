//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This C program extracts metadata from a given file.
 * It reads the file and searches for specific patterns
 * to extract information such as author, date, and version.
 * The extracted information is then printed to the console.
 */

int main(int argc, char *argv[])
{
    // Check if a filename was provided
    if (argc < 2)
    {
        printf("Please specify a filename.\n");
        return 1;
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");

    // Check if file was opened successfully
    if (fp == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create variables to store metadata
    char author[30] = "";
    char date[20] = "";
    int version = 0;

    // Read file line by line
    char line[100];
    while (fgets(line, 100, fp) != NULL)
    {
        // Check for author metadata
        if (strstr(line, "//author:") != NULL)
        {
            strcpy(author, line+9);
            author[strcspn(author, "\n")] = 0;
        }

        // Check for date metadata
        if (strstr(line, "//date:") != NULL)
        {
            strcpy(date, line+7);
            date[strcspn(date, "\n")] = 0;
        }

        // Check for version metadata
        if (strstr(line, "//version:") != NULL)
        {
            version = atoi(line+10);
        }
    }

    // Print metadata
    if (strcmp(author, "") != 0)
    {
        printf("Author: %s\n", author);
    }
    if (strcmp(date, "") != 0)
    {
        printf("Date: %s\n", date);
    }
    if (version > 0)
    {
        printf("Version: %d\n", version);
    }

    // Close the file
    fclose(fp);

    return 0;
}