//FormAI DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Define a custom error function */
void perror_exit(const char *error) {
    perror(error);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    FILE *file;

    /* Check for the correct number of command line arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Attempt to open the file */
    if ((file = fopen(argv[1], "r")) == NULL) {
        /* Check if the error was caused by an invalid argument */
        if (errno == EINVAL) {
            perror_exit("Invalid argument passed to fopen()");
        }
        /* Check if the error was caused by a nonexistent file */
        else if (errno == ENOENT) {
            fprintf(stderr, "Error: file '%s' does not exist\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        /* For all other errors, print the error message to stderr */
        else {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    /* Continue with the rest of the program */

    return 0;
}