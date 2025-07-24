//FormAI DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 20
#define MAX_TRIES 10

void printRules()
{
    printf("MEMORY GAME\n");
    printf("The objective of the game is to match pairs of cards with the same number\n");
    printf("There are %d cards and you have %d tries to make all the matches\n", MAX_CARDS, MAX_TRIES);
    printf("Good Luck!\n\n");
}

void printBoard(int board[MAX_CARDS], int selected[MAX_CARDS])
{
    printf("\nCurrent Board:\n");
    printf("==============\n");
    for (int i=0; i<MAX_CARDS; i++)
    {
        if (selected[i])
            printf("%d\t", board[i]);
        else
            printf("-\t");
        if ((i+1)%5==0)
            printf("\n");
    }
    printf("\n");
}

void shuffleCards(int board[MAX_CARDS])
{
    srand(time(NULL));
    for (int i=0; i<MAX_CARDS-1; i++)
    {
        int j = i + rand() / (RAND_MAX / (MAX_CARDS-i) + 1);
        int temp = board[j];
        board[j] = board[i];
        board[i] = temp;
    }
}

int main()
{
    int board[MAX_CARDS];
    int selected[MAX_CARDS] = {0};
    int tries = 0;

    // Generate the board
    for (int i=0; i<MAX_CARDS/2; i++)
    {
        board[i] = i+1;
        board[i+MAX_CARDS/2] = i+1;
    }

    // Shuffle the board
    shuffleCards(board);

    // Print the rules
    printRules();

    // Game loop
    while (tries < MAX_TRIES)
    {
        // Print the board
        printBoard(board, selected);

        // Ask for user input
        int first, second;
        printf("Try #%d - Select two cards (1-%d): ", tries+1, MAX_CARDS);
        scanf("%d %d", &first, &second);
        first -= 1; // Adjusting to zero-based indexing
        second -= 1;

        // Check if the inputs are valid
        if (first < 0 || first >= MAX_CARDS || second < 0 || second >= MAX_CARDS || first == second)
        {
            printf("Invalid inputs, please try again\n");
            continue;
        }
        if (selected[first] || selected[second])
        {
            printf("Cards already selected, please try again\n");
            continue;
        }

        // Check if the cards match
        if (board[first] == board[second])
        {
            selected[first] = selected[second] = 1;
            printf("Match found!\n");
        }
        else
        {
            printf("No match, try again\n");
            tries += 1;
        }

        // Check if the game is over
        int matched = 0;
        for (int i=0; i<MAX_CARDS; i++)
        {
            if (selected[i])
                matched += 1;
        }
        if (matched == MAX_CARDS)
        {
            printf("Congratulations, you won in %d tries!\n", tries+1);
            return 0;
        }
    }

    // Game over
    printf("Game Over, you used all your tries.\n");
    printf("Better luck next time!\n");
    return 0;
}