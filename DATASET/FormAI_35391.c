//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* define game constants */
#define MAX_TRIES 6
#define WORDS_COUNT 10

char *words[] = {
    "elephant",
    "penguin",
    "ostrich",
    "hippopotamus",
    "rhinoceros",
    "giraffe",
    "platypus",
    "armadillo",
    "kangaroo",
    "crocodile"
};

const char *HANGMAN_ASCII_ART[] = {
    " +----+\n     |\n     |\n     |\n    ===\n",
    " +----+\n O   |\n     |\n     |\n    ===\n",
    " +----+\n O   |\n |   |\n     |\n    ===\n",
    " +----+\n O   |\n/|   |\n     |\n    ===\n",
    " +----+\n O   |\n/|\\  |\n     |\n    ===\n",
    " +----+\n O   |\n/|\\  |\n/    |\n    ===\n",
    " +----+\n O   |\n/|\\  |\n/ \\  |\n    ===\n"
};

int main(void)
{
    char word[50];
    char letter;
    int wrong_guesses = 0;
    int found_count = 0;
    int random_index;

    /* seed the random number generator */
    srand((unsigned int)time(NULL));

    /* randomly select a word from the list */
    random_index = rand() % WORDS_COUNT;
    strcpy(word, words[random_index]);
    int word_length = strlen(word);

    /* array to track which letters have been found */
    int found_letters[word_length];
    memset(found_letters, 0, sizeof(found_letters));

    /* show initial game state */
    printf("%s\n", HANGMAN_ASCII_ART[0]);
    printf("The word contains %d letters!\n", word_length);
    printf("Guess the letters:\n\n");

    /* main loop for game */
    while (wrong_guesses < MAX_TRIES && found_count < word_length)
    {
        /* display found letters and underscores for missing letters */
        for (int i = 0; i < word_length; i++)
        {
            if (found_letters[i])
            {
                printf("%c ", word[i]);
                found_count++;
            }
            else
            {
                printf("_ ");
            }
        }
        printf("\n\n");

        /* prompt player for letter guess */
        printf("Enter a letter: ");
        scanf(" %c", &letter);
        printf("\n");

        /* check if letter is in word */
        int letter_found = 0;
        for (int i = 0; i < word_length; i++)
        {
            if (word[i] == letter)
            {
                found_letters[i] = 1;
                letter_found = 1;
            }
        }

        /* if letter was not found, increment wrong guesses */
        if (!letter_found)
        {
            wrong_guesses++;
            printf("Wrong guess, try again!\n");
            printf("%s\n", HANGMAN_ASCII_ART[wrong_guesses]);
            printf("%d tries left!\n\n", MAX_TRIES-wrong_guesses);
        }
    }

    /* check if player has won or lost */
    if (found_count == word_length)
    {
        printf("Congratulations, you guessed the word %s!\n", word);
    }
    else
    {
        printf("You lose, the word was %s.\n", word);
        printf("%s\n", HANGMAN_ASCII_ART[MAX_TRIES]);
    }

    return 0;
}