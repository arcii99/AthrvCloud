//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char sentence[100] = "the quick brown fox jumps over the lazy dog";
    int i, j, cpm, errors = 0, seconds = 0;
    clock_t start_time, end_time;
    float wpm;

    printf("***Typing Speed Test***\n");
    printf("Type the following sentence as fast as you can:\n%s\n\n", sentence);

    printf("Press enter when ready...");
    getchar();

    printf("Type the sentence below:\n");
    start_time = clock();

    for (i = 0; i < 100; i++) {
        j = getchar();
        if (j == sentence[i]) {
            putchar(j);
        } else {
            putchar('*');
            errors++;
        }
        if (j == '\n') {
            break;
        }
    }

    end_time = clock();
    seconds = (end_time - start_time) / CLOCKS_PER_SEC; // calculate elapsed time
    cpm = (i / 5) / (seconds / 60); // calculate characters per minute
    wpm = cpm / 5; // calculate words per minute

    printf("\n\nYou made %d errors.\n", errors);
    printf("Your typing speed is %d characters per minute and %0.2f words per minute.\n", cpm, wpm);

    return 0;
}