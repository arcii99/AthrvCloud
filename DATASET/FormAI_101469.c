//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Ada Lovelace
#include <stdio.h>
#include <ctype.h>

#define IN 1
#define OUT 0
#define MAXLEN 100

int main() {
    int c, state = OUT, len = 0;
    int freq[MAXLEN];

    for (int i = 0; i < MAXLEN; i++)
        freq[i] = 0;

    while ((c = getchar()) != EOF) {
        if (!isspace(c))
            len++;
        if (isspace(c) || c == '\n') {
            state = OUT;
            if (len != 0 && len < MAXLEN)
                ++freq[len];
            len = 0;
        }
        else if (state == OUT) {
            state = IN;
        }
    }

    printf("%10s %10s\n", "LENGTH", "FREQUENCY");
    for (int i = 1; i < MAXLEN; i++) {
        if (freq[i] > 0) {
            printf("%10d %10d ", i, freq[i]);
            for (int j = 0; j < freq[i]; j++)
                putchar('*');
            putchar('\n');
        }
    }

    return 0;
}