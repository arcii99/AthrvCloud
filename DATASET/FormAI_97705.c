//FormAI DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LEN 100 // define maximum length for input string

// function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c); // convert character to lowercase to handle uppercase characters as well
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // read input string from user

    // loop through input string to process each character
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) { // check if character is a letter
            printf("%c is a letter.", str[i]);
            if (isVowel(str[i])) // check if letter is a vowel
                printf(" It is a vowel.\n");
            else
                printf(" It is a consonant.\n");
        }
        else if (isdigit(str[i])) // check if character is a digit
            printf("%c is a digit.\n", str[i]);
        else if (isspace(str[i])) // check if character is a space
            printf(" "); // simply print a space
        else // handle all other characters as special characters
            printf("%c is a special character.\n", str[i]);
    }

    return 0;
}