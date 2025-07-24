//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include <stdio.h>

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 ,0x09, 0x0A};
    int length = sizeof(data);
    unsigned short int checksum = 0x0000;

    for (int i = 0; i < length; i += 2) {
        unsigned short int word = (data[i] << 8) + data[i+1];
        checksum += word;
        if(checksum > 0xFFFF) { // if carry happens
            checksum &= 0xFFFF; // add carry bit to other end
            checksum++; // add 1
        }
    }

    checksum = ~checksum; // invert all bits of checksum
    printf("Checksum: 0x%04X\n", checksum); // print the checksum in hex

    return 0;
}