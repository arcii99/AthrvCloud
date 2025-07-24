//FormAI DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Error handling function
void error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    // Ensure correct number of command line arguments
    if (argc != 2) {
        error("Expected one command line argument");
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        // Handle file opening error
        error(strerror(errno));
    }

    // Read the first line of the file
    char line[256];
    if (fgets(line, sizeof(line), fp) == NULL) {
        // Handle file reading error
        error(strerror(errno));
    }

    // Convert the line to an integer
    int num = atoi(line);
    if (num == 0) {
        // Handle invalid number error
        error("Invalid number in file");
    }

    printf("The number is: %d\n", num);

    // Close the file
    if (fclose(fp) != 0) {
        // Handle file closing error
        error(strerror(errno));
    }

    return 0;
}