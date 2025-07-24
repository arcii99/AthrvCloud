//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[100];

    // Open the file
    fp = fopen("example.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Read in each line of the file
    while (fgets(line, sizeof(line), fp)) {
        // If the line contains the string "error"
        if (strstr(line, "error")) {
            // Throw an error
            fprintf(stderr, "ERROR: Found '%s' in file.\n", line);
            exit(EXIT_FAILURE);
        }
    }

    // Close the file and exit
    fclose(fp);
    exit(EXIT_SUCCESS);
}