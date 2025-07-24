//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: satisfied
#include <stdio.h>
#include <stdint.h>

void generateChecksum(const uint8_t data[], int length, uint8_t* checksum) {
    uint8_t sum = 0; //initialize checksum
    int i;
    for (i = 0; i < length; ++i) {
        sum += data[i]; //sum all bytes of data
    }
    *checksum = ~(sum); //one's compliment of sum is the checksum
}

int main() {
    uint8_t data[] = { 0x01, 0x02, 0x03, 0x04 }; //example data bytes
    int length = sizeof(data) / sizeof(data[0]); //calculate the length of data array
    uint8_t checksum; //initialize checksum
    generateChecksum(data, length, &checksum); //calculate checksum
    printf("Checksum: 0x%02x\n", checksum); //print checksum
    return 0;
}