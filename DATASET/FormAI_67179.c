//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate the checksum
unsigned char calculateChecksum(unsigned char *data, int length) {
    unsigned char checksum = 0;
    int i;

    for (i = 0; i < length; i++) {
        checksum += data[i];
    }

    return checksum;
}

int main() {
    unsigned char *data = (unsigned char*)malloc(50 * sizeof(unsigned char));
    int length, i;

    printf("Welcome to the Checksum Calculator!\n\n");
    printf("Please enter the length of the data you want to calculate the checksum for (between 1 and 50): ");
    scanf("%d", &length);

    // validate input
    if (length < 1 || length > 50) {
        printf("\nInvalid input length. Please enter a value between 1 and 50.\n");
        return 1;
    }

    printf("\nPlease enter the data (maximum of %d characters): ", length);
    scanf("%s", data);

    // truncate if input is longer than specified
    if (strlen(data) > length) {
        data[length] = '\0';
    }

    // calculate the checksum
    unsigned char checksum = calculateChecksum(data, length);

    printf("\nChecksum for data \"%s\" is: %u\n", data, checksum);

    free(data);

    return 0;
}