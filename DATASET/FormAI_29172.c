//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include <stdio.h>
#include <string.h>

int isPalindrome(char* word, int i, int j) { // recursive function to check for palindrome
    if (i >= j) // base case
        return 1;
    if (word[i] != word[j])
        return 0;
    return isPalindrome(word, i+1, j-1);
}

void palindromeChecker(char* word) {
    int len = strlen(word);
    int i = 0, j = len-1;
    int palindrome = isPalindrome(word, i, j);
    if (palindrome == 1) {
        printf("'%s' is a palindrome!\n", word);
    } else {
        printf("'%s' is not a palindrome.\n", word);
    }
}

int main() {
    char word[100];
    printf("Enter a word to check for palindrome: ");
    fgets(word, 100, stdin);
    word[strcspn(word, "\n")] = 0; // removing newline character from input
    palindromeChecker(word); // checking for palindrome
    return 0;
}