//FormAI DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define MAX_GUESSES 8

int main()
{
    int numBoard[BOARD_SIZE]; // number board
    int guessBoard[BOARD_SIZE]; // guess board
    int guess1, guess2; // user input guesses
    int numGuesses = 0; // number of guesses made
    int matchedCount = 0; // number of matching pairs found
    int i, j;

    // initialize board with random number pairs
    for(i = 0; i < BOARD_SIZE / 2; i++)
    {
        numBoard[i] = i;
        numBoard[i + BOARD_SIZE / 2] = i;
    }
    
    // shuffle number board using Fisher-Yates algorithm
    srand(time(NULL));
    for(i = BOARD_SIZE - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        int temp = numBoard[i];
        numBoard[i] = numBoard[j];
        numBoard[j] = temp;
    }
    
    // set guess board to all zeros
    for(i = 0; i < BOARD_SIZE; i++)
    {
        guessBoard[i] = 0;
    }
    
    // game loop
    while(numGuesses < MAX_GUESSES && matchedCount < BOARD_SIZE / 2)
    {
        // print current guess board
        printf("   ");
        for(i = 0; i < BOARD_SIZE; i++)
        {
            printf("%d ", guessBoard[i]);
            if(i % 4 == 3) // newline every 4 numbers
            {
                printf("\n   ");
            }
        }
        printf("\n");
        
        // get user input for guesses
        printf("Enter two numbers between 0 and 15: ");
        scanf("%d", &guess1);
        scanf("%d", &guess2);
        
        // check if guesses are valid
        if(guess1 < 0 || guess1 > 15 || guess2 < 0 || guess2 > 15)
        {
            printf("Invalid guess. Please enter two numbers between 0 and 15.\n");
            continue;
        }
        if(guess1 == guess2)
        {
            printf("You cannot guess the same number twice.\n");
            continue;
        }
        if(guessBoard[guess1] != 0 || guessBoard[guess2] != 0)
        {
            printf("That number has already been guessed.\n");
            continue;
        }
        
        // update guess board and number of guesses
        guessBoard[guess1] = numBoard[guess1];
        guessBoard[guess2] = numBoard[guess2];
        numGuesses++;
        
        // check if guesses match
        if(numBoard[guess1] == numBoard[guess2]) 
        {
            printf("Match found!\n");
            matchedCount++;
        }
        else
        {
            printf("No match.\n");
            guessBoard[guess1] = 0;
            guessBoard[guess2] = 0;
        }
    }
    
    // print final guess board and game over message
    printf("\n   ");
    for(i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", guessBoard[i]);
        if(i % 4 == 3)
        {
            printf("\n   ");
        }
    }
    printf("\n\n");
    
    if(matchedCount == BOARD_SIZE / 2)
    {
        printf("Congratulations! You found all the matching pairs in %d guesses.\n", numGuesses);
    }
    else
    {
        printf("Game over. You were not able to find all the matching pairs in %d guesses.\n", MAX_GUESSES);
    }
    
    return 0;
}