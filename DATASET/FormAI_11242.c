//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_checksum(const char* data, int length) {
    int checksum = 0;
    for (int i = 0; i < length; i++) {
        checksum += (int)data[i];
    }
    return checksum;
}

int main() {
    char data[256];
    int checksum = 0;

    printf("Enter data to calculate checksum:\n");
    fgets(data, 256, stdin);

    // Remove trailing newline character
    data[strcspn(data, "\n")] = 0;
    
    checksum = calculate_checksum(data, strlen(data));

    printf("Checksum of %s is %d.\n", data, checksum);

    return 0;
}