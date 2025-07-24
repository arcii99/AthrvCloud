//FormAI DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the immersive file handling program!\n\n");

    // Create a file pointer
    FILE *filePointer;

    // Open a file in write mode
    filePointer = fopen("sample.txt", "w");

    // Check if the file was opened successfully
    if (filePointer == NULL)
    {
        printf("Error opening file. Exiting program...\n");
        exit(1);
    }

    printf("File opened successfully.\n\n");

    printf("Please enter some text to write to the file:\n");
    
    char userInput[50];

    // read the user input
    fgets(userInput, 50, stdin);

    // write the user input to the file
    fputs(userInput, filePointer);

    printf("\nText written to file: %s\n", userInput);

    // close the file pointer
    fclose(filePointer);

    printf("\nFile closed successfully.\n\n");

    // open the file in read mode
    filePointer = fopen("sample.txt", "r");

    // Check if the file was opened successfully
    if (filePointer == NULL)
    {
        printf("Error opening file. Exiting program...\n");
        exit(1);
    }

    printf("File opened successfully.\n\n");

    printf("Reading contents of the file:\n");

    // read each line of the file and print it to the console
    char line[255];
    while (fgets(line, 255, filePointer))
    {
        printf("%s", line);
    }

    // close the file pointer
    fclose(filePointer);

    printf("\nFile closed successfully.\n\n");

    printf("Thank you for using the immersive file handling program!\n");

    return 0;
}