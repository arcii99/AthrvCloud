//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char input;
    int seconds;
    int errors = 0;
    int correct = 0;
    int total = 0;
    time_t start, end;
    
    srand(time(NULL));
    printf("Your typing speed test will start now!\n");
    printf("Type as many words as you can in 60 seconds.\n");
    printf("If you make a mistake, it will be counted as an error.\n");
    
    // Countdown
    printf("Get ready...");
    for (int i = 3; i >= 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
    
    time(&start);
    // Loop for 60 seconds
    while ((int)(end - start) < 60) {
        char next_char = rand() % 26 + 97; // Random lowercase letter
        printf("%c", next_char);
        input = getchar();
        if (input == '\n') {
            // End of word
            total++;
            continue;
        }
        if (input == next_char) {
            correct++;
        } else {
            errors++;
        }
    }
    time(&end);
    
    printf("\nTime's up!\n");
    printf("You typed %d words with %d errors.\n", total, errors);
    printf("Your typing speed is %.2f words per minute.\n", ((float)total/ ((float)(end - start) / 60)));
    printf("Your accuracy is %.2f%%.\n", ((float)correct / (float)(correct + errors)) * 100);
    return 0;
}