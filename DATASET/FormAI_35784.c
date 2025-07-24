//FormAI DATASET v1.0 Category: Ebook reader ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("Welcome to the C Ebook Reader!\n");
    printf("We'll show you how to read an Ebook in style!\n");

    printf("Please enter the name of your Ebook file: ");
    char filename[50];
    fgets(filename, 50, stdin);

    printf("Welcome %s! Let's get started.\n", filename);

    printf("Reading Ebook...\n");

    FILE *fp;
    char ch;
    int count=0, wordCount=0, lineCount=0, charCount=0;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Oops! Unable to open the Ebook!");
        exit(0);
    }
    else{
        printf("Ebook opened successfully!\n");
        printf("Reading Ebook...\n");
        printf("----------------------------------\n");

        while((ch = fgetc(fp)) != EOF)
        {
            if(ch == '\n')
            {
                lineCount++;
            }

            if(ch == ' ' || ch == '\n' || ch == '\t')
            {
                wordCount++;
            }

            if(ch != ' ' && ch != '\n' && ch != '\t')
            {
                charCount++;
            }

            putchar(ch);
            count++;
        }

        printf("----------------------------------\n");
        printf("Ebook read successfully!\n");
        printf("Number of characters read: %d\n", charCount);
        printf("Number of words read: %d\n", wordCount);
        printf("Number of lines read: %d\n", lineCount);
    }

    fclose(fp);

    printf("Thanks for using C Ebook Reader!\n");
    printf("Hope you enjoyed reading in style!\n");

    return 0;
}