//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void printHeader() {
    printf("\n************************************************\n");
    printf("\tC Checksum Calculator Program\n");
    printf("************************************************\n");
}

unsigned int calculateChecksum(unsigned char* data, int dataSize) {
    unsigned int checksum = 0;
    for(int i=0; i<dataSize; i++) {
        checksum += (unsigned int) data[i];
    }
    return checksum;
}

int main() {
    printHeader();
    printf("Enter the number of elements in the data: ");
    int dataSize;
    scanf("%d", &dataSize);

    if(dataSize <= 0) {
        printf("Invalid input!");
        return 0;
    }

    unsigned char* data = malloc(dataSize * sizeof(unsigned char));
    printf("Enter the data elements: ");
    for(int i=0; i<dataSize; i++) {
        scanf("%hhu", &data[i]);
    }

    unsigned int checksum = calculateChecksum(data, dataSize);
    printf("\nChecksum: %u\n", checksum);

    free(data);
    return 0;
}