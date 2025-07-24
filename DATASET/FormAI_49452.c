//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {

    // Welcome message
    printf("Welcome to the Surrealist Checksum Calculator!\n\n");

    // Get user input
    char input[MAX_LENGTH];
    printf("Enter a string (maximum length %d): ", MAX_LENGTH-1);
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Apply surrealist transformation
    char transformed_input[MAX_LENGTH];
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            transformed_input[i] = 'T'; // Replace spaces with letter "T"
        } else {
            transformed_input[i] = input[i];
        }
    }

    // Calculate checksum
    int sum = 0;
    for (int i = 0; i < strlen(transformed_input); i++) {
        sum += (int) transformed_input[i];
    }

    // Display results
    printf("\nTransformed input: %s\n", transformed_input);
    printf("Checksum: %d\n\n", sum);

    // Exit message
    printf("Thank you for using the Surrealist Checksum Calculator!\n");

    return 0;
}