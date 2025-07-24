//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Are you ready to test your typing speed?! Let's get started!\n\n");
    printf("Type the sentences below as fast as you can.\n");
    printf("Press 'Enter' after each sentence to get the next one.\n\n");

    srand(time(NULL));
    const char *sentences[5] = {"The quick brown fox jumps over the lazy dog.",
                                "The five boxing wizards jump quickly.",
                                "Pack my box with five dozen liquor jugs.",
                                "How vexingly quick daft zebras jump.",
                                "Quick fox jumps nightly above wizard."};

    int total_time = 0;
    for (int i = 0; i < 5; i++) {
        printf("%s\n", sentences[i]);
        char input[50];
        time_t start_time = time(NULL);

        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = 0;

        time_t end_time = time(NULL);
        int time_taken = end_time - start_time;
        total_time += time_taken;

        if (strcmp(input, sentences[i]) != 0) {
            printf("\nOh no! You made a mistake. Try again!\n");
            i--;
            total_time -= time_taken;
        } else {
            printf("Time taken for sentence %d: %d seconds.\n\n", i+1, time_taken);
        }
    }

    double avg_time = (double)total_time/5;
    printf("Congratulations! You completed the test!\n");
    printf("Your average time was %.2f seconds.\n", avg_time);
    printf("Thanks for testing your typing speed with us!");

    return 0;
}