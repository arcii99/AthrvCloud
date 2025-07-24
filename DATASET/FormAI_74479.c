//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>

int main() {
    // create a file pointer to hold the file we're working with
    FILE *filePointer;

    // create a file named "example.txt" in write mode
    filePointer = fopen("example.txt", "w");

    // check if the file was created and opened successfully
    if (filePointer == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // write to the file
    fprintf(filePointer, "Hello, world!\n");

    // close the file to save changes
    fclose(filePointer);

    // open the file again, this time in read mode
    filePointer = fopen("example.txt", "r");

    // check if the file was opened successfully
    if (filePointer == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // read from the file and print its contents to the screen
    char buffer[100];
    while (fgets(buffer, 100, filePointer) != NULL) {
        printf("%s", buffer);
    }

    // close the file
    fclose(filePointer);

    return 0;
}