//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>

int main() {
    int sum = 0;

    printf("Enter the length of the message: ");
    int length;
    scanf("%d", &length);

    printf("Enter the message to calculate the checksum:\n");

    for (int i = 0; i < length; i++) {
        char c;
        scanf(" %c", &c);

        sum += (int) c; // adding ASCII value of each character to the sum
    }

    // take the one's complement of the sum
    sum = ~sum;

    // output the checksum as a hexadecimal value
    printf("Checksum: %x\n", sum);

    return 0;
}