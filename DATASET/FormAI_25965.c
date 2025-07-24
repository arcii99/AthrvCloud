//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 15
#define MAX_TIME 60 // in seconds

char dictionary[MAX_WORDS][MAX_WORD_LENGTH] = {
    "apple",
    "banana",
    "cherry",
    "date",
    "elderberry",
    "fig",
    "grape",
    "honeydew",
    "kiwi",
    "lemon"
};

void shuffle_dictionary() {
    int i, j;
    char tmp[MAX_WORD_LENGTH];
    srand(time(NULL));
    for (i = MAX_WORDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        strcpy(tmp, dictionary[i]);
        strcpy(dictionary[i], dictionary[j]);
        strcpy(dictionary[j], tmp);
    }
}

void print_dictionary() {
    int i;
    printf("\nType the following words as fast as you can:\n\n");
    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s ", dictionary[i]);
    }
    printf("\n\n");
}

int main() {
    char input[MAX_WORDS][MAX_WORD_LENGTH];
    int i, j, correct_count = 0;
    time_t start_time, end_time;

    shuffle_dictionary();
    print_dictionary();

    time(&start_time);

    // read user input
    for (i = 0; i < MAX_WORDS; i++) {
        printf("Type word #%d: ", i+1);
        scanf("%s", input[i]);
        if (strcmp(input[i], dictionary[i]) == 0) {
            correct_count++;
        }
    }

    time(&end_time);

    double elapsed_time = difftime(end_time, start_time);

    // calculate results
    int total_chars = MAX_WORDS * MAX_WORD_LENGTH;
    int incorrect_chars = total_chars - (correct_count * MAX_WORD_LENGTH);
    double cpm = (double) correct_count / elapsed_time * 60;
    double wpm = cpm / 5;

    printf("\nResults:\n");
    printf("Time elapsed: %.2f seconds\n", elapsed_time);
    printf("Correct words: %d/%d\n", correct_count, MAX_WORDS);
    printf("Incorrect words: %d/%d\n", MAX_WORDS - correct_count, MAX_WORDS);
    printf("Incorrect characters: %d/%d\n", incorrect_chars, total_chars);
    printf("CPM (characters per minute): %.2f\n", cpm);
    printf("WPM (words per minute): %.2f\n", wpm);

    return 0;
}