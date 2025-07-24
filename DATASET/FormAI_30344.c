//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>

int main() {
    // Create file pointer
    FILE *file_pointer;

    // Open file in write mode
    file_pointer = fopen("example.txt", "w");

    // Write text to file
    fprintf(file_pointer, "Hello world!\n");
    fprintf(file_pointer, "This is a file handling example program in C.\n");

    // Close file
    fclose(file_pointer);

    // Open file in read mode
    file_pointer = fopen("example.txt", "r");

    // Read text from file
    if (file_pointer) {
        printf("File contents:\n");

        char line[255];
        while (fgets(line, sizeof(line), file_pointer)) {
            printf("%s", line);
        }

        fclose(file_pointer);
    } else {
        printf("Error opening file\n");
    }

    return 0;
}