//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Calculate checksum
    unsigned long checksum = 0;
    for (int i = 0; i < strlen(input); i++) {
        checksum += (unsigned long) input[i];
    }

    // Add post-apocalyptic twist to output message based on checksum value
    if (checksum % 3 == 0) {
        printf("The checksum of %s is %lu. The world is a barren wasteland, devoid of life.\n", input, checksum);
    } else if (checksum % 3 == 1) {
        printf("The checksum of %s is %lu. Mutated creatures roam the earth, searching for prey.\n", input, checksum);
    } else {
        printf("The checksum of %s is %lu. Refugees huddle together, trying to eke out a living in a shattered world.\n", input, checksum);
    }

    return 0;
}