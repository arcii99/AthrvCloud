//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char inputStr[100];
    printf("Hello there! Let's do some C string manipulation!\n");

    printf("Please enter a string to manipulate: ");
    fgets(inputStr, 100, stdin);
    // Remove the newline character at the end of the string
    inputStr[strcspn(inputStr, "\n")] = 0;

    printf("Great! You entered: %s\n", inputStr);

    // Convert the string to all uppercase characters
    for (int i = 0; inputStr[i]; i++) {
        if (inputStr[i] >= 'a' && inputStr[i] <= 'z')
            inputStr[i] -= 32;
    }

    printf("String in all uppercase: %s\n", inputStr);

    // Convert the string to all lowercase characters
    for (int i = 0; inputStr[i]; i++) {
        if (inputStr[i] >= 'A' && inputStr[i] <= 'Z')
            inputStr[i] += 32;
    }

    printf("String in all lowercase: %s\n", inputStr);

    // Reverse the string
    int len = strlen(inputStr);
    for (int i = 0; i < len / 2; i++) {
        char temp = inputStr[i];
        inputStr[i] = inputStr[len - i - 1];
        inputStr[len - i - 1] = temp;
    }

    printf("String in reverse: %s\n", inputStr);

    // Find the length of the string
    int length = strlen(inputStr);
    printf("Length of the string is: %d\n", length);

    // Check if the string is a palindrome
    int isPalindrome = 1;
    for (int i = 0; i < length / 2; i++) {
        if (inputStr[i] != inputStr[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("The string is a palindrome!\n");
    else
        printf("The string is not a palindrome.\n");

    printf("Thanks for playing! Bye!\n");

    return 0;
}