//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>

int main() {
    char message[] = "hello world";
    int sum = 0;
    int i;

    // Iterate over each character in the message
    for (i = 0; message[i] != '\0'; i++) {
        // Add the ASCII value of the character to the sum
        sum += (int) message[i];
    }

    // Print the sum as the checksum
    printf("Checksum: %d\n", sum);

    return 0;
}