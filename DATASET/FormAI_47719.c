//FormAI DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // the size of the grid
#define MAX_VALUE 8 // maximum value on a card

// function declarations
void initialize(int grid[][SIZE], int row, int col);
void printGrid(int grid[][SIZE], int row, int col);
void shuffle(int cards[], int size);

int main()
{
    int grid[SIZE][SIZE]; // the game grid
    int cards[MAX_VALUE * 2]; // the cards to be matched
    int row, col, numCards, card1Row, card1Col, card2Row, card2Col;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the grid and the cards
    initialize(grid, SIZE, SIZE);
    shuffle(cards, MAX_VALUE * 2);
    
    // Print the instructions
    printf("Welcome to the Memory Game!\n");
    printf("To play, enter the row and column of two cards.\n");
    printf("The cards will be revealed for 2 seconds, then hidden again.\n");
    printf("If the cards match, they will remain visible.\n");
    printf("The game is over when all cards are visible.\n\n");
    
    // Play the game
    numCards = 0;
    while (numCards < MAX_VALUE * 2)
    {
        // Print the current grid
        printGrid(grid, SIZE, SIZE);
        
        // Get the first card
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &card1Row, &card1Col);
        while (card1Row < 1 || card1Row > SIZE || card1Col < 1 || card1Col > SIZE || grid[card1Row - 1][card1Col - 1] != -1)
        {
            printf("Invalid input or card already revealed. Please try again: ");
            scanf("%d %d", &card1Row, &card1Col);
        }
        grid[card1Row - 1][card1Col - 1] = cards[(card1Row - 1) * SIZE + (card1Col - 1) / 2];
        printGrid(grid, SIZE, SIZE);
        
        // Get the second card
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &card2Row, &card2Col);
        while (card2Row < 1 || card2Row > SIZE || card2Col < 1 || card2Col > SIZE || grid[card2Row - 1][card2Col - 1] != -1 || (card2Row == card1Row && card2Col == card1Col))
        {
            printf("Invalid input or card already revealed or the same card as before. Please try again: ");
            scanf("%d %d", &card2Row, &card2Col);
        }
        grid[card2Row - 1][card2Col - 1] = cards[(card2Row - 1) * SIZE + (card2Col - 1) / 2];
        printGrid(grid, SIZE, SIZE);
        
        // Check if the cards match
        if (grid[card1Row - 1][card1Col - 1] == grid[card2Row - 1][card2Col - 1])
        {
            printf("Match found!\n");
        }
        else
        {
            printf("No match. The cards will be hidden again in 2 seconds...\n");
            grid[card1Row - 1][card1Col - 1] = -1;
            grid[card2Row - 1][card2Col - 1] = -1;
            sleep(2);
        }
        
        // Update the number of cards revealed
        numCards = 0;
        for (row = 0; row < SIZE; row++)
        {
            for (col = 0; col < SIZE; col++)
            {
                if (grid[row][col] != -1)
                {
                    numCards++;
                }
            }
        }
    }
    
    // Print the final grid and message
    printGrid(grid, SIZE, SIZE);
    printf("Congratulations! You won!\n");
    
    return 0;
}

// initialize the grid with -1 (hidden cards)
void initialize(int grid[][SIZE], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            grid[i][j] = -1;
        }
    }
}

// print the current grid
void printGrid(int grid[][SIZE], int row, int col)
{
    int i, j;
    printf("\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (grid[i][j] == -1)
            {
                printf("* ");
            }
            else
            {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// shuffle the cards randomly
void shuffle(int cards[], int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        cards[i] = (i / 2) + 1;
    }
    for (i = 0; i < size; i++)
    {
        j = rand() % size;
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}