//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// This function calculates the checksum of a given string using XOR
char calculate_checksum(char* message) {
    char checksum = 0;
    int i = 0;
    while (message[i] != '\0') {
        checksum ^= message[i];
        i++;
    }
    return checksum;
}

int main () {
    char* message = malloc(256 * sizeof(char)); // Allocate memory for the message
    printf("Enter the message: ");
    scanf("%[^\n]%*c", message); // Read the message with spaces
    char checksum = calculate_checksum(message); // Calculate the checksum
    printf("The checksum of the message is: %d\n", checksum);
    free(message); // Free the memory allocated for the message
    return 0;
}