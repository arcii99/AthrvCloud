//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000];
    int count[26] = {0};

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            count[tolower(input[i]) - 'a']++;
        }
    }

    printf("Character frequency:\n");

    for (int i = 0; i < 26; i++) {
        printf("'%c' : %d\n", i + 'a', count[i]);
    }

    return 0;
}