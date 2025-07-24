//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {
    char word[50];
    int length, i, j, palindrome = 1;

    printf("Enter a word: ");
    scanf("%s", word);

    length = strlen(word);

    for (i = 0, j = length - 1; i < length / 2; i++, j--) {
        if (word[i] != word[j]) {
            palindrome = 0;
            break;
        }
    }

    if (palindrome) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }
    
    return 0;
}