//FormAI DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define FILENAME "data.txt"

int main() {
    FILE *file = NULL;
    int num = 0, sum = 0;

    // Open the file in read mode
    file = fopen(FILENAME, "r");

    // Check for errors while opening the file
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Read numbers from the file and add them
    while (fscanf(file, "%d", &num) == 1) {
        sum += num;
    }

    // Check for errors while reading from the file
    if (ferror(file)) {
        printf("Error: Unable to read from file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Print the sum of the numbers
    printf("Sum of the numbers in the file: %d\n", sum);

    // Close the file
    if (fclose(file) == EOF) {
        printf("Error: Unable to close file\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}