//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>

int main() {
    // Create a file pointer and open the file in write mode
    FILE *filePointer;
    filePointer = fopen("example.txt", "w");

    char message[50];

    // Get user input and write it to the file
    printf("Enter a message to write to the file: ");
    gets(message);
    fputs(message, filePointer);

    // Close the file
    fclose(filePointer);

    // Open the file in read mode and print the contents
    filePointer = fopen("example.txt", "r");

    printf("Contents of the file: ");
    char character = fgetc(filePointer);
    while (character != EOF) {
        printf("%c", character);
        character = fgetc(filePointer);
    }

    // Close the file
    fclose(filePointer);

    return 0;
}