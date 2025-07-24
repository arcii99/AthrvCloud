//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file_ptr;
    char file_name[30], data[1000];

    // Prompt user for file name
    printf("Enter the file name to write: ");
    fgets(file_name, 30, stdin);

    // Open file for writing
    file_ptr = fopen(file_name, "w");

    // Check if file opened successfully
    if (file_ptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Prompt user for text data to write to file
    printf("Enter the text to write to the file: ");
    fgets(data, 1000, stdin);

    // Write data to file
    fputs(data, file_ptr);

    // Close file
    fclose(file_ptr);

    // Open file for reading
    file_ptr = fopen(file_name, "r");

    // Check if file opened successfully
    if (file_ptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Read data from file and print to console
    printf("\nReading data from the file: \n");
    while (fgets(data, 1000, file_ptr) != NULL) {
        printf("%s\n", data);
    }

    // Close file
    fclose(file_ptr);

    return 0;
}