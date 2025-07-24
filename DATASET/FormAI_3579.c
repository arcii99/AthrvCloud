//FormAI DATASET v1.0 Category: Word Count Tool ; Style: medieval
/* Medieval Word Count Tool */

#include <stdio.h>
#include <ctype.h>

int main() {
    int wordCount = 0;
    char c, prev = ' ';

    printf("Welcome to the Medieval Word Count Tool!\n");
    printf("Enter your text below. End your text with a period (.)\n");

    while (1) {
        c = getchar();

        if (c == '.') break;

        if (isalpha(c)) {
            if (prev == ' ') wordCount++;
            prev = c;
        } else {
            prev = ' ';
        }
    }

    printf("\n\nYour text contained %d words.\n", wordCount);

    return 0;
}