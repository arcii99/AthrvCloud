//FormAI DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {

    FILE *fp;

    fp = fopen("some_file.txt", "r"); // Try to open a file that doesn't exist
    if (fp == NULL) { // Error handling begins

        fprintf(stderr, "Error: %s\n", strerror(errno)); // Print the error message corresponding to the value of errno
        perror("Error"); // Print the string "Error" followed by the error message corresponding to the value of errno

        switch(errno) { // A switch statement to handle different types of errors

            case EACCES: // Permission denied error
                printf("You do not have permission to access this file.\n");
                exit(EXIT_FAILURE); // Terminate the program
                break;

            case ENOENT: // No such file or directory error
                printf("The file you are trying to access does not exist.\n");
                exit(EXIT_FAILURE);
                break;

            case EIO: // Input/Output error
                printf("There was an error while reading the file.\n");
                exit(EXIT_FAILURE);
                break;

            default: // For all other errors
                printf("There was an error: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
                break;

        }

    } // Error handling ends

    // If the file opened successfully, do something with it

    fclose(fp); // Close the file

    return 0; // Terminate the program

}