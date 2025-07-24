//FormAI DATASET v1.0 Category: Educational ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_WORDS 10 //Maximum number of words allowed in the dictionary
#define MAX_WORD_LENGTH 20 //Maximum length of each word in the dictionary

//Function to fill the dictionary with random words
void fillDictionary(char dictionary[MAX_WORDS][MAX_WORD_LENGTH])
{
    //List of random words to choose from
    char words[10][20] = {"computer", "programming", "algorithm", "memory", "array", "pointer", "string", "function", "variable", "iteration"};

    //Seed the random number generator
    srand((unsigned int) time(NULL));

    //Fill the dictionary with random words
    for(int i=0; i<MAX_WORDS; i++)
    {
        //Choose a random word
        int index = rand() % 10;

        //Copy the chosen word to the dictionary
        strcpy(dictionary[i], words[index]);
    }
}

//Function to print the current state of the game
void printGameState(char guessWord[MAX_WORD_LENGTH], int numGuesses)
{
    printf("\nGuess word: %s\n", guessWord);
    printf("Number of guesses left: %d\n", numGuesses);
}

int main()
{
    char dictionary[MAX_WORDS][MAX_WORD_LENGTH]; //Array to hold the dictionary of words
    char chosenWord[MAX_WORD_LENGTH]; //The word chosen from the dictionary
    char guessWord[MAX_WORD_LENGTH]; //The word that the user is guessing
    int numGuesses = 6; //Number of guesses the user has left
    int wordLength; //Length of the chosen word

    //Fill the dictionary with random words
    fillDictionary(dictionary);

    //Choose a random word from the dictionary
    srand((unsigned int) time(NULL));
    int index = rand() % MAX_WORDS;
    strcpy(chosenWord, dictionary[index]);

    //Initialize guessWord to underscores
    wordLength = strlen(chosenWord);
    for(int i=0; i<wordLength; i++)
    {
        guessWord[i] = '_';
    }
    guessWord[wordLength] = '\0';

    //Print the initial state of the game
    printGameState(guessWord, numGuesses);

    //Loop until the user has guessed the word or run out of guesses
    while(numGuesses > 0 && strcmp(chosenWord, guessWord) != 0)
    {
        //Get a guess from the user
        char guess;
        printf("\nEnter a guess: ");
        scanf(" %c", &guess);

        //Check if the guess is in the chosen word
        int found = 0;
        for(int i=0; i<wordLength; i++)
        {
            if(chosenWord[i] == guess)
            {
                guessWord[i] = guess;
                found = 1;
            }
        }

        //If the guess was not found, decrement the number of guesses
        if(!found)
        {
            numGuesses--;
        }

        //Print the current state of the game
        printGameState(guessWord, numGuesses);
    }

    //Print the final message
    if(numGuesses > 0)
    {
        printf("\nCongratulations! You guessed the word!\n");
    }
    else
    {
        printf("\nSorry, you ran out of guesses. The word was %s.\n", chosenWord);
    }

    return 0;
}