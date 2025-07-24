//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 10

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words;

    printf("Enter the number of words to test: ");
    scanf("%d", &num_words);

    printf("Enter %d words for the test:\n", num_words);
    for(int i=0; i<num_words; i++) {
        scanf("%s", words[i]);
    }

    printf("Type the following words:\n");
    srand(time(NULL));
    for(int i=0; i<num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    int num_correct = 0;
    clock_t start_time = clock();
    for(int i=0; i<num_words; i++) {
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);
        if(strcmp(input, words[i]) == 0) {
            num_correct++;
        }
    }
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double accuracy = ((double)num_correct / (double)num_words) * 100.0;
    double wpm = ((double)num_words / time_taken) * 60.0;

    printf("You correctly typed %d out of %d words.\n", num_correct, num_words);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Time taken: %.2fs\n", time_taken);
    printf("Words per minute: %.2f\n", wpm);

    return 0;
}