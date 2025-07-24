//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SENTENCE "The quick brown fox jumps over the lazy dog"
#define MAX_ATTEMPTS 5

int main() {
    int i, j, accuracy, attempts = 0;
    char c;
    time_t start, end;
    double time_taken;

    printf("Welcome to the Typing Speed Test!\nType the following sentence:\n\n%s\n\nPress ENTER when ready.\n", SENTENCE);
    getchar();

    do {
        attempts++;
        accuracy = 0;
        time(&start);

        for (i = 0; i < MAX_ATTEMPTS; ++i) {
            printf("Attempt %d of %d:\n", i + 1, MAX_ATTEMPTS);

            for (j = 0; j < sizeof(SENTENCE); ++j) {
                c = getchar();

                if (c == SENTENCE[j]) {
                    accuracy++;
                }
            }

            getchar();
        }

        time(&end);
        time_taken = difftime(end, start);
        printf("\nResults:\n");
        printf("Total time taken: %.2f seconds\n", time_taken);
        printf("Average accuracy: %.2f%%\n", ((float) accuracy / (MAX_ATTEMPTS * sizeof(SENTENCE))) * 100);

        if (attempts < MAX_ATTEMPTS) {
            printf("\nYou can try again (attempt %d of %d) or exit by typing 'q': ", attempts, MAX_ATTEMPTS);
        }
    } while (attempts < MAX_ATTEMPTS && getchar() != 'q');

    printf("\nThank you for taking the Typing Speed Test!\n");

    return EXIT_SUCCESS;
}