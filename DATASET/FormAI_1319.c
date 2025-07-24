//FormAI DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void){

    // Set up a file pointer
    FILE *fp;

    // Open a file that does not exist
    fp = fopen("nonexistent_file.txt", "r");

    // If file pointer is NULL, print error message with error code
    if (fp == NULL){
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Try to write to a read-only file
    char *file_content = "This is a test.\n";
    if (fwrite(file_content, strlen(file_content), 1, fp) != 1){

        // Print error message with error code and close file
        fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(fp);

    // Try to delete the file
    if (remove("nonexistent_file.txt") != 0){

        // Print error message with error code
        fprintf(stderr, "Error deleting file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // If we made it here, everything went smoothly
    printf("Program executed successfully.\n");
    exit(EXIT_SUCCESS);
}