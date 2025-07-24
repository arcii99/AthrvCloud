//FormAI DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

int main() {
    char c, word[MAX_WORD_LENGTH + 1];
    int i = 0, count = 0;

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            if (i < MAX_WORD_LENGTH)
                word[i++] = tolower(c);
        }
        else if (i > 0) {
            word[i] = '\0';
            count++;
            i = 0;
        }
    }

    if (i > 0) {
        word[i] = '\0';
        count++;
    }

    printf("Number of words = %d\n", count);

    return 0;
}