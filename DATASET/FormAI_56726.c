//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_LEN 15
#define TEST_TIME 60

char *words[MAX_WORDS] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "indigo", "jicama", "kiwi", "lemon", "mango", "nectarine", "orange", "pineapple", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "zucchini", "apricot", "blackberry", "cantaloupe", "dragonfruit", "eggplant", "fennel", "grapefruit", "huckleberry", "imbe", "jackfruit", "kumquat", "lime", "mandarin", "nashi", "olive", "papaya", "quinoa", "rhubarb", "starfruit", "tomato", "ugli", "vanilla", "watercress", "xigua", "yellowwatermelon", "zinfandel"};

// Function to generate a random word.
char *get_random_word() {
    return words[rand() % MAX_WORDS];
}

int main() {
    printf("*** Typing Speed Test ***\n\n");
    printf("You will be given random words to type.\n");
    printf("Type as many words as you can in %d seconds.\n\n", TEST_TIME);

    // Initialize the random number generator.
    srand(time(NULL));

    // Variables to keep track of time and scores.
    time_t start_time, now;
    int correct_words = 0, total_words = 0;
    double elapsed_time;

    // Start the test.
    printf("Press Enter to begin...");
    getchar();
    start_time = time(NULL);

    while (1) {
        // Generate a random word and print it.
        char *word = get_random_word();
        printf("\n%s\n", word);
        total_words++;

        // Get the user input.
        char input[MAX_LEN];
        fgets(input, MAX_LEN, stdin);

        // Remove the newline character from the input.
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        // Check if the input is correct.
        if (strcmp(input, word) == 0) {
            correct_words++;
        }

        // Check if the time is up.
        now = time(NULL);
        elapsed_time = difftime(now, start_time);
        if (elapsed_time >= TEST_TIME) {
            break;
        }
    }

    // Compute the score.
    double accuracy = (double) correct_words / (double) total_words * 100;
    double wpm = (double) total_words / elapsed_time * 60;

    // Print the results.
    printf("\nTime's up!\n\n");
    printf("Total words typed: %d\n", total_words);
    printf("Correct words typed: %d\n", correct_words);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("WPM: %.2f\n", wpm);

    return 0;
}