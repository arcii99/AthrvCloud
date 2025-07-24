//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* This function returns the 32-bit one's complement of the sum of the 16-bit words in the data array. */
uint32_t checksum(uint16_t *data, int len) {
    uint32_t sum = 0;
    uint16_t checksum = 0;
    int i;
    
    for (i = 0; i < len; i++) {
        sum += data[i];
    }
    checksum = (sum & 0xffff) + (sum >> 16);
    checksum = ~(checksum & 0xffff);
    
    return checksum;
}

int main() {
    uint16_t data[5] = {0x1234, 0x5678, 0x9abc, 0xdef0, 0x4321};
    uint32_t checksum_val = 0;
    
    checksum_val = checksum(data, 5);
    
    printf("Checksum Value: 0x%04X", (checksum_val & 0xffff));
    
    return 0;
}