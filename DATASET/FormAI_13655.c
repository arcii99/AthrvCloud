//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int main()
{
    char word[50], reversed[50];
    int i, j, flag;

    printf("Enter a word: ");
    fgets(word, 50, stdin);

    // Removing the newline character from the input string
    word[strcspn(word, "\n")] = 0;

    // Reversing the input string
    j = strlen(word) - 1;
    for (i = 0; i <= j; i++) {
        reversed[i] = word[j - i];
    }

    flag = strcmp(word, reversed);

    if (flag == 0) {
        printf("The word '%s' is a palindrome!\n", word);
    } else {
        printf("The word '%s' is not a palindrome.\n", word);
    }

    return 0;
}