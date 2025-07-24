//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint16_t checksum (uint16_t *addr, uint16_t len) {
    uint32_t sum = 0;
    while (len > 1) {
        sum += *addr++;
        len -= 2;
    }
    if (len == 1) {
        sum += *(uint8_t*)addr;
    }
    // Add carry
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (uint16_t)~sum;
}

int main() {
    char message[100];
    printf("Enter the message to calculate the checksum: ");
    scanf("%[^\n]", message);
    uint16_t len = strlen(message);
    uint16_t *addr = (uint16_t*)message;
    uint16_t result = checksum(addr, len);
    printf("The calculated checksum is: %04x\n", result);
    return 0;
}