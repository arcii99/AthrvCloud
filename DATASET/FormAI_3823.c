//FormAI DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum length of a line in the input file
#define BUFFER_SIZE 100

int main() {
    FILE *inFile, *outFile;
    char buffer[BUFFER_SIZE];

    // Open the input and output files
    if ((inFile = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "Error: Unable to open input.txt\n");
        exit(1);
    }

    if ((outFile = fopen("output.txt", "w")) == NULL) {
        fprintf(stderr, "Error: Unable to open output.txt\n");
        exit(1);
    }

    // Read each line from the input file
    while (fgets(buffer, BUFFER_SIZE, inFile) != NULL) {
        // Remove the newline character at the end of the line
        buffer[strcspn(buffer, "\n")] = '\0';

        // Write the line to the output file in reverse order
        for (int i = strlen(buffer) - 1; i >= 0; i--) {
            fputc(buffer[i], outFile);
        }

        // Add a newline character to the output file
        fputc('\n', outFile);
    }

    // Close the input and output files
    fclose(inFile);
    fclose(outFile);

    return 0;
}