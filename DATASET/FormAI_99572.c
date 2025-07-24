//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <ctype.h>

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;
    nl = nw = nc = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (isspace(c)) {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
        if (c == '\n') {
            ++nl;
        }
    }

    printf("Character count: %d\n", nc);
    printf("Word count: %d\n", nw);
    printf("Line count: %d\n", nl);

    return 0;
}