//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

typedef unsigned char byte;

/**
 * Computes the checksum using the C checksum algorithm.
 */
byte compute_checksum(const char* data, size_t len) {
    byte checksum = 0;
    for (size_t i = 0; i < len; ++i) {
        checksum += data[i];
    }
    return ~checksum + 1;
}

int main() {
    char input[MAX_LEN];
    printf("Enter some data to compute the C checksum: ");
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        --len;
    }
    byte checksum = compute_checksum(input, len);
    printf("The C checksum of \"%s\" is %02X\n", input, checksum);
    return 0;
}