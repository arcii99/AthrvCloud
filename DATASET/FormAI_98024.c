//FormAI DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char filename[20];
    char line[100];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("Error: Unable to open file '%s'\n", filename);
        exit(1);
    }

    printf("Content of file '%s':\n\n", filename);

    while (fgets(line, sizeof(line), fptr))
    {
        printf("%s", line);
    }

    fclose(fptr);

    return 0;
}