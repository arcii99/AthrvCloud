//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short calc_checksum(char *data, int size) {
    unsigned short cksum = 0;
    int i;

    for (i = 0; i < size - 1; i += 2) {
        unsigned short word = *(unsigned short *)(data + i);
        cksum += word;
    }

    if (size & 1) {
        cksum += *(unsigned char *)(data + size - 1);
    }

    while (cksum >> 16) {
        cksum = (cksum & 0xffff) + (cksum >> 16);
    }

    return ~cksum;
}

int main() {
    char data[1000];
    int data_len;
    unsigned short checksum;

    printf("Enter data to calculate checksum: ");
    fgets(data, 1000, stdin);
    data_len = strlen(data) - 1;
    checksum = calc_checksum(data, data_len);

    printf("\nResult:\nData: %s", data);
    printf("Checksum: 0x%04x\n", checksum);

    return 0;
}