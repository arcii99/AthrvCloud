//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
int compute_checksum(char[]);
void display_checksum(char[]);

int main()
{
    char message[100];
    int checksum;

    // Get input message from user
    printf("Enter the message to compute the checksum for: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    // Compute checksum for message
    checksum = compute_checksum(message);

    // Display final checksum
    display_checksum(message);
}

/**
 * Computes the checksum for a given message.
 * The checksum is computed as the sum of all the
 * ASCII values of the characters in the message.
 *
 * @param message The message for which the checksum is to be computed
 * @return The checksum for the message
 */
int compute_checksum(char message[])
{
    int checksum = 0;
    int i;

    for (i = 0; i < strlen(message); i++) {
        checksum += (int) message[i];
    }

    return checksum;
}

/**
 * Displays the message along with its checksum
 *
 * @param message The message whose checksum is to be displayed
 */
void display_checksum(char message[])
{
    int checksum = compute_checksum(message);

    printf("Message: %s\n", message);
    printf("Checksum: %d", checksum);
}