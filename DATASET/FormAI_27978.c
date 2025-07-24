//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    int i, j, temp, score = 0;
    char ch, text[150], input[150];
    float time_taken;

    printf("Welcome to Typing Speed Test!\n");

    printf("\nEnter the text to be typed:\n");
    fgets(text, 150, stdin);

    printf("\nType the text from above (press enter to start):\n");
    getchar();

    clock_t start = clock();

    for (i = 0; text[i] != '\0'; i++) {
        ch = getchar();
        if (ch != text[i]) {
            printf("\nIncorrect! Game over!");
            return 0;
        }
        if (ch == '\n') {
            i++;
            break;
        }
    }
    input[i] = '\0';

    clock_t end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == text[i]) {
            score++;
        }
    }

    printf("\nCongratulations! Your typing speed test has been completed.");
    printf("\nText Typed: %s", input);
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Accuracy: %.2f%%\n", (float) score / i * 100);

    return 0;
}