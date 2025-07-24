//FormAI DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() 
{
    char filename[MAX_SIZE];
    char input[MAX_SIZE];

    printf("Please enter the filename you would like to create:\n");
    fgets(filename, MAX_SIZE, stdin);

    // Remove newline character from filename
    int i;
    for (i = 0; i < MAX_SIZE; i++) 
    {
        if (filename[i] == '\n') 
        {
            filename[i] = '\0';
            break;
        }
    }

    // Create and write to file
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) 
    {
        printf("Error creating file. Exiting program.\n");
        return 1;
    }

    printf("Please enter the text you would like to write to the file:\n");
    fgets(input, MAX_SIZE, stdin);

    fputs(input, fp);
    fclose(fp);

    // Read from file
    char buffer[MAX_SIZE];
    fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("Error opening file. Exiting program.\n");
        return 1;
    }

    printf("Reading from file...\n");
    while (fgets(buffer, MAX_SIZE, fp) != NULL) 
    {
        printf("%s", buffer);
    }

    fclose(fp);
    return 0;
}