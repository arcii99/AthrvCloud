//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char str[100];
    char filename[50];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // create a new file or append to an existing file
    fp = fopen(filename, "a+");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter a sentence to write to the file: ");
    fgets(str, 100, stdin);
    fputs(str, fp);

    fclose(fp);

    // open the file again, but this time for reading
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("The contents of %s are:\n", filename);

    while (fgets(str, 100, fp) != NULL)
    {
        printf("%s", str);
    }

    fclose(fp);

    return 0;
}