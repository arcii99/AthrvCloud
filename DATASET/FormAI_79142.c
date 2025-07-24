//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char str[100], c;
    int i = 0, errors = 0;
    double time_taken;
    time_t start, end;

    printf("Type the following sentence as fast as you can:\n");
    printf("The quick brown fox jumps over the lazy dog.\n");

    time(&start);

    while ((c = getchar()) != '\n')
    {
        if (str[i] != c)
            errors++;

        str[i++] = c;
    }

    time(&end);

    time_taken = difftime(end, start);

    printf("You have made %d error(s).\n", errors);
    printf("Time taken: %.2lf seconds.\n", time_taken);

    return 0;
}