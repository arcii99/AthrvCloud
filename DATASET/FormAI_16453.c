//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    printf("Welcome to the Typing Speed Test!\n\n");

    char sentence[100] = "The quick brown fox jumps over the lazy dog.";
    printf("Type the following sentence:\n%s\n\n", sentence);

    char input[100];
    int correct = 1;
    int incorrect = 1;
    int i, j = 0;
    clock_t startTime, endTime;
    double timeElapsed;

    // start timer
    startTime = clock();

    // user input
    while (j < 3) {
        printf("Type Here: ");
        fgets(input, 100, stdin);

        for (i = 0; i < 100; i++) {
            if (tolower(input[i]) != tolower(sentence[i])) {
                printf("\nIncorrect, try again!\n");
                incorrect++;
                break;
            }
        }
            if (i == 100) {
            printf("\nCorrect!\n");
            correct++;
            j++;
        }
    }

    // stop timer and calculate elapsed time
    endTime = clock();
    timeElapsed = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // final results
    printf("\nCongratulations, you have completed the Typing Speed Test!\n");
    printf("Total time elapsed: %.2lf seconds\n", timeElapsed);
    printf("Total correct: %d out of %d attempts\n", correct, j - 1);
    printf("Total incorrect: %d out of %d attempts\n", incorrect, j - 1);

    return 0;
}