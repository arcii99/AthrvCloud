//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>
#include <stdint.h>

// calculate checksum of given data
uint8_t calculate_checksum(uint8_t *data, uint32_t size) {
    uint8_t sum = 0;
    for (uint32_t i = 0; i < size; i++) {
        sum += data[i];
    }
    return ~(sum & 0xFF) + 1;
}

int main() {
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    uint32_t size = sizeof(data) / sizeof(data[0]);
    
    uint8_t checksum = calculate_checksum(data, size);
    
    printf("Checksum: 0x%02X\n", checksum);
    
    return 0;
}