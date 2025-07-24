//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the sentence below:\n\n");
    printf("The quick brown fox jumps over the lazy dog.\n");

    // Start timer
    clock_t start_time = clock();

    // Read user input
    char input[100];
    fgets(input, 100, stdin);

    // Stop timer
    clock_t end_time = clock();
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Compute accuracy and words per minute
    int correct_chars = 0;
    int total_chars = 0;
    int num_words = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ' || input[i] == '\n') {
            num_words++;
        } else if (input[i] == "The quick brown fox jumps over the lazy dog."[i]) {
            correct_chars++;
        }
        total_chars++;
    }
    double accuracy = ((double) correct_chars) / total_chars * 100;
    double wpm = (((double) total_chars) / 5) / time_taken;

    // Print results
    printf("\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Accuracy: %.2f%c\n", accuracy, '%');
    printf("Words per minute: %.2f\n", wpm);
    printf("Number of words typed: %d\n", num_words);

    return 0;
}