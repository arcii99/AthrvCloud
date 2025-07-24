//FormAI DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    FILE* fp;
    char filename[MAX_SIZE];
    char line[MAX_SIZE];
    int n_lines = 0;

    // Get filename from user input
    printf("Enter the input filename: ");
    fgets(filename, MAX_SIZE, stdin);

    // Remove newline character from filename
    char* pos = NULL;
    if ((pos = strchr(filename, '\n')) != NULL) {
        *pos = '\0';
    }

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Count the number of lines in the file
    while (fgets(line, MAX_SIZE, fp) != NULL) {
        n_lines++;
    }

    // Allocate memory for an array of strings
    char** lines = (char**) malloc(n_lines * sizeof(char*));
    if (lines == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    // Reset file pointer to beginning of file
    rewind(fp);

    // Read each line into the array of strings
    for (int i = 0; i < n_lines; i++) {
        fgets(line, MAX_SIZE, fp);

        // Remove newline character from line
        if ((pos = strchr(line, '\n')) != NULL) {
            *pos = '\0';
        }

        // Allocate memory for the string and copy the line into it
        lines[i] = (char*) malloc((strlen(line) + 1) * sizeof(char));
        if (lines[i] == NULL) {
            printf("Memory allocation error.\n");
            exit(1);
        }
        strcpy(lines[i], line);
    }

    // Close the file
    fclose(fp);

    // Get output filename from user input
    printf("Enter the output filename: ");
    fgets(filename, MAX_SIZE, stdin);

    // Remove newline character from filename
    if ((pos = strchr(filename, '\n')) != NULL) {
        *pos = '\0';
    }

    // Open file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write the lines to the output file in reverse order
    for (int i = n_lines - 1; i >= 0; i--) {
        fprintf(fp, "%s\n", lines[i]);

        // Free the memory allocated for the string
        free(lines[i]);
    }

    // Free the memory allocated for the array of strings
    free(lines);

    // Close the file
    fclose(fp);

    return 0;
}