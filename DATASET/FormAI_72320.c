//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants
#define BLOCK_SIZE 512
#define BUFFER_SIZE BLOCK_SIZE * 10

// Function prototypes
bool calculate_checksum(char *file_name);

int main(int argc, char *argv[]) {
    char *file_name;

    // Check if the user provided an argument
    if (argc == 2) {
        file_name = argv[1];
    } else {
        printf("Please provide a file name as an argument.\n");
        return 1;
    }

    // Calculate the checksum for the file
    if (calculate_checksum(file_name)) {
        printf("Checksum calculation successful!\n");
    } else {
        printf("Error calculating checksum.\n");
    }

    return 0;
}

/**
 * Calculates the checksum for the given file.
 *
 * @param file_name - The name of the file to calculate the checksum for.
 *
 * @return True if the checksum was successfully calculated, false otherwise.
 */
bool calculate_checksum(char *file_name) {
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error opening %s\n", file_name);
        return false;
    }

    unsigned char buffer[BUFFER_SIZE];
    unsigned long checksum = 0;

    int read_bytes = 0;
    while ((read_bytes = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, file)) > 0) {
        for (int i = 0; i < read_bytes; i++) {
            checksum += buffer[i];
        }
    }

    fclose(file);

    printf("The checksum of %s is: %lu\n", file_name, checksum);

    return true;
}