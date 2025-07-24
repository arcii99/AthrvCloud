//FormAI DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // read input string from user

    // check if string is palindrome or not
    int i = 0;
    int j = strlen(str) - 1; // last index of the string

    while (j > i) {
        if (str[i++] != str[j--]) { // compare characters from both ends
            printf("The string is not a palindrome.\n");
            return 0;
        }
    }

    printf("The string is a palindrome.\n");

    // count and replace vowels with stars
    int count = 0; // counter for vowels
    for (i = 0; i < strlen(str); i++) {
        switch (str[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                str[i] = '*'; // replace vowel with star
                count++; // increment vowel counter
                break;
            default:
                break;
        }
    }

    printf("The modified string is: %s", str);
    printf("Total vowels: %d\n", count);

    return 0;
}