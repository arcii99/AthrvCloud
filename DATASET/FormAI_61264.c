//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[100];
    unsigned int checksum = 0;

    printf("Enter the string to be checksummed: ");
    scanf("%s", input);

    // Adding all character ASCII values to the checksum
    for (int i = 0; i < strlen(input); i++) {
        checksum += (unsigned int)input[i];
    }

    // Flipping all the bits in the checksum
    checksum = ~checksum;

    printf("The checksum for '%s' is: 0x%x\n", input, checksum);

    return 0;
}