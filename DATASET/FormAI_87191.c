//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surprised
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    int c = 0, count[26] = {0};

    printf("Enter a string: ");
    scanf("%s", str);

    for (c = 0; str[c] != '\0'; c++) {
        if (isalpha(str[c])) {
            count[toupper(str[c]) - 'A']++;
        }
    }

    printf("\nFrequency of each alphabet:\n");
    for (c = 0; c < 26; c++) {
        printf("%c occurs %d times\n", c+'A', count[c]);
    }

    return 0;
}