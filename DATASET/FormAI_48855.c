//FormAI DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to Ebook Reader!\n");
    
    // Declare variables
    FILE *fp;
    char fileName[50], ch;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", fileName);

    // Attempt to open file
    fp = fopen(fileName, "r");

    // If file doesn't exist, output error message and exit
    if(fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    printf("\n\nReading contents of ebook:\n\n");

    // Read and output contents of file
    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    // Close file
    fclose(fp);
    printf("\n\nFinished reading ebook!\n");
    
    return 0;
}