//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

void removeSpaces(char input[]);

int checkPalindrome(char input[]);

int main() {
    char inputString[100];
    
    printf("Enter a string: ");
    fgets(inputString, 100, stdin);

    removeSpaces(inputString);
    
    if (checkPalindrome(inputString)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}

void removeSpaces(char input[]) {
    int i, j;
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ') {
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0';
}

int checkPalindrome(char input[]) {
    int i;
    int length = strlen(input);
    for (i = 0; i < length/2; i++) {
        if (input[i] != input[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}