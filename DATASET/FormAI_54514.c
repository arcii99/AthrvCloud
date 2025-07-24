//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 15

void shuffle(char* arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char* temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    char* words[MAX_WORDS] = {"introspection", "creativity", "typing", "speed", "programming", "language", "computer", "keyboard", "accuracy", "challenge"};
    int num_words = sizeof(words) / sizeof(char*);
    srand(time(NULL));

    printf("\nWelcome to the C typing speed test!\n");
    printf("----------------------------------\n");
    printf("You will be given a series of %d words to type.\n", num_words);
    printf("Type each word and hit enter to proceed to the next one.\n");
    printf("Press any key to start the test.\n");
    getchar();

    shuffle(words, num_words);

    clock_t start = clock();
    int score = 0;

    for (int i = 0; i < num_words; i++) {
        printf("%s: ", words[i]);
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);
        if (strcmp(input, words[i]) == 0) {
            score++;
        }
    }

    clock_t end = clock();

    printf("\n--- Results ---\n");
    printf("Words typed correctly: %d/%d\n", score, num_words);
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time taken: %.2f seconds\n", total_time);
    double wpm = (double)score / total_time * 60;
    printf("Your typing speed is: %.2f words per minute\n", wpm);

    return 0;
}