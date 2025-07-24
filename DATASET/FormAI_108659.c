//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scalable
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

unsigned short calculateChecksum(char *buffer, size_t length) {
    unsigned int checksum = 0;
    for (int i = 0; i < length; i++) {
        if ((i & 1) == 0) {
            checksum += (unsigned int) buffer[i];
        } else {
            checksum += ((unsigned int) buffer[i]) << 8;
        }
    }
    while (checksum >> 16) {
        checksum = (checksum & 0xFFFF) + (checksum >> 16);
    }
    return ~((unsigned short) checksum);
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    printf("Enter the data: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove extra newline character
    unsigned short checksum = calculateChecksum(buffer, strlen(buffer));
    printf("Checksum: %04X\n", checksum);
    return 0;
}