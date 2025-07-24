//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>

// Function to calculate the checksum of a given array
unsigned int calculate_checksum(unsigned char *data) {
    unsigned int sum = 0;
    int i;
    for (i = 0; i < 50; i++) {
        sum += *data;
        data++;
    }
    return sum;
}

int main() {

    unsigned char data[50];

    // Get input from user
    printf("Enter 50 bytes of data: ");
    scanf("%s", data);

    // Calculate the checksum of the input data
    unsigned int checksum = calculate_checksum(data);

    // Print the checksum
    printf("Checksum of the input data is: %u\n", checksum);

    return 0;
}