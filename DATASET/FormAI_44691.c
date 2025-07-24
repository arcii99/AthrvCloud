//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read csv file recursively
void read_csv(FILE *file) {
    char line[256];
    char *token;

    // Get each line until the end of file
    while (fgets(line, sizeof(line), file)) {
        // Parse each token separated by comma
        token = strtok(line, ",");
        while (token != NULL) {
            // Print token value
            printf("%s", token);
            // Move to next token
            token = strtok(NULL, ",");
            // If this is not the end of the line, print comma
            if (token != NULL) {
                printf(", ");
            }
        }
        printf("\n");

        // Recursively call function to read next line
        read_csv(file);
    }
}

int main() {
    // Open csv file for reading
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    // Read csv file recursively
    read_csv(file);

    // Close file
    fclose(file);

    return 0;
}