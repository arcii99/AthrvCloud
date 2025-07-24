//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char text[1000];
    int time_taken, cps, len, i, mistakes = 0;
    time_t start, end;
    printf("Welcome to the Typing Speed Test Program\n\n");
    printf("Please type the following text as quickly and accurately as possible:\n\n");

    char random_text[] = "The quick brown fox jumps over the lazy dog.";

    printf("%s\n\n", random_text);

    start = time(NULL);
    fgets(text, 1000, stdin);
    end = time(NULL);

    len = strlen(random_text);

    for(i=0; i<len; i++)
        if(random_text[i] != text[i])
            mistakes++;

    printf("\nYou typed: %s\n", text);

    time_taken = (int)(end - start);
    cps = len / time_taken * 60;
    printf("Time taken: %d seconds\n", time_taken);
    printf("Speed: %d characters per second\n", cps);
    printf("Accuracy: %.2f%%\n\n", (float)(len - mistakes) / len * 100);

    return 0;
}