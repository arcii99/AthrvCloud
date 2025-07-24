//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void delay(int seconds) {
    clock_t timeDelay = seconds * CLOCKS_PER_SEC;
    clock_t startTime = clock();
    while (clock() < startTime + timeDelay);
}

int main() {
    printf("Welcome to the Typing Speed Test!\n\n");

    char quote[] = "The quick brown fox jumps over the lazy dog. ";
    int quoteLen = strlen(quote);
    int numChars = 0;
    int i = 0;
    int j = 0;

    printf("You will be given a quote to type out as fast as possible.\n\n");

    printf("Press enter to begin...");
    getchar();

    printf("Type the following quote as fast as possible:\n\"%s\"\n", quote);

    clock_t startTime = clock();
    while (numChars < quoteLen) {
        char c = getchar();

        if (c == quote[numChars]) {
            printf("%c", c);
            numChars++;
        }
        else {
            printf("*");
        }
    }
    clock_t timeElapsed = clock() - startTime;

    printf("\n\nYou typed the quote in %f seconds!\n", (float)timeElapsed / CLOCKS_PER_SEC);

    delay(2);

    printf("\nNow let's see how many words you can type in 60 seconds!\n");
    printf("Press enter to begin...");
    getchar();

    char words[] = "the quick brown fox jumps over the lazy dog";
    int wordsLen = strlen(words);
    int numWords = 0;

    startTime = clock();
    while ((clock() - startTime) / CLOCKS_PER_SEC < 60) {
        j = 0;
        for (i = 0; i < wordsLen; i++) {
            char c = getchar();
            if (c == ' ' || c == '\n') {
                if (i > 0 && words[j] == '\0') {
                    numWords++;
                }
                j = 0;
                continue;
            }
            if (c == words[j]) {
                j++;
            }
            else {
                printf("*");
                j = 0;
            }
        }
    }

    printf("\n\nYou typed %d words in 60 seconds!\n", numWords);

    return 0;
}