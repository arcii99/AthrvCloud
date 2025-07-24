//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>

// helper function to determine parity of a byte
int parity(unsigned char byte){
    int count = 0;
    while(byte){
        count += byte & 1;
        byte >>= 1;
    }
    return count % 2 == 0 ? 0 : 1;
}

// main function to calculate checksum of an array of bytes
unsigned char calculate_checksum(unsigned char* data, int length){
    unsigned char checksum = 0;
    for(int i=0; i<length; i++){
        checksum ^= data[i];
        checksum ^= parity(data[i]);
    }
    return checksum;
}

int main(){
    // example usage
    unsigned char data[] = {0x12, 0x34, 0x56, 0x78, 0x9a};
    int length = sizeof(data)/sizeof(data[0]);
    unsigned char checksum = calculate_checksum(data, length);
    printf("Checksum: %02x", checksum);
    return 0;
}