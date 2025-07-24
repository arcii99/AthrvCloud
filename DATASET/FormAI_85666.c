//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;
    int skip_whitespace = 1;
    
    nl = nw = nc = 0;
    state = OUT;
    
    while ((c = getchar()) != EOF) {
        ++nc;

        if (skip_whitespace) {
            if (isspace(c)) continue;
            skip_whitespace = 0;
        }

        if (c == '\n') {
            ++nl;
            skip_whitespace = 1;
        }

        if (isspace(c)) {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    
    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}