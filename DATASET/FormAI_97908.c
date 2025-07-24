//FormAI DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8  // size of game board
#define MAX_MOVES 20  // maximum number of moves allowed
#define CARD_POOL_SIZE 26  // number of available cards
#define CARD_SIZE 2  // combination of two letters

// function to initialize the game board with random cards
void initialize_board(char board[][BOARD_SIZE])
{
    // initialize random seed
    srand(time(NULL));
    
    // array to keep track of which cards have already been placed on board
    int used_cards[CARD_POOL_SIZE] = {0};
    
    // place cards on board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            // choose random card from pool
            int chosen_card;
            do
            {
                chosen_card = rand() % CARD_POOL_SIZE;
            } while (used_cards[chosen_card]);
            used_cards[chosen_card] = 1;
            
            // set card on board
            board[i][j] = 'A' + chosen_card / 2;
        }
    }
}

// function to display the game board
void display_board(char board[][BOARD_SIZE], int revealed[][BOARD_SIZE])
{
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%c ", 'A' + i);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (revealed[i][j])
            {
                printf("%c ", board[i][j]);
            }
            else
            {
                printf("? ");
            }
        }
        printf("\n");
    }
}

// function to check if two cards match
int match(char board[][BOARD_SIZE], int row1, int col1, int row2, int col2)
{
    return board[row1][col1] == board[row2][col2];
}

// function to reveal a card and return the value of the revealed card
char reveal_card(char board[][BOARD_SIZE], int row, int col)
{
    return board[row][col];
}

// main function
int main()
{
    // initialize game board
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    
    // array to keep track of which cards have been revealed
    int revealed[BOARD_SIZE][BOARD_SIZE] = {0};
    
    // initialize variables
    int moves = 0;
    int game_over = 0;
    
    // start game loop
    while (!game_over)
    {
        // display board
        display_board(board, revealed);
        
        // get input from player
        char input[5];
        int r1, c1, r2, c2;
        do
        {
            printf("Enter two cards (e.g. A1 B2): ");
            fgets(input, 5, stdin);
            r1 = input[0] - 'A';
            c1 = input[1] - '1';
            r2 = input[3] - 'A';
            c2 = input[4] - '1';
        } while (r1 < 0 || r1 >= BOARD_SIZE || c1 < 0 || c1 >= BOARD_SIZE || r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE);
        
        // reveal cards and check for match
        char card1 = reveal_card(board, r1, c1);
        char card2 = reveal_card(board, r2, c2);
        revealed[r1][c1] = revealed[r2][c2] = 1;
        printf("%c %c\n", card1, card2);
        if (match(board, r1, c1, r2, c2))
        {
            printf("Match found!\n");
        }
        else
        {
            printf("No match found.\n");
            moves++;
            if (moves >= MAX_MOVES)
            {
                printf("Game over!\n");
                game_over = 1;
            }
            else
            {
                // hide cards again
                revealed[r1][c1] = revealed[r2][c2] = 0;
            }
        }
    }
    
    return 0;
}