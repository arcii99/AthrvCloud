//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// function to generate random words
char* generate_random_word(int length) {
    char* word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + (rand() % 26);
    }
    word[length] = '\0';
    return word;
}

int main() {
    printf("Welcome to the Typing Speed Test program, my dear Watson!\n");
    printf("In order to test your typing skills, please type the words that appear on the screen as quickly and accurately as possible.\n");
    printf("Are you ready?\n");
    printf("Let's begin!\n");

    srand(time(NULL)); // seed random number generator

    char* input; // user input
    int hits = 0; // number of correctly typed words
    int misses = 0; // number of incorrectly typed words
    int total_time = 0; // total time taken to type
    int num_words = 0; // number of words typed

    clock_t start_time, end_time;
    double cpu_time_used;

    printf("Type the word: ");

    // generate first random word
    char* word = generate_random_word(5);
    printf("%s\n", word);
    start_time = clock(); // start timer

    while (1) {
        input = malloc(6 * sizeof(char)); // allocate memory for input

        scanf("%5s", input); // read user input
        num_words++;

        if (strcmp(word, input) == 0) { // compare input with word
            hits++;
        } else {
            misses++;
        }

        end_time = clock(); // stop timer
        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // calculate time taken
        total_time += cpu_time_used;

        if (cpu_time_used >= 60) { // if one minute has passed, end the test
            break;
        }

        // generate new random word
        free(word);
        word = generate_random_word(5);
        printf("\nType the word: %s\n", word);
        start_time = clock(); // restart timer
    }

    printf("\nTest finished! Here are your results:\n");
    printf("Total time taken: %d seconds\n", total_time);
    printf("Total number of words typed: %d\n", num_words);
    printf("Number of correctly typed words: %d\n", hits);
    printf("Number of incorrectly typed words: %d\n", misses);

    free(input);
    free(word);

    printf("\nWell done, my dear Watson! Your typing skills are truly admirable.\n");

    return 0;
}