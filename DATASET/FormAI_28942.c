//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
    char message[100], checksum[2];
    int i, sum = 0;

    printf("Enter the message to calculate the C Checksum:\n");
    fgets(message, 100, stdin);

    // Remove newline character
    message[strcspn(message, "\n")] = '\0';

    // Calculate the sum of all characters in the message
    for (i = 0; message[i] != '\0'; i++) {
        sum += message[i];
    }

    // Convert the sum to hexadecimal
    sprintf(checksum, "%02X", sum);

    printf("\nThe C Checksum of the message is: %s\n", checksum);

    return 0;
}