//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>

int main() {
    FILE *fptr;

    // Open file for writing
    fptr = fopen("example.txt", "w");

    // Check if file opened successfully
    if (fptr == NULL) {
        printf("Error opening file!");
        return -1;
    }

    // Write data to file
    fprintf(fptr, "This is an example C file handling program.\n");
    fprintf(fptr, "We can use this program to read and write data to files.\n");

    // Close file
    fclose(fptr);

    // Open file for reading
    fptr = fopen("example.txt", "r");

    // Check if file opened successfully
    if (fptr == NULL) {
        printf("Error opening file!");
        return -1;
    }

    // Read data from file and print to console
    char buffer[100];
    while (fgets(buffer, 100, fptr)) {
        printf("%s", buffer);
    }

    // Close file
    fclose(fptr);

    return 0;
}