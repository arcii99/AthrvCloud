//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
/* C Checksum Calculator */
/* Written in a Ken Thompson style */

#include <stdio.h>

int main() {
    char input[100];
    int checksum = 0, i;

    printf("Enter a string to calculate its checksum: ");
    fgets(input, 100, stdin);

    /* Calculate checksum */
    for (i = 0; input[i] != '\n'; i++) {
        checksum += input[i];
        checksum = (checksum << 1) | (checksum >> 31);
    }

    /* Output result */
    printf("The checksum for '%s' is: %X\n", input, checksum);

    return 0;
}