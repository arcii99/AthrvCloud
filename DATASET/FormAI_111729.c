//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum value
unsigned char calculateChecksum(unsigned char* message, int len) {
    unsigned char checksum = 0;
    for(int i=0; i<len; i++) {
        checksum += message[i];
    }
    return ~(checksum);
}

int main() {
    // Welcome message
    printf("Welcome to our Checksum Calculator!\n");

    // Get the input message from the user
    char message[100];
    printf("Please enter the message to calculate the checksum: ");
    scanf("%s", message);

    // Calculate the checksum value
    unsigned char checksum = calculateChecksum((unsigned char*)message, strlen(message));

    // Display the calculated checksum value
    printf("\nThe checksum value of the message [%s] is: %02X", message, checksum);

    return 0;
}