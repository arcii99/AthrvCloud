//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the Checksum Calculator!\n");
    printf("This program will calculate the checksum of your input.\n\n");

    // Get user input
    char input[50];
    printf("Enter your input (up to 50 characters): ");
    scanf("%s", input);

    // Calculate checksum
    int sum = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        sum += input[i];
    }
    int checksum = sum % 256;

    // Display result
    printf("\nYour input: %s\n", input);
    printf("Checksum: %d\n\n", checksum);

    printf("Isn't that amazing?! The Checksum Calculator has done its magic again!\n");

    return 0;
}