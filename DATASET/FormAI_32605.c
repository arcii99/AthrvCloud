//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char []);

int main() {
    char input[100];
    printf("Enter a string:\n");
    fgets(input, sizeof(input), stdin); // read input from user
    
    if(isPalindrome(input)) {
        printf("%s is a palindrome\n", input);
    } else {
        printf("%s is not a palindrome\n", input);
    }

    return 0;
}

int isPalindrome(char string[]) {
    int length = strlen(string) - 1; // exclude newline character
    int i, j;
    char c1, c2;

    for(i = 0, j = length; i < j; i++, j--) {
        // ignore spaces and punctuation
        while(!isalnum(string[i]) && i < j) {
            i++;
        }
        while(!isalnum(string[j]) && i < j) {
            j--;
        }

        // convert to lowercase to ignore case
        c1 = tolower(string[i]);
        c2 = tolower(string[j]);

        if(c1 != c2) {
            return 0; // not a palindrome
        }
    }

    return 1; // is a palindrome
}