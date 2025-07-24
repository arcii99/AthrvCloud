//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* Function to calculate the C checksum */
unsigned int c_checksum(char *data, int len) {
    unsigned int checksum = 0, carry = 0;
    
    /* Step 1: Add up all the 16-bit words */
    for (int i = 0; i < len; i += 2) {
        checksum += (data[i] << 8) | data[i+1];
        carry = checksum >> 16;     /* Check for carry */
        checksum &= 0xffff;         /* Mask off the upper 16 bits */
        checksum += carry;          /* Add in the carry, if any */
    }
    
    /* Step 2: Take the one's complement of the result */
    checksum = ~checksum;
    
    return checksum;
}

int main() {
    char data[] = {0x87, 0x2c, 0xae, 0xb7, 0x4b, 0x6f, 0x21, 0x65, 
                   0x98, 0x10, 0xc9, 0x2d, 0x3b, 0x50, 0x17, 0xba};
    int len = sizeof(data) / sizeof(data[0]);
    
    /* Calculate the C checksum */
    unsigned int checksum = c_checksum(data, len);
    
    /* Display the checksum in hexadecimal format */
    printf("C checksum: 0x%04x\n", checksum);
    
    return 0;
}