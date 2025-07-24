//FormAI DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char filename[50];
    char ch;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL) 
    {
        printf("Cannot open file \n");
        exit(0);
    }

    printf("The contents of the file are:\n");
    while ((ch = fgetc(fptr)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fptr);

    // Open file for writing
    fptr = fopen(filename, "a");

    if (fptr == NULL) 
    {
        printf("Cannot open file \n");
        exit(0);
    }

    printf("Enter text to write to file: ");
    scanf(" %[^\n]s", &ch);

    fprintf(fptr, "%s", ch);

    fclose(fptr);

    return 0;
}