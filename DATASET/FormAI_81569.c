//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    int i, j;

    // Prompt user for input
    printf("Enter a string with special characters: ");
    fgets(input, 100, stdin);

    // Loop through input array and remove special characters
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0'; // Add null terminator

    // Print sanitized input
    printf("Sanitized Input: %s\n", input);

    // Ask user if they want to continue
    char answer;
    printf("Do you want to continue? (Y/N) ");
    scanf(" %c", &answer);

    // If user wants to continue, repeat program
    if (toupper(answer) == 'Y') {
        main();
    } else {
        printf("Goodbye!\n");
    }

    return 0;
}