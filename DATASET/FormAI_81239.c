//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // Maximum line length of CSV file

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    const char *delimiter = ","; // Delimiter used in the CSV file

    // Open the CSV file
    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read and display each line of the CSV file
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *line_copy = strdup(line); // Duplicate the line for tokenizing
        token = strtok(line_copy, delimiter);

        // Tokenize the line by the delimiter and display each token
        while(token != NULL) {
            printf("%s\t", token);
            token = strtok(NULL, delimiter);
        }

        free(line_copy);
        printf("\n"); // Move to the next line
    }

    // Close the file and exit
    fclose(fp);
    return 0;
}