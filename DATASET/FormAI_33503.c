//FormAI DATASET v1.0 Category: Error handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


// define our own error handling function
void error_handling(char *msg) {
   perror(msg);
   exit(EXIT_FAILURE);
}

int main() {
    FILE *fp;

    // open a file with an invalid file name and check for errors
    fp = fopen("filewhichdoesnotexist.txt", "r");
    if (fp == NULL) {
        error_handling("Cannot open file");
    }

    // do some processing here

    // close the file and check for errors
    if (fclose(fp) == EOF) {
        error_handling("Cannot close file");
    }

    return EXIT_SUCCESS;
}