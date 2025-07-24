//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SENTENCE "The quick brown fox jumps over the lazy dog"

int typingSpeed(char *sentence) {
    char typed[100];
    double time_taken;
    printf("Type this sentence:\n%s\n", sentence);
    // Getting input from the user
    fgets(typed, 100, stdin);
    // Remove the newline character from the input
    typed[strcspn(typed, "\n")] = 0;
    // If sentence is not perfectly typed then recursively ask user to try again.
    if (strcmp(sentence, typed) != 0) {
        printf("You typed it wrong. Try again.\n");
        return typingSpeed(sentence);
    }
    // Calculate time taken to type sentence
    time_taken = (double)clock() / CLOCKS_PER_SEC;
    printf("Time taken to type: %.2f seconds\n", time_taken);
    return 0;
}

int main() {
    // Seed for random number generation
    srand(time(0));
    // Generate a random sentence
    char sentence[100];
    strcpy(sentence, SENTENCE);
    int random_shift = rand() % 10 + 1;
    int len = strlen(sentence);
    for (int i = 0; i < len; i++) {
        sentence[i] = sentence[i] + random_shift;
    }
    // Call typingSpeed function
    typingSpeed(sentence);
    return 0;
}