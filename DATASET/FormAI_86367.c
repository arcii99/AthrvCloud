//FormAI DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_GUESSES 10
#define MAX_WORD_LENGTH 20

bool is_guess_correct(char guess, char* word, char* guess_status) {
    bool correct_guess = false;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == guess) {
            guess_status[i] = guess;
            correct_guess = true;
        }
    }
    return correct_guess;
}

bool is_word_guessed(char* guess_status) {
    for (int i = 0; i < strlen(guess_status); i++) {
        if (guess_status[i] == '_') {
            return false;
        }
    }
    return true;
}

void print_guess_status(char* guess_status) {
    for (int i = 0; i < strlen(guess_status); i++) {
        printf("%c ", guess_status[i]);
    }
    printf("\n");
}

void play_game(char* word) {
    int attempts = 0;
    char guess_status[MAX_WORD_LENGTH];
    memset(guess_status, '_', MAX_WORD_LENGTH);
    printf("The word has %d letters.\n", strlen(word));
    print_guess_status(guess_status);
    while (attempts < MAX_GUESSES) {
        printf("\nGuess a letter: ");
        char guess;
        scanf(" %c", &guess);
        if (is_guess_correct(guess, word, guess_status)) {
            printf("Correct guess!\n");
            print_guess_status(guess_status);
            if (is_word_guessed(guess_status)) {
                printf("\nYou won!\n");
                return;
            }
        } else {
            attempts++;
            printf("Incorrect guess, you have %d attempts remaining.\n", MAX_GUESSES - attempts);
        }
    }
    printf("\nYou lost! The word was '%s'\n", word);
}

int main() {
    char* words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig"};
    char* word = words[rand() % (sizeof(words) / sizeof(char*))];
    play_game(word);
    return 0;
}