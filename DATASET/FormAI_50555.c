//FormAI DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {

    // Open the file for reading
    FILE* fp = fopen("nonexistent_file.txt", "r");

    // Check if the file exists
    if (fp == NULL) {
        
        // Print the error message
        fprintf(stderr, "Error: Could not open file - %s\n", strerror(errno));
        
        // Return the error code
        return EXIT_FAILURE;
    }
    
    // Read the contents of the file
    char buffer[1024];
    int bytesRead = fread(buffer, sizeof(char), sizeof(buffer), fp);
    
    // Check if the read operation was successful
    if (bytesRead < 0) {
        
        // Print the error message
        fprintf(stderr, "Error: Could not read file - %s\n", strerror(errno));
        
        // Close the file
        fclose(fp);
        
        // Return the error code
        return EXIT_FAILURE;
    }
    
    // Print the contents of the file
    printf("%s", buffer);
    
    // Close the file
    fclose(fp);
    
    // Return success
    return EXIT_SUCCESS;
}