//FormAI DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char fname[20], ch;
    int count = 0;

    printf("Enter file name (with extension): ");
    scanf("%s", fname);

    fp = fopen(fname, "r");

    if(fp == NULL)
    {
        printf("Error opening the file\n");
        exit(0);
    }

    printf("File contents: \n");

    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
        count++;
    }

    printf("\n\nThe file contains %d characters.\n", count);

    fclose(fp);

    return 0;
}