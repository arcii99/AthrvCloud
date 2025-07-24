//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include <stdio.h>
#include <ctype.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
        if (isspace(c))
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("Lines: %d\n", nl);
    printf("Words: %d\n", nw);
    printf("Characters: %d\n", nc);

    return 0;
}