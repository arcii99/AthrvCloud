//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
/*************************************************************************
*This program is a colorful file handling example program
*It creates and writes to a file named "happy_file.txt"
*The program is filled with positive messages
*Created by the cheerful chatbot, Let's Be Happy
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the happy file handling program!\n\n");
    printf("Let's spread some joy and create a new file...\n");

    // Creating a new file
    FILE *happy_file = fopen("happy_file.txt", "w");

    // Checking if file was created successfully
    if (happy_file == NULL)
    {
        printf("Oopsie, there was an error creating the file...");
        return 1;
    }

    // Writing positive messages to the file
    fprintf(happy_file, "Hello, world!\n");
    fprintf(happy_file, "Today is a great day!\n");
    fprintf(happy_file, "You are awesome!\n");
    fprintf(happy_file, "Don't forget to smile!\n");
    fprintf(happy_file, "Always believe in yourself!\n");
    fprintf(happy_file, "You are a shining star!\n");
    fprintf(happy_file, "Life is beautiful, cherish every moment!\n");

    printf("Hooray, the file has been successfully created and written to!\n");

    // Closing the file
    fclose(happy_file);

    // Reading from the file
    printf("\nNow, let's read from the file and spread some more happiness...\n\n");

    FILE *happy_file_read = fopen("happy_file.txt", "r");

    // Checking if file was opened successfully
    if (happy_file_read == NULL)
    {
        printf("Oopsie, there was an error opening the file...");
        return 1;
    }

    // Reading and printing each line of the file
    char line[100];
    while (fgets(line, sizeof(line), happy_file_read) != NULL)
    {
        printf("%s", line);
    }

    // Closing the file
    fclose(happy_file_read);

    printf("\nHappiness has been successfully spread! Hope this program made you smile today :)\n");

    return 0;
}