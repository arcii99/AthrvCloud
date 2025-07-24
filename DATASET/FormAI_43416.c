//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void calculate_checksum(unsigned char *data, unsigned int len) {
    unsigned int checksum = 0;
    unsigned char i = 0;

    while(len-- > 0) {
        checksum += data[i++];
    }

    printf("\nChecksum: %#X\n", checksum);
}

int main() {
    unsigned char *data;
    unsigned int len, i;

    printf("Enter length of data: ");
    scanf("%u", &len);

    // Allocate memory for data array
    data = (unsigned char *) malloc(len * sizeof(unsigned char));

    // Accept data from user
    printf("\nEnter data:\n");
    for(i = 0; i < len; i++) {
        scanf("%hhx", &data[i]);
    }

    // Display input data
    printf("\nInput Data: ");
    for(i = 0; i < len; i++) {
        printf("%02X ", data[i]);
    }

    // Calculate checksum
    calculate_checksum(data, len);

    // Free allocated memory
    free(data);

    return 0;
}