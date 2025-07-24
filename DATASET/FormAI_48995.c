//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include <stdio.h>
#include <string.h>

// Function to convert the given string to Alien language
void convertToAlienLanguage(char str[]) {
    int i, j;
    char ch;
    int len = strlen(str);

    // Loop through each character in the string and convert to Alien language
    for(i = 0; i < len; i++) {
        ch = str[i];
        if(ch >= 'a' && ch <= 'z') {
            // Convert lowercase letter to uppercase in Alien language
            str[i] = ch - ('a' - 'A');
        } else if(ch >= 'A' && ch <= 'Z') {
            // Convert uppercase letter to lowercase in Alien language
            str[i] = ch + ('a' - 'A');
        } else if(ch >= '0' && ch <= '9') {
            // In Alien language, numbers are replaced by their squares
            str[i] = (ch - '0') * (ch - '0') + '0';
        } else {
            // In Alien language, all other characters are replaced by spaces
            str[i] = ' ';
        }
    }

    // Print the Alien language string
    printf("Alien language: %s\n", str);
}

int main() {
    char str[100];

    // Get the input string from the user
    printf("Enter a string to convert to Alien language: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character from input

    // Convert the input string to Alien language
    convertToAlienLanguage(str);

    return 0;
}