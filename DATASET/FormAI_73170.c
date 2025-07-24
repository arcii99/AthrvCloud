//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDS_PER_MINUTE 60 // Average number of words a human types per minute

// Function to shuffle the words in the array
void shuffle_words(char *words[], int count) {
    srand(time(NULL));
    for (int i = 0; i < count - 1; i++) {
        int j = rand() % (count - i) + i;
        char *temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main() {
    char *words[] = {"programming", "language", "algorithm", "compilation", "debugging",
                     "function", "recursion", "pointer", "structure", "heap", "stack",
                     "memory", "address", "binary", "octal", "hexadecimal", "bitwise",
                     "operator", "conditional", "loop", "switch", "variable", "constant"};
    int count = sizeof(words) / sizeof(words[0]);

    shuffle_words(words, count);

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be given a series of %d random words to type.\n", count);
    printf("Press enter to start the test...");
    getchar();

    clock_t start_time = clock(); // Record the start time

    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
        fflush(stdout);

        char input[20];
        scanf("%s", input);

        if (strcmp(input, words[i]) != 0) {
            printf("Incorrect! The word was '%s'\n", words[i]);
            i--;
        }
    }

    clock_t end_time = clock(); // Record the end time
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nCongratulations! You completed the test in %.2f seconds.\n", elapsed_time);
    printf("Your score is %.2f words per minute.\n", count / (elapsed_time / 60));

    return 0;
}