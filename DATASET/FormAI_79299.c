//FormAI DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>

int main()
{
    printf("Welcome to my exciting file handling program!\n");

    // Creating a file and opening it in write mode
    FILE *fp = fopen("my_file.txt", "w");

    // Checking if the file opened successfully
    if (fp == NULL)
    {
        printf("Oops! Something went wrong while opening the file.\n");
        return 1;
    }

    printf("File created and opened successfully!\n");

    // Writing to the file
    fprintf(fp, "Hello, world!");

    // Closing the file
    fclose(fp);

    // Opening the file in read mode
    fp = fopen("my_file.txt", "r");

    // Checking if the file opened successfully
    if (fp == NULL)
    {
        printf("Oops! Something went wrong while opening the file.\n");
        return 1;
    }

    printf("\nFile opened successfully in read mode!\n");

    // Reading from the file and printing the contents
    char c;
    printf("Content of file: ");
    while((c=fgetc(fp))!=EOF) 
    {
        putchar(c);
    }

    // Closing the file
    fclose(fp);

    printf("\n\nHope you enjoyed my file handling program!");

    return 0;
}