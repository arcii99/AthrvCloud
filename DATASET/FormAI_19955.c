//FormAI DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter your romantic text: ");
    fgets(input, 100, stdin);

    // Remove newline character at the end of input
    input[strcspn(input, "\n")] = 0;

    // Count the number of vowels in the input
    int count = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' ||
            input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
            count++;
        }
    }
    printf("Your romantic text contains %d vowels.\n", count);

    // Reverse the input
    printf("Your romantic text backwards: ");
    for (int i = strlen(input) - 1; i >= 0; i--) {
        printf("%c", input[i]);
    }
    printf("\n");

    return 0;
}