//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int calculate_checksum(char *message, size_t len) {
    unsigned int checksum = 0;
    int i;
    
    for (i = 0; i < len; i++) {
        checksum += ((unsigned int)message[i] << (i % 4) * 8);
    }
    
    return checksum;
}

int main() {
    char message[100];
    printf("Enter a message: ");
    fgets(message, 100, stdin);
    size_t len = strlen(message) - 1; // remove newline character
    printf("Message length: %zu\n", len);
    
    unsigned int checksum = calculate_checksum(message, len);
    printf("Checksum: %u\n", checksum);
    
    return 0;
}