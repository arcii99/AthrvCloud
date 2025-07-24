//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main() {
    char message[] = "Hello, world!";
    size_t length = strlen(message);
    unsigned int sum = 0;

    // Calculate the sum of all message bytes
    for (size_t i = 0; i < length; i++) {
        sum += message[i];
    }

    // Apply the two's complement to obtain the checksum
    unsigned int checksum = ~(sum - 1);

    printf("Message: %s\n", message);
    printf("Checksum: %u\n", checksum);

    return 0;
}