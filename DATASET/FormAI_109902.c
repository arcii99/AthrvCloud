//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, c = 0, t = 0;
    char ch;
    time_t start, end;
    double time_taken;

    printf("Welcome to the Typing Speed Test! Press Enter to start.\n");
    getchar();

    for (i = 0; i < 5; i++) {
        printf("Test %d:\n", i+1);
        printf("Type the following sentence:\n");

        // Generate random sentence
        srand(time(NULL));
        char sentence[50];
        for (j = 0; j < 50; j++) {
            sentence[j] = rand() % 26 + 97; // lowercase letters only
            printf("%c", sentence[j]);
        }
        printf("\n");

        // Get user input and calculate accuracy and speed
        start = time(NULL);
        for (k = 0; k < 50; k++) {
            ch = getchar();
            if (ch == sentence[k]) {
                c++;
            }
        }
        end = time(NULL);
        time_taken = difftime(end, start);
        t += time_taken;
        printf("Your accuracy rate was %.2f%%\n", (float)c/50 * 100);
        printf("Your typing speed was %.2f characters per second\n", 50/time_taken);
        c = 0; // reset counter for next test
        printf("\n");
    }

    printf("Overall, your average typing speed was %.2f characters per second\n", 250/t);
    printf("Thanks for taking the Typing Speed Test! Goodbye.\n");

    return 0;
}