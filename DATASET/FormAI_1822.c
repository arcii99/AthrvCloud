//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>

unsigned char calculate_checksum(unsigned char data[], int length) {
    unsigned char checksum = 0;
    
    for (int i = 0; i < length; i++) {
        checksum += data[i];
    }
    
    return ~checksum;
}

int main() {
    int data_length = 8;    // configurable length of data
    unsigned char data[data_length];
    
    // configurable data values
    data[0] = 0x01;
    data[1] = 0x02;
    data[2] = 0x03;
    data[3] = 0x04;
    data[4] = 0x05;
    data[5] = 0x06;
    data[6] = 0x07;
    data[7] = 0x08;
    
    printf("Data: ");
    for (int i = 0; i < data_length; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
    
    unsigned char checksum = calculate_checksum(data, data_length);
    printf("Checksum: %02x\n", checksum);
    
    return 0;
}