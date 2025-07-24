//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: single-threaded
#include <stdio.h>

// Function to calculate the checksum
unsigned int calcChecksum(char *data, int len) {
    unsigned int sum = 0;
    int i;
    for (i=0; i<len; i++) {
        sum += data[i];
    }
    return sum;
}

int main() {
    char data[100];
    printf("Enter data: ");
    scanf("%s", data);
    int len = strlen(data);
    unsigned int checksum = calcChecksum(data, len);
    printf("Checksum: %u\n", checksum);
    return 0;
}