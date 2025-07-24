//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    char input[100];
    int i, j, length, isPalindrome = 1;
    
    // user inputs a word
    printf("Enter a word: ");
    fgets(input, sizeof(input), stdin);
    
    // convert all characters to lowercase
    for (i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }
    
    length = strlen(input);
    
    // check if the word is a palindrome
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (input[i] != input[j]) {
            isPalindrome = 0;
            break;
        }
    }
    
    // output the result
    printf("--------------------------\n");
    if (isPalindrome) {
        printf("Result: The word is a palindrome\n");
    } else {
        printf("Result: The word is NOT a palindrome\n");
    }
    printf("--------------------------\n");
    
    return 0;
}