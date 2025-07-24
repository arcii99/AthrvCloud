//FormAI DATASET v1.0 Category: Ebook reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {

    //Welcome message
    printf("Welcome to Vision Reader!\n\n");

    //Open ebook file
    FILE *fp;
    char filename[100];
    printf("Enter the name of the ebook file to open: ");
    gets(filename);
    fp = fopen(filename, "r");

    //Check if file exists
    if (fp == NULL) {
        printf("Error: File not found or unable to open.\n");
        exit(1);
    }

    //Read ebook content
    printf("\nReading ebook...\n\n");
    char ch;
    while((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    //Close ebook file
    fclose(fp);

    //Exit message
    printf("\n\nThank you for using Vision Reader!\n");

    return 0;
}