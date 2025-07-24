//FormAI DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main() {
    char input[50];
    printf("Enter a string to process: ");
    scanf("%[^\n]s", input);

    // Find the length of the string
    int length = strlen(input);

    // Reverse the string using two pointers approach
    char reverse[length + 1];
    int i, j;
    for (i = length - 1; i >= 0; i--) {
        reverse[length - i - 1] = input[i];
    }
    reverse[length] = '\0';

    // Convert the string to uppercase
    char uppercase[length + 1];
    for (i = 0; i < length; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            uppercase[i] = input[i] - 32;
        } else {
            uppercase[i] = input[i];
        }
    }
    uppercase[length] = '\0';

    // Remove all the vowels from the input string
    char vowel_free[length + 1];
    int k = 0;
    for (i = 0; i < length; i++) {
        if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && input[i] != 'o' && input[i] != 'u' && input[i] != 'A' && input[i] != 'E' && input[i] != 'I' && input[i] != 'O' && input[i] != 'U') {
            vowel_free[k++] = input[i];
        }
    }
    vowel_free[k] = '\0';

    // Print the results
    printf("Length of the string: %d\n", length);
    printf("Reverse of the string: %s\n", reverse);
    printf("Uppercase of the string: %s\n", uppercase);
    printf("String without vowels: %s\n", vowel_free);

    return 0;
}