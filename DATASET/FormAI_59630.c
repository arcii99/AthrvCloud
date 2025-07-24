//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    FILE *fptr;
    char filename[MAX_LEN];
    char line[MAX_LEN];
    char *token;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LEN, fptr))
    {
        token = strtok(line, ",\n");

        while (token != NULL)
        {
            printf("%s ", token);
            token = strtok(NULL, ",\n");
        }

        printf("\n");
    }

    fclose(fptr);

    return 0;
}