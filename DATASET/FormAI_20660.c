//FormAI DATASET v1.0 Category: Log analysis ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000 // Maximum line size

int main(int argc, char *argv[]) {
    char *filename = argv[1]; // Get filename from command line argument
    FILE *fp = fopen(filename, "r"); // Open file

    if (fp == NULL) { // Check if file exists
        printf("Error: File not found\n");
        return 1;
    }

    int line_number = 1; // Line number counter
    char line[MAXLINE]; // Line buffer
    while (fgets(line, MAXLINE, fp) != NULL) { // Read file line by line
        // Check if line contains "ERROR"
        if (strstr(line, "ERROR") != NULL) {
            printf("%s:%d %s", filename, line_number, line); // Print filename, line number, and line containing "ERROR"
        }
        line_number++; // Increment line number counter
    }

    fclose(fp); // Close file
    return 0;
}