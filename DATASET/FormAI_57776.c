//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int i, j, len, flag = 0;

    printf("Enter a word or sentence: ");
    fgets(word, sizeof(word), stdin);

    len = strlen(word);

    // remove newline character from the end of the string
    if (word[len - 1] == '\n') {
        word[len - 1] = '\0';
        len--;
    }

    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        // compare characters from both ends
        if (word[i] != word[j]) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("%s is not a palindrome.\n", word);
    } else {
        printf("%s is a palindrome.\n", word);
    }

    return 0;
}