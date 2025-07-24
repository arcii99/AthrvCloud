//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){

    int tries = 5;
    char words[5][20] = {"apple", "banana", "cherry", "durian", "elderberry"};
    int word_length[5] = {5, 6, 6, 6, 10};
    char user_input[20];

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d words to type.\n", tries);

    int correct_counter = 0;
    double total_time = 0.0;

    for (int i = 0; i < tries; i++) {

        int rand_index = rand() % 5;
        clock_t start_time, end_time;
        char word[20];
        strcpy(word, words[rand_index]);
        printf("\nWord %d: %s\n", i+1, word);

        start_time = clock();
        scanf("%s", user_input);
        end_time = clock();
        double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        total_time += time_taken;

        if (strcmp(user_input, word) == 0) {
            correct_counter++;
            printf("Correct!\n");
        } else {
            printf("Incorrect\n");
        }

    }

    printf("\n\nResults:\n");
    printf("You typed %d words correctly out of %d\n", correct_counter, tries);
    printf("Total time taken: %f seconds\n", total_time);
    printf("Average time taken per word: %f seconds\n", (total_time / tries));

    return 0;
}