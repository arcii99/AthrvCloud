//FormAI DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the file name
#define FILE_NAME "data.txt"

// Define the max length of the string
#define MAX_STRING_LEN 100

int main() {
    // Open the file for writing
    FILE *file = fopen(FILE_NAME, "w");

    // Check if file was successfully opened
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write some strings to the file
    fputs("Hello, world!\n", file);
    fputs("This is a sample file handling program.\n", file);

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen(FILE_NAME, "r");

    // Check if file was successfully opened
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read strings from the file
    char str[MAX_STRING_LEN];
    while (fgets(str, MAX_STRING_LEN, file)) {
        printf("%s", str);
    }

    // Close the file
    fclose(file);

    return 0;
}