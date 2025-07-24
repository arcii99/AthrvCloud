//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint16_t calc_checksum(int data[], int len) {
    uint32_t sum = 0;
    for (int i = 0; i < len; i++) {
        sum += data[i];
    }

    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    return ~sum;
}

int main() {
    int n;
    printf("Enter the number of elements in the data: ");
    scanf("%d", &n);

    int* data = malloc(n * sizeof(int));
    printf("Enter the data: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    uint16_t checksum = calc_checksum(data, n);
    printf("Checksum: %04X\n", checksum);

    free(data);
    return 0;
}