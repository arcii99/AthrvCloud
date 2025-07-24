//FormAI DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

char cards[ROWS][COLS];

char hiddenCards[ROWS][COLS];

/**
 * This function initializes the cards with random values
 */
void initializeCards()
{
    // Initialize random number generator
    srand(time(NULL));

    int count = 0;
    char charValue = 'A';

    // Generate all possible card values
    while (count < (ROWS * COLS))
    {
        int row = rand() % ROWS;
        int col = rand() % COLS;

        if (cards[row][col] == ' ')
        {
            cards[row][col] = charValue;
            count++;

            // Generate matching card value
            if (count % 2 == 0)
            {
                int row2 = rand() % ROWS;
                int col2 = rand() % COLS;

                while (cards[row2][col2] != ' ')
                {
                    row2 = rand() % ROWS;
                    col2 = rand() % COLS;
                }

                cards[row2][col2] = charValue;
                count++;
            }

            charValue++;
        }
    }
}

/**
 * This function prints the cards' current state, either hidden or revealed
 * @param hidden    whether to print the hidden cards or the revealed ones
 */
void printCards(char hidden)
{
    printf("\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (hidden)
            {
                printf("%c ", hiddenCards[i][j]);
            }
            else
            {
                printf("%c ", cards[i][j]);
            }
        }

        printf("\n");
    }
}

/**
 * This function prompts the user for their chosen card coordinates
 * @param row   output variable for selected row
 * @param col   output variable for selected column
 */
void promptSelection(int *row, int *col)
{
    printf("\nSelect a card (row, col): ");
    scanf("%d %d", row, col);
    printf("\n");
}

/**
 * This function reveals a selected card to the player
 * @param row   selected row
 * @param col   selected column
 */
void revealCard(int row, int col)
{
    hiddenCards[row][col] = cards[row][col];
}

/**
 * This function hides a selected card from the player
 * @param row   selected row
 * @param col   selected column
 */
void hideCard(int row, int col)
{
    hiddenCards[row][col] = 'X';
}

/**
 * This function checks if there are any cards currently hidden
 * @return  whether any cards are currently hidden
 */
int hasHiddenCards()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (hiddenCards[i][j] == 'X')
            {
                return 1;
            }
        }
    }

    return 0;
}

/**
 * This function checks if two selected cards match in value
 * @param row1  first selected card's row
 * @param col1  first selected card's column
 * @param row2  second selected card's row
 * @param col2  second selected card's column
 * @return      whether the two selected cards match
 */
int cardsMatch(int row1, int col1, int row2, int col2)
{
    return (cards[row1][col1] == cards[row2][col2]);
}

int main()
{
    // Initialize cards and hidden cards
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cards[i][j] = ' ';
            hiddenCards[i][j] = 'X';
        }
    }

    // Generate random card values
    initializeCards();

    // Game loop
    while (hasHiddenCards())
    {
        // Print hidden cards
        printCards(1);

        // Prompt player for card selection
        int row1, col1;
        promptSelection(&row1, &col1);

        // Reveal selected card
        revealCard(row1, col1);

        // Print revealed cards
        printCards(0);

        // Prompt player for second card selection
        int row2, col2;
        promptSelection(&row2, &col2);

        // Reveal second selected card
        revealCard(row2, col2);

        // Print final cards
        printCards(0);

        // Check if selected cards match
        if (cardsMatch(row1, col1, row2, col2))
        {
            printf("Cards match!\n");
        }
        else
        {
            // Hide selected cards
            hideCard(row1, col1);
            hideCard(row2, col2);

            printf("Cards do not match.\n");
        }
    }

    printf("You have won the game!\n");

    return 0;
}