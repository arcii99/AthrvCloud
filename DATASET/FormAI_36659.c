//FormAI DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[100], content[200];

    // Get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open file for writing in synchronous mode
    fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get content from user
    printf("Enter content to write: ");
    scanf("%s", content);

    // Write to file
    fprintf(fp, "%s", content);

    // Close file
    fclose(fp);

    // Open file for reading in synchronous mode
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read and print file content
    printf("\nContent from %s:\n\n", filename);

    while (fgets(content, 200, fp) != NULL)
    {
        printf("%s", content);
    }

    // Close file
    fclose(fp);

    return 0;
}