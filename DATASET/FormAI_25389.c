//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the Palindrome Checker program, my dear Watson. Please enter a word:\n");
    char word[100];
    scanf("%s", &word);
    int length = strlen(word);
    int halfLength = length / 2;
    int i;
    for (i = 0; i < halfLength; i++) {
        if (word[i] != word[length - i - 1]) {
            printf("Alas! The word \"%s\" is not a palindrome, my dear Watson.\n", word);
            return 0;
        }
    }
    printf("Congratulations, my dear Watson! The word \"%s\" is indeed a palindrome.\n", word);
    return 0;
}