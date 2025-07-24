//FormAI DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Custom error handling function
void handle_error(char* error_msg, int error_code) {
    printf("%s. Error code: %d\n", error_msg, error_code);
    exit(EXIT_FAILURE);
}

int main() {
    FILE *fp;
    char* filename = "nonexistent_file.txt";
    int num;
    
    // Try to open the file
    fp = fopen(filename, "r");
    
    // Check if file opening was successful or not
    if (fp == NULL) {
        if (errno == ENOENT) {  // Check if file does not exist
            handle_error("File does not exist", errno);
        } else if (errno == EACCES) {  // Check if permission is denied
            handle_error("Permission denied", errno);
        } else {  // Catch-all for any other errors
            handle_error("Unknown error occurred while opening file", errno);
        }
    }
    
    // If file opening was successful, try to read an integer from the file
    if (fscanf(fp, "%d", &num) != 1) {  // If fscanf returns anything other than 1, it means it failed to read an integer
        handle_error("Failed to read integer from file", errno);
    }
    
    // Close the file
    if (fclose(fp) != 0) {  // If fclose returns anything other than 0, it means it failed to close the file
        handle_error("Failed to close file", errno);
    }
    
    // Print the read integer
    printf("The integer read from the file is: %d\n", num);
    
    return 0;
}