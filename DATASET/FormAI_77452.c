//FormAI DATASET v1.0 Category: Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESSES 6 // Maximum number of guesses
#define MAX_WORD_LENGTH 20 // Maximum length of word to be guessed
#define WORDS_FILE "words.txt"

int main() {
    char word[MAX_WORD_LENGTH + 1]; // Randomly selected word to be guessed
    int wordLength; // Length of the word
    char lettersGuessed[26] = {'\0'}; // Array to store letters that have already been guessed
    int numGuesses = 0; // Number of guesses made so far
    char guess[MAX_WORD_LENGTH + 1]; // Current guess by the user
    int numCorrect = 0; // Number of correct letters guessed so far

    // Open file containing possible words
    FILE* file = fopen(WORDS_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to read from file: %s\n", WORDS_FILE);
        exit(1);
    }

    // Count number of words in file
    int numWords = 0;
    char currentWord[MAX_WORD_LENGTH + 1];
    while (fgets(currentWord, MAX_WORD_LENGTH + 1, file) != NULL) {
        if (strlen(currentWord) <= MAX_WORD_LENGTH) {
            numWords++;
        }
    }
    fseek(file, 0, SEEK_SET);

    // Seed random number generator
    srand(time(NULL));

    // Randomly select a word from the file
    int randomIndex = rand() % numWords;
    int currentIndex = 0;
    while (fgets(currentWord, MAX_WORD_LENGTH + 1, file) != NULL) {
        if (strlen(currentWord) <= MAX_WORD_LENGTH) {
            if (currentIndex == randomIndex) {
                // Copy selected word to variable
                strcpy(word, currentWord);
                // Remove newline character from end of word
                int length = strlen(word);
                if (word[length - 1] == '\n') {
                    word[length - 1] = '\0';
                }
                // Set length of word
                wordLength = strlen(word);
                break;
            }
            currentIndex++;
        }
    }
    fclose(file);

    // Print instructions
    printf("Welcome to Hangman!\n");
    printf("The word to be guessed has %d letters.\n", wordLength);

    // Loop until the user guesses the word or runs out of guesses
    while (numCorrect < wordLength && numGuesses < MAX_GUESSES) {
        // Print current status of the word
        printf("Word: ");
        for (int i = 0; i < wordLength; i++) {
            char c = word[i];
            if (strchr(lettersGuessed, c) != NULL) {
                printf("%c", c);
            } else {
                printf("_");
            }
        }
        printf("\n");

        // Print list of letters already guessed
        printf("Letters guessed: ");
        for (int i = 0; i < strlen(lettersGuessed); i++) {
            printf("%c ", lettersGuessed[i]);
        }
        printf("\n");

        // Get next guess from user
        printf("Guess a letter: ");
        scanf(" %c", &guess[0]);
        guess[1] = '\0';

        // Check if letter has already been guessed
        if (strchr(lettersGuessed, guess[0]) != NULL) {
            printf("You have already guessed the letter %c.\n", guess[0]);
            continue;
        }

        // Add letter to list of letters guessed
        lettersGuessed[strlen(lettersGuessed)] = guess[0];

        // Check if letter is in the word
        if (strchr(word, guess[0]) != NULL) {
            printf("Correct!\n");
            numCorrect++;
        } else {
            printf("Incorrect.\n");
            numGuesses++;
        }
    }

    // Print final status of the word
    printf("Word: ");
    for (int i = 0; i < wordLength; i++) {
        char c = word[i];
        if (strchr(lettersGuessed, c) != NULL) {
            printf("%c", c);
        } else {
            printf("_");
        }
    }
    printf("\n");

    // Check if the user won or lost
    if (numCorrect == wordLength) {
        printf("Congratulations! You guessed the word %s.\n", word);
    } else {
        printf("Sorry, you are out of guesses. The word was %s.\n", word);
    }

    return 0;
}