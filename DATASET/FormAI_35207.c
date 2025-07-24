//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, num3;
    int checksum;

    printf("Enter three integers: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    // Calculate the checksum
    checksum = (num1 + num2 + num3) % 256;

    printf("Original numbers: %d, %d, %d\n", num1, num2, num3);
    printf("Checksum: %d\n", checksum);

    return 0;
}