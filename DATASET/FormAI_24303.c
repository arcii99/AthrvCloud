//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char word[]);

int main() {
    char word[50];
    printf("Enter a word: ");
    scanf("%s", word);

    if (isPalindrome(word)) {
        printf("%s is a palindrome.", word);
    } else {
        printf("%s is not a palindrome.", word);
    }

    return 0;
}

bool isPalindrome(char word[]) {
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - 1 - i]) {
            return false;
        }
    }
    return true;
}