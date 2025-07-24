//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum
int calculate_checksum(char* message) {
    int checksum = 0;
    int length = strlen(message);

    for (int i = 0; i < length; i++) {
        checksum += message[i];
    }

    return checksum;
}

int main() {
    char message[100];
    printf("Welcome to the Checksum Calculator!\n");
    printf("Please enter your message: ");
    fgets(message, 100, stdin); // Get input from the user

    int checksum = calculate_checksum(message); // Calculate the checksum

    printf("\nYour message: %s", message);
    printf("The checksum of your message is: %d\n", checksum);

    printf("\nThank you for using the Checksum Calculator!\n");

    return 0;
}