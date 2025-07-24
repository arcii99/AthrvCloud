//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: accurate
#include <stdio.h>

int main() {
    int data[255];
    int checksum = 0;
    int dataSize, i;

    printf("Enter number of elements: ");
    scanf("%d", &dataSize);

    printf("Enter %d integers:\n", dataSize);

    for (i = 0; i < dataSize; i++) {
        scanf("%d", &data[i]);
    }

    for (i = 0; i < dataSize; i++) {
        checksum += data[i];
    }

    checksum = ~(checksum % 256);

    printf("Checksum: %d\n", checksum);

    return 0;
}