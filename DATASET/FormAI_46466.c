//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define CHECKSUM_LENGTH 4

/**
 * Calculates the checksum of a given input string
 * @param data The input string
 * @return The calculated checksum
 */
char *calculateChecksum(char *data) {
    int len = strlen(data);
    int sum = 0;
    int i = 0;
    for (i = 0; i < len; i++) {
        sum += data[i];
    }
    char *checksum = (char *) malloc(CHECKSUM_LENGTH + 1);
    snprintf(checksum, CHECKSUM_LENGTH + 1, "%04d", sum);
    return checksum;
}

/**
 * Entry point of the program
 * @param argc The number of command-line arguments
 * @param argv An array of command-line arguments
 * @return 0 if program ran successfully, non-zero otherwise
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s data\n", argv[0]);
        return 1;
    }

    char *data = argv[1];
    char *checksum = calculateChecksum(data);
    printf("Checksum of '%s' is: %s\n", data, checksum);

    free(checksum);
    return 0;
}