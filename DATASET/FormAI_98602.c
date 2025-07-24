//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GUESSES 6
#define WORDS_SIZE 50
#define MAX_LINE_SIZE 1024

// Function to generate a random word from a file
void generate_word(char* word) {
    FILE* fp;
    char line[MAX_LINE_SIZE], temp_word[WORDS_SIZE];
    int count = 0, i = 0;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening the file!\n");
        exit(EXIT_FAILURE);
    }

    // Get the total number of words in the file
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        count++;
    }

    // Generate a random number
    srand(time(NULL));
    int random_index = rand() % count;

    // Get the corresponding word
    rewind(fp);
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        if (i == random_index) {
            strcpy(temp_word, line);
            break;
        }
        i++;
    }

    // Remove the newline character from the word
    temp_word[strlen(temp_word)-1] = '\0';
    strcpy(word, temp_word);

    // Close the file
    fclose(fp);
}

int main() {
    char word[WORDS_SIZE], guessed_word[WORDS_SIZE];
    int len, guesses = 0, i, j;
    char guess;

    // Generate a random word
    generate_word(word);

    // Initialize the guessed word with underscores
    len = strlen(word);
    for (i = 0; i < len; i++) {
        guessed_word[i] = '_';
    }
    guessed_word[len] = '\0';

    // Play the game
    printf("Welcome to the Sherlock Holmes Hangman Game!\n");
    printf("You have %d guesses to find the mystery word.\n", MAX_GUESSES);

    while (guesses < MAX_GUESSES) {
        printf("\nMystery word: %s", guessed_word);

        printf("\nGuess a letter: ");
        scanf(" %c", &guess);
        getchar(); // consume the newline character

        // Check if the letter is in the word
        for (i = 0; i < len; i++) {
            if (word[i] == guess) {
                guessed_word[i] = guess;
            }
        }

        // Check if the game is won
        if (strcmp(word, guessed_word) == 0) {
            printf("\nCongratulations! You found the mystery word: %s\n", word);
            return 0;
        }

        guesses++;

        // Display the hangman
        printf("\n");
        switch (guesses) {
            case 1:
                printf("   ___________\n");
                printf("    |         |\n");
                printf("              |\n");
                printf("              |\n");
                printf("              |\n");
                printf("              |\n");
                printf("              |\n");
                printf("    ==========\n");
                break;
            case 2:
                printf("   ___________\n");
                printf("    |         |\n");
                printf("    O         |\n");
                printf("              |\n");
                printf("              |\n");
                printf("              |\n");
                printf("              |\n");
                printf("    ==========\n");
                break;
            case 3:
                printf("   ___________\n");
                printf("    |         |\n");
                printf("    O         |\n");
                printf("    |         |\n");
                printf("              |\n");
                printf("              |\n");
                printf("              |\n");
                printf("    ==========\n");
                break;
            case 4:
                printf("   ___________\n");
                printf("    |         |\n");
                printf("    O         |\n");
                printf("   /|         |\n");
                printf("              |\n");
                printf("              |\n");
                printf("              |\n");
                printf("    ==========\n");
                break;
            case 5:
                printf("   ___________\n");
                printf("    |         |\n");
                printf("    O         |\n");
                printf("   /|\\        |\n");
                printf("              |\n");
                printf("              |\n");
                printf("              |\n");
                printf("    ==========\n");
                break;
            case 6:
                printf("   ___________\n");
                printf("    |         |\n");
                printf("    O         |\n");
                printf("   /|\\        |\n");
                printf("   /          |\n");
                printf("              |\n");
                printf("              |\n");
                printf("    ==========\n");
                break;
            case 7:
                printf("   ___________\n");
                printf("    |         |\n");
                printf("    O         |\n");
                printf("   /|\\        |\n");
                printf("   / \\        |\n");
                printf("              |\n");
                printf("              |\n");
                printf("    ==========\n");
                printf("Game over! You ran out of guesses.\nThe mystery word was: %s\n", word);
                return 0;
        }
    }

    return 0;
}