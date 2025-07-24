//FormAI DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    FILE *fp;
    char filename[MAX_SIZE], content[MAX_SIZE], newContent[MAX_SIZE];

    // Get the file name from the user
    printf("Enter the file name: ");
    fgets(filename, MAX_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;

    // Creating the File
    fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Error in creating a file..");
        exit(1);
    }

    printf("File created successfully.\n");

    // Writing Content to the File
    printf("Enter the content: ");
    fgets(content, MAX_SIZE, stdin);

    fprintf(fp, "%s", content);

    fclose(fp);

    printf("Content written to the file successfully.\n");

    // Reading Content of the File
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error in opening the file..");
        exit(1);
    }

    printf("The content of the file is:\n");

    while (fgets(newContent, MAX_SIZE, fp) != NULL)
    {
        printf("%s", newContent);
    }

    fclose(fp);

    return 0;
}