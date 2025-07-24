//FormAI DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int words = 0;
    char c, last_c = ' ';

    printf("Welcome to the C Word Count Tool!\n\n");
    printf("Please enter your text:\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' && last_c != ' ') {
            words++;
        }
        last_c = c;
    }

    if (last_c != ' ') {
        words++;
    }

    printf("\n\nYour text contains %d words.\n", words);

    return 0;
}