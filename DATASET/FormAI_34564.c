//FormAI DATASET v1.0 Category: String manipulation ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

/* This program will manipulate a string entered by a user by converting all lowercase letters to uppercase,
 * removing any spaces, and reversing the order of the characters. */

int main() {
    char str[100]; // Maximum length of the string is 100 characters.
    int i, j;

    printf("Enter a string you want to manipulate: ");
    fgets(str, sizeof(str), stdin); // Reading input from user

    // Convert all lowercase letters to uppercase
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // ASCII value difference between uppercase and lowercase is 32
        }
    }

    // Remove any spaces from the string
    for(i = j = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ') {
            str[j++] = str[i];
        }
    }

    str[j] = '\0'; // Add null character at the end of the string

    // Reverse the order of characters in the string
    int length = strlen(str);
    char temp;
    for(i = 0; i < length/2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    printf("Manipulated string: %s\n", str);
    return 0; // End of program
}