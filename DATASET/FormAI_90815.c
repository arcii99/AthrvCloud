//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *fp;
    char *filename = "example.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) { // checking if the file is opened successfully or not
        printf("Error occured while opening the file %s\n", filename);
        
        if (errno == ENOENT) { // checking specific error
            printf("File %s does not exist\n", filename);
        } else if (errno == EACCES) {
            printf("File %s cannot be opened due to permission issue\n", filename);
        }
        // other specific error handling can be done like this
        // ...
        // ...
        // OR
        printf("Error code: %d\nError message: %s", errno, strerror(errno));
        // generic error handling, to print error code and message of any error
        exit(EXIT_FAILURE); // exit the program with failure status code
    }
    else {
        printf("File %s opened successfully\n", filename);
        // do rest of the file processing here
        // ...
        fclose(fp); // close the file
        exit(EXIT_SUCCESS); // exit the program with success status code
    }
}