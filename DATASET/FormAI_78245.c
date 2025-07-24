//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_LENGTH 100

unsigned char compute_checksum(char* data, int length);

int main() {
    char data[MAX_LENGTH];
    int i, length;
    unsigned char checksum;

    printf("Enter data to be checksummed (max length %d): ", MAX_LENGTH);
    fgets(data, MAX_LENGTH, stdin);

    length = strlen(data);

    // remove any newline character from input
    if (data[length-1] == '\n') {
        data[length-1] = '\0';
        length--;
    }

    checksum = compute_checksum(data, length);

    printf("Checksum: %02X\n", checksum);

    return 0;
}

unsigned char compute_checksum(char* data, int length) {
    int i;
    unsigned char checksum = 0;

    for (i=0; i<length; i++) {
        checksum ^= data[i];
    }

    return checksum;
}