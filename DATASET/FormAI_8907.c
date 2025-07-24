//FormAI DATASET v1.0 Category: File handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_pointer;

    // Create a new file for writing
    file_pointer = fopen("example.txt", "w");

    if(file_pointer == NULL) {
        printf("Error creating file.");
        exit(1);
    }

    // Write some data to the file
    fprintf(file_pointer, "This is an example program.\n");
    fprintf(file_pointer, "It uses file handling in C.\n");

    // Close the file
    fclose(file_pointer);

    // Open the file again for reading
    file_pointer = fopen("example.txt", "r");

    if(file_pointer == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // Read the data from the file
    char buffer[256];
    fgets(buffer, 256, file_pointer);

    // Print the data to the console in bold
    printf("\033[1m%s\033[0m", buffer);

    fgets(buffer, 256, file_pointer);

    // Print the data to the console in bold
    printf("\033[1m%s\033[0m", buffer);

    // Close the file
    fclose(file_pointer);

    return 0;
}