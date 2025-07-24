//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SENTENCE_COUNT 5
#define SENTENCE_MAX_LEN 100

// Array of sentences for the typing test
char sentences[SENTENCE_COUNT][SENTENCE_MAX_LEN] = {
    "The quick brown fox jumps over the lazy dog.",
    "She sells seashells by the seashore.",
    "Peter Piper picked a peck of pickled peppers.",
    "How much wood would a woodchuck chuck, if a woodchuck could chuck wood?",
    "I scream, you scream, we all scream for ice cream."
};

// Function to shuffle the sentences array
void shuffle_sentences() {
    srand(time(NULL));
    for (int i = SENTENCE_COUNT - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp[SENTENCE_MAX_LEN];
        strcpy(temp, sentences[i]);
        strcpy(sentences[i], sentences[j]);
        strcpy(sentences[j], temp);
    }
}

int main() {
    shuffle_sentences(); // Shuffle the sentences array before the test
    
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be given %d sentences to type, one at a time.\n", SENTENCE_COUNT);
    printf("Type each sentence exactly as it appears on the screen, then press enter.\n");
    printf("The program will track your typing speed, accuracy, and total time taken.\n\n");
    
    printf("Press enter to start the test...");
    getchar(); // Wait for user to press enter
    
    clock_t start_time = clock(); // Record start time of the test
    int total_chars_typed = 0;
    int total_errors = 0;
    
    for (int i = 0; i < SENTENCE_COUNT; i++) {
        printf("\n[SENTENCE %d]\n%s\n\n", i+1, sentences[i]);
        printf("Type the sentence and press enter: ");
        char input[SENTENCE_MAX_LEN];
        fgets(input, SENTENCE_MAX_LEN, stdin);

        // Remove newline character from input string
        int input_len = strlen(input);
        if (input[input_len-1] == '\n') {
            input[input_len-1] = '\0';
            input_len--;
        }

        // Count number of characters typed and number of errors
        int chars_typed = 0;
        int errors = 0;
        for (int j = 0; j < strlen(sentences[i]); j++) {
            if (j >= input_len) {
                errors++;
            } else if (sentences[i][j] != input[j]) {
                errors++;
            }
            chars_typed++;
        }
        total_chars_typed += chars_typed;
        total_errors += errors;

        // Calculate typing speed and accuracy for this sentence
        double accuracy = (double)(chars_typed - errors) / chars_typed * 100.0;
        double time_taken = (double)(clock() - start_time) / CLOCKS_PER_SEC;
        double typing_speed = (double)chars_typed / 5 / time_taken * 60;
        
        // Print results for this sentence
        printf("\n[RESULTS FOR SENTENCE %d]\n", i+1);
        printf("Characters typed: %d\n", chars_typed);
        printf("Errors: %d\n", errors);
        printf("Accuracy: %.2f%%\n", accuracy);
        printf("Typing speed: %.2f WPM\n", typing_speed);
        printf("Time taken: %.2f seconds\n", time_taken);
    }
    
    // Calculate overall typing speed and accuracy for the test
    double overall_accuracy = (double)(total_chars_typed - total_errors) / total_chars_typed * 100.0;
    double overall_time_taken = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    double overall_typing_speed = (double)total_chars_typed / 5 / overall_time_taken * 60;
    
    // Print overall results for the test
    printf("\n[OVERALL RESULTS]\n");
    printf("Total characters typed: %d\n", total_chars_typed);
    printf("Total errors: %d\n", total_errors);
    printf("Overall accuracy: %.2f%%\n", overall_accuracy);
    printf("Overall typing speed: %.2f WPM\n", overall_typing_speed);
    printf("Overall time taken: %.2f seconds\n", overall_time_taken);

    return 0;
}