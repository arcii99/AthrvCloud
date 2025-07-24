//FormAI DATASET v1.0 Category: Error handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Function to open a file
void open_file(const char* filename) {
    FILE* fp;
    // Try to open file
    fp = fopen(filename, "r");
    // Check if there was an error
    if (fp == NULL) {
        // Print error message, and return
        printf("Error opening file %s\n", filename);
        perror("");
        exit(EXIT_FAILURE);
    }
    printf("Successfully opened file %s\n", filename);
    fclose(fp);
}

int main() {
    const char* filename = "nonexistent_file.txt";
    // Call function to open file
    open_file(filename);
    return 0;
}