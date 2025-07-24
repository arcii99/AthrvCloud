//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>

int main() {

    FILE *filePointer;

    // Creating a new file named "example.txt"
    filePointer = fopen("example.txt", "w");

    if (filePointer == NULL) {
        printf("Error: Unable to create file.\n");
        return 1;
    }

    // Writing to the file
    fprintf(filePointer, "Hello World! I am a file.\n");
    fprintf(filePointer, "Nice to meet you.\n");

    // Closing the file
    fclose(filePointer);

    // Reopening the file for reading
    filePointer = fopen("example.txt", "r");

    if (filePointer == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Reading and printing the contents of the file
    char character = getc(filePointer);
    while (character != EOF) {
        printf("%c", character);
        character = getc(filePointer);
    }

    // Closing the file
    fclose(filePointer);

    // Deleting the file
    int status;
    status = remove("example.txt");

    if (status == 0) {
        printf("\nThe file was deleted successfully.\n");
    } else {
        printf("\nError: Unable to delete the file.\n");
        return 1;
    }

    return 0;
}