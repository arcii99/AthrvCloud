//FormAI DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_GUESSES 6
#define WORD_SIZE 20

char *chooseRandomWord(char *wordList[]);
void printWord(char word[], bool guessedLetters[]);
bool checkGuess(char word[], bool guessedLetters[], char guess);
bool checkWin(bool guessedLetters[]);
void printHangman(int incorrectGuesses);

int main(void) {
    char *wordList[] = {"cat", "dog", "elephant", "giraffe", "penguin", "lion", "tiger", "monkey", "zebra", "rhinoceros"};
    char *wordToGuess = chooseRandomWord(wordList);
    int wordLength = strlen(wordToGuess);

    bool guessedLetters[wordLength];
    memset(guessedLetters, false, sizeof(guessedLetters));

    int incorrectGuesses = 0;
    char guess;

    while (incorrectGuesses < MAX_GUESSES && !checkWin(guessedLetters)) {
        printf("Guess the word: ");
        printWord(wordToGuess, guessedLetters);

        printf("Enter a letter: ");
        scanf(" %c", &guess);

        if (checkGuess(wordToGuess, guessedLetters, guess)) {
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
            incorrectGuesses++;
            printHangman(incorrectGuesses);
        }
    }

    if (checkWin(guessedLetters)) {
        printf("Congratulations, you guessed the word!\n");
    } else {
        printf("Sorry, you ran out of guesses. The word was %s.\n", wordToGuess);
    }

    return 0;
}

char *chooseRandomWord(char *wordList[]) {
    int numberOfWords = 10;
    int randomIndex = rand() % numberOfWords;
    return wordList[randomIndex];
}

void printWord(char word[], bool guessedLetters[]) {
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        if (guessedLetters[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }

    printf("\n");
}

bool checkGuess(char word[], bool guessedLetters[], char guess) {
    int length = strlen(word);
    bool correctGuess = false;

    for (int i = 0; i < length; i++) {
        if (word[i] == guess) {
            guessedLetters[i] = true;
            correctGuess = true;
        }
    }

    return correctGuess;
}

bool checkWin(bool guessedLetters[]) {
    int length = sizeof(guessedLetters) / sizeof(guessedLetters[0]);

    for (int i = 0; i < length; i++) {
        if (!guessedLetters[i]) {
            return false;
        }
    }

    return true;
}

void printHangman(int incorrectGuesses) {
    if (incorrectGuesses == 1) {
        printf("  ___\n");
        printf(" |   |\n");
        printf("     |\n");
        printf("     |\n");
        printf("     |\n");
        printf("     |\n");
    } else if (incorrectGuesses == 2) {
        printf("  ___\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("     |\n");
        printf("     |\n");
        printf("     |\n");
    } else if (incorrectGuesses == 3) {
        printf("  ___\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf(" |   |\n");
        printf("     |\n");
        printf("     |\n");
    } else if (incorrectGuesses == 4) {
        printf("  ___\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|   |\n");
        printf("     |\n");
        printf("     |\n");
    } else if (incorrectGuesses == 5) {
        printf("  ___\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|\\  |\n");
        printf("     |\n");
        printf("     |\n");
    } else if (incorrectGuesses == 6) {
        printf("  ___\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|\\  |\n");
        printf("/    |\n");
        printf("     |\n");
    }
}