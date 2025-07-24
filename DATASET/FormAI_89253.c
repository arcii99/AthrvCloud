//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <ctype.h>

int main() {
    int c, i, j;
    int word_count = 0;
    char words[100][100];

    while ((c = getchar()) != EOF) {
        if (isalnum(c)) {
            words[word_count][i++] = c;
        } else if (i > 0) {
            words[word_count][i] = '\0';
            word_count++;
            i = 0;
        }
    }

    int count[word_count];

    for (i = 0; i < word_count; i++) {
        count[i] = 1;
        for (j = i+1; j < word_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count[i]++;
            }
        }
    }

    printf("Word Frequency Counter:\n\n");

    for (i = 0; i < word_count; i++) {
        if (count[i] > 1) {
            printf("%s\t%d\n", words[i], count[i]);
        }
    }

    return 0;
}