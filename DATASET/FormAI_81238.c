//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int i, j, flag = 0;
    
    printf("Enter a word: ");
    scanf("%s", word);

    printf("\n\nReading the word backwards:\n");

    for (i = strlen(word) - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }

    printf("\n\nChecking if it's a palindrome:\n");

    for (i = 0, j = strlen(word) - 1; i < j; i++, j--) {
        if (word[i] != word[j]) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("%s is not a palindrome.", word);
    } else {
        printf("%s is a palindrome!", word);
    }

    printf("\n\n");

    return 0;
}