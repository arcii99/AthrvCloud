//FormAI DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>

void main() {
    FILE* fp; // Declare the file pointer
    char filename[100]; // Declare the filename array
    char buffer[100]; // Declare a buffer array for text input

    // Ask the user for the filename
    printf("Enter the name of the file you wish to create: ");
    scanf("%s", filename);

    // Attempt to open the file in write mode
    fp = fopen(filename, "w");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file: %s", filename); // Output an error message
        return; // Terminate the program
    }

    // Ask the user for some text to write to the file
    printf("Enter some text to write to the file: ");
    scanf("%s", buffer);

    // Write the text to the file
    fputs(buffer, fp);

    // Close the file
    fclose(fp);

    // Re-open the file in read mode
    fp = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file: %s", filename); // Output an error message
        return; // Terminate the program
    }

    // Declare a buffer array for reading from the file
    char readbuf[100];

    // Read the entire contents of the file into the buffer
    while (fgets(readbuf, sizeof(readbuf), fp) != NULL) {
        // Output the text read from the file to the console
        printf("%s", readbuf);
    }

    // Close the file
    fclose(fp);
}