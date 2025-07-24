//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Function to calculate checksum
int checksum(char msg[]) {
    int sum = 0, i;
    for (i = 0; msg[i] != '\0'; i++) {
        sum += (int)msg[i];
    }
    return sum;
}

// Main function
int main() {
    char message[100];
    printf("Enter message to calculate checksum: ");
    scanf("%[^\n]s",message);   // Read the input string

    // Call the checksum() function to calculate checksum
    int sum = checksum(message);

    printf("Checksum value: %d\n", sum);
    return 0;
}