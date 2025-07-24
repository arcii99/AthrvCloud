//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void reverse_string(char* string) {
    int length = strlen(string);
    for(int i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
}

int main() {
    char original_string[MAX_STRING_LENGTH], reversed_string[MAX_STRING_LENGTH];

    // Read user input
    printf("Enter a string: ");
    fgets(original_string, MAX_STRING_LENGTH, stdin);
    original_string[strcspn(original_string, "\n")] = '\0'; // Remove trailing newline

    // Copy original string to reversed string
    strcpy(reversed_string, original_string);
    
    // Reverse the reversed string
    reverse_string(reversed_string);

    // Compare the two strings
    int result = strcmp(original_string, reversed_string);

    // Print the result
    if(result == 0) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}