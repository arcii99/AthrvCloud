//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int i, j, length, result = 1;

    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter a word to check if it is a palindrome: ");
    scanf("%s", word);

    length = strlen(word);

    for (i = 0, j = length - 1; i < length/2; i++, j--) {
        if (word[i] != word[j]) {
            result = 0;
            break;
        }
    }

    if (result == 1) {
        printf("\nCongratulations, \"%s\" is a palindrome!\n", word);
        printf("Keep spreading positive vibes, like this palindrome.\n");
    } else {
        printf("\nSorry, \"%s\" is not a palindrome.\n", word);
        printf("Don't worry, there are plenty of other positive things in life.\n");
    }

    return 0;
}