//FormAI DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a given string
void reverseString(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to capitalize every character in a given string
void capitalizeString(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

// Function to remove all spaces from a given string
void removeSpaces(char* str) {
    int len = strlen(str);
    int count = 0;
    for(int i = 0; str[i]; i++) {
        if(str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline

    printf("\nOriginal String: %s\n", str);

    printf("Reversed String: ");
    reverseString(str);
    printf("%s\n", str);

    printf("Capitalized String: ");
    capitalizeString(str);
    printf("%s\n", str);

    printf("String with Spaces Removed: ");
    removeSpaces(str);
    printf("%s\n", str);

    return 0;
}