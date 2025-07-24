//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>

#define MAX_BUFFER_SIZE 1024

unsigned int calculate_checksum(const char *data, int length) {
    unsigned int checksum = 0;
    int i;
    for (i = 0; i < length; ++i) {
        checksum += (unsigned int)(data[i]);
    }
    return checksum;
}

int main() {
    char buffer[MAX_BUFFER_SIZE];

    // Read input data
    printf("Enter input data to calculate the checksum:\n");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Calculate the checksum
    unsigned int checksum = calculate_checksum(buffer, strlen(buffer));

    // Display the result
    printf("Checksum of input data '%s' is %u", buffer, checksum);

    return 0;
}