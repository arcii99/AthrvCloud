//FormAI DATASET v1.0 Category: Memory Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// Function declarations
void printBoard(int board[][COLS], int rows);
void placeCards(int board[][COLS], int rows, int chosenCards[], int numChosenCards);
void hideCards(int board[][COLS], int rows, int chosenCards[], int numChosenCards);
int selectCard(int board[][COLS], int rows, int cols);

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Initialize the board
    int board[ROWS][COLS] = {{0}};
    int cardCount = ROWS * COLS / 2;
    int chosenCards[cardCount];
    for (int i = 0; i < cardCount; i++)
    {
        // Randomly choose a card
        int card = rand() % 100;
        chosenCards[i] = card;

        // Place the card on the board twice
        placeCards(board, ROWS, chosenCards, i + 1);
    }

    // Print the initial board
    printf("Welcome to the Mind-Bending Memory Game!\n\n");
    printBoard(board, ROWS);

    // Main game loop
    int firstCardRow, firstCardCol, secondCardRow, secondCardCol;
    while (1)
    {
        // Select the first card
        printf("Select the row and column of the first card: ");
        firstCardRow = selectCard(board, ROWS, COLS);
        firstCardCol = selectCard(board, ROWS, COLS);
        printf("\n");

        // Select the second card
        printf("Select the row and column of the second card: ");
        secondCardRow = selectCard(board, ROWS, COLS);
        secondCardCol = selectCard(board, ROWS, COLS);
        printf("\n");

        // Check if the cards match
        if (board[firstCardRow][firstCardCol] == board[secondCardRow][secondCardCol])
        {
            printf("Congratulations, you have a matched pair!\n");
            hideCards(board, ROWS, chosenCards, cardCount);
        }
        else
        {
            printf("Sorry, those cards do not match.\n");
        }

        // Print the updated board
        printBoard(board, ROWS);
    }

    return 0;
}

void printBoard(int board[][COLS], int rows)
{
    printf("    ");
    for (int col = 0; col < COLS; col++)
    {
        printf(" %2d ", col);
    }
    printf("\n");

    printf("   ");
    for (int col = 0; col < COLS; col++)
    {
        printf("+---");
    }
    printf("+\n");

    for (int row = 0; row < rows; row++)
    {
        printf(" %d ", row);
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] < 0)
            {
                printf("|   ");
            }
            else
            {
                printf("| %2d", board[row][col]);
            }
        }
        printf("|\n");

        printf("   ");
        for (int col = 0; col < COLS; col++)
        {
            printf("+---");
        }
        printf("+\n");
    }
}

void placeCards(int board[][COLS], int rows, int chosenCards[], int numChosenCards)
{
    int count = 0;
    while (count < 2)
    {
        int row = rand() % rows;
        int col = rand() % COLS;
        if (board[row][col] == 0)
        {
            board[row][col] = chosenCards[numChosenCards - 1];
            count++;
        }
    }
}

void hideCards(int board[][COLS], int rows, int chosenCards[], int numChosenCards)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == chosenCards[numChosenCards - 1])
            {
                board[row][col] = -1 * chosenCards[numChosenCards - 1];
            }
        }
    }
}

int selectCard(int board[][COLS], int rows, int cols)
{
    int card;
    do {
        scanf("%d", &card);
    } while (card < 0 || card >= rows || board[card][cols] < 0);
    return card;
}