//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to Happy File Handling Program!\n");

    FILE *filePointer;

    // Open file in write mode
    filePointer = fopen("happy.txt", "w");

    // Check if file is successfully opened
    if (filePointer == NULL)
    {
        printf("Oops! Something went wrong.\n");
        exit(1);
    }

    // Write to file
    fprintf(filePointer, "Hello world! I am a happy program.\n");

    // Close file
    fclose(filePointer);

    // Open file in read mode
    filePointer = fopen("happy.txt", "r");

    // Check if file is successfully opened
    if (filePointer == NULL)
    {
        printf("Oops! Something went wrong.\n");
        exit(1);
    }

    // Read from file
    char buffer[100];
    fgets(buffer, 100, filePointer);

    // Print file contents to console
    printf("%s", buffer);

    // Close file
    fclose(filePointer);

    printf("File handling completed successfully! Have a happy day!\n");

    return 0;
}