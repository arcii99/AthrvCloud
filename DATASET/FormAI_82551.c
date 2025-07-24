//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_TIME 60

int main() {
    char *words[] = {"apple", "banana", "cherry", "orange", "peach", "pear", "plum", "grape", "kiwi", "mango"};
    int total_words = 10;
    int count = 0, correct = 0, incorrect = 0;
    time_t start_time, end_time;
    double total_time;
    srand(time(NULL));

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be given 60 seconds to type as many words as you can.\n");
    printf("Type the word and press enter to submit.\n\n");
    printf("Press enter to start the test...");
    getchar();

    start_time = time(NULL);
    while ((total_time = difftime(time(NULL), start_time)) < MAX_TIME) {
        int i = rand() % total_words;
        char word[MAX_WORD_LENGTH];

        printf("\n%s: ", words[i]);
        scanf("%s", word);

        count++;
        if (strcmp(word, words[i]) == 0) {
            printf("Correct!");
            correct++;
        } else {
            printf("Incorrect! The correct word is: %s", words[i]);
            incorrect++;
        }
    }

    end_time = time(NULL);
    printf("\n\nTime's up! You typed %d words in %.1lf seconds.\n\n", count, total_time);
    printf("%d words were correct and %d words were incorrect.\n", correct, incorrect);

    return 0;
}