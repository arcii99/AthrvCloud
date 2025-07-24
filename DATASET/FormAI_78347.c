//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int c;
    int count[26] = {0};

    printf("Please input some text: \n");

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            c = tolower(c);
            count[c - 'a']++;
        }
    }

    printf("Character Frequency\n");

    for (int i = 0; i < 26; i++) {
        printf("%c %d\n", i + 'a', count[i]);
    }

    return 0;
}