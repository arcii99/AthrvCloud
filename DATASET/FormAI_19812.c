//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include<stdio.h>

int main()
{
    printf("Hello coders, are you ready for some awesome C File Handling example program?");
    printf("\n\nYou better buckle up, because here we go!\n\n");
    
    FILE *fp;
    char c;

    fp = fopen("example.txt", "r");

    if (fp == NULL)
    {
        printf("Oops, the file could not be opened!");
        return 1;
    }

    printf("The contents of the file are:\n\n");

    while ((c = getc(fp)) != EOF)
        putchar(c);

    fclose(fp);
    printf("\n\nThe file has been successfully read!");

    fp = fopen("example.txt", "a");

    if (fp == NULL)
    {
        printf("Oops, the file could not be opened!");
        return 1;
    }

    printf("\n\nAdding some text to the file...\n\n");

    fprintf(fp, "\nHey coders, C File Handling is awesome!");

    fclose(fp);
    printf("The text has been successfully added to the file!");

    printf("\n\nHope you enjoyed the program, happy coding!");

    return 0;
}