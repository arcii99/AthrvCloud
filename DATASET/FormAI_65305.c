//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000000

int main() {
    // Allocate a large buffer
    char* buffer = (char*) malloc(sizeof(char) * BUFFER_SIZE);

    // Fill the buffer with random data
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = rand() % 256;
    }

    // Compute the checksum of the buffer
    long long checksum = 0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        checksum += buffer[i];
    }

    printf("Checksum: %lld\n", checksum);

    // Free the buffer
    free(buffer);

    return 0;
}