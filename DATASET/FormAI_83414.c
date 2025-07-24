//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20
#define WAIT_TIME 5

int main() {
    srand(time(NULL));
    char words[MAX_WORDS][MAX_WORD_LEN] = {"hello", "world", "programming", "language", "computer",
                                            "science", "algorithm", "database", "binary", "decimal",
                                            "tree", "queue", "stack", "linked", "list",
                                            "function", "recursion", "pointer", "array", "struct",
                                            "novel", "paragraph", "sentence", "literature", "story",
                                            "planet", "galaxy", "universe", "nebula", "comet",
                                            "apple", "banana", "grape", "orange", "kiwi",
                                            "dog", "cat", "hamster", "parrot", "fish",
                                            "car", "bus", "train", "plane", "bike",
                                            "football", "basketball", "soccer", "tennis", "golf",
                                            "kitchen", "bedroom", "bathroom", "living", "room"};
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d seconds to type as many random words as you can.\n", WAIT_TIME);
    printf("Press enter to start.");
    getchar();
    int num_correct = 0;
    int num_total = 0;
    time_t start_time, end_time;
    start_time = time(NULL);
    while (time(NULL) - start_time < WAIT_TIME) {
        int rand_index = rand() % MAX_WORDS;
        printf("%s\n", words[rand_index]);
        char input[MAX_WORD_LEN];
        scanf("%s", input);
        num_total++;
        if (strcmp(input, words[rand_index]) == 0) {
            num_correct++;
        }
    }
    
    end_time = time(NULL);
    printf("Time up!\n");
    printf("You typed %d correct words out of %d total words.\n", num_correct, num_total);
    printf("Your typing speed is %.2f words per minute.\n", (num_correct / ((double)(end_time - start_time) / 60)));
    return 0;
}