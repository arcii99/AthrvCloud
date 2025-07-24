//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include <stdio.h>

int compute_checksum(char *string) {
    int checksum = 0;

    // Loop through each character in the string
    for (int i = 0; string[i] != '\0'; i++) {
        checksum += string[i];
    }

    return checksum;
}

int main() {
    char input[100];
    printf("Welcome to the cheerful Checksum Calculator!\n");

    while (1) {
        printf("Enter a string to calculate its checksum (enter 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            printf("Thank you for using the cheerful Checksum Calculator! Goodbye!\n");
            break;
        }

        // Compute the checksum of the input string
        int checksum = compute_checksum(input);

        printf("The checksum of '%s' is %d.\n", input, checksum);
    }

    return 0;
}