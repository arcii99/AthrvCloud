//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define POLYNOMIAL 0xA001

unsigned short int getCRC(unsigned char data[], unsigned int len) {
    unsigned short int crc = 0xFFFF;
    int i, j;
    for (i = 0; i < len; i++) {
        crc ^= (unsigned short int)data[i];
        for (j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc >>= 1;
                crc ^= POLYNOMIAL;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

int main() {
    unsigned char data[MAX_SIZE];
    unsigned int len;
    unsigned short int checksum;

    printf("Enter the length of data (maximum %d): ", MAX_SIZE);
    scanf("%d", &len);

    if (len > MAX_SIZE) {
        printf("Error: Data length exceeds maximum size!\n");
        return 1;
    }

    printf("Enter the data (in hexadecimal format, separated by spaces):\n");
    for (int i = 0; i < len; i++) {
        scanf("%hhx", &data[i]);
    }

    checksum = getCRC(data, len);
    printf("Checksum: 0x%04X\n", checksum);

    return 0;
}