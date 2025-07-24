//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char word[100];

    printf("Welcome to the Palindrome Checker!\n");
    printf("Please enter a word to check if it is palindrome: ");

    scanf("%s", word);

    int length = strlen(word);
    int isPalindrome = 1;

    for(int i = 0; i < length/2; i++) {
        if(word[i] != word[length-i-1]) {
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome) {
        printf("Hooray! '%s' is a palindrome!\n", word);
    } else {
        printf("Oh no! '%s' is not a palindrome.\n", word);
    }

    return 0;
}