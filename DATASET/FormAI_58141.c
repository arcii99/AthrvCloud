//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Function to convert character to ASCII art
void charToArt(char c) {
    switch (c) {
        case 'A':
            printf("  /\\  \n /  \\ \n/    \\\n");
            break;
        case 'B':
            printf(" ____ \n|_  _|\n _| | \n|___|\n");
            break;
        case 'C':
            printf("  ___ \n / __|\n| (__ \n \\___|\n");
            break;
        // Add more cases for other characters
        // ...
        default:
            printf("Invalid character. Please try again.\n");
    }
}

// Function to print ASCII art for a string
void printArt(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        charToArt(str[i]);
        printf("\n");
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    printArt(str);

    return 0;
}