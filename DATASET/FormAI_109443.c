//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void populateBoard(int board[][BOARD_SIZE]);
void printBoard(int board[][BOARD_SIZE]);
int getCardRow(char card);
int getCardCol(char card);
void flipCard(int *cards, int board[][BOARD_SIZE], int row, int col);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    char cards[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int flippedCards[2] = {-1, -1};
    int remainingPairs = 8;
    
    srand(time(NULL));
    populateBoard(board);   // Initialize game board
    
    printf("MEMORY GAME\n");
    printf("Try to match all the pairs in as few moves as possible!\n");
    printBoard(board);      // Print initial game board
    
    while (remainingPairs > 0) {
        // Prompt user for card to flip
        printf("Enter the card you want to flip (ex: A1): ");
        char input[3];
        scanf("%s", input);
        int row = getCardRow(input[0]);
        int col = getCardCol(input[1]);
        
        if (row == -1 || col == -1) {   // Invalid input
            printf("Invalid input. Please try again.\n");
        } else if (board[row][col] == -1) {   // Already flipped
            printf("That card has already been matched. Please try again.\n");
        } else {
            flipCard(flippedCards, board, row, col);
            printBoard(board);
            
            if (flippedCards[1] != -1) {
                // Two cards flipped, check if they match
                if (board[flippedCards[0]][flippedCards[1]] == board[flippedCards[2]][flippedCards[3]]) {
                    printf("Match found!\n");
                    remainingPairs--;
                } else {
                    // Cards do not match, flip them back
                    board[flippedCards[0]][flippedCards[1]] = 0;
                    board[flippedCards[2]][flippedCards[3]] = 0;
                    printf("Sorry, those cards don't match.\n");
                }
                flippedCards[0] = -1;   // Reset flipped cards
                flippedCards[1] = -1;
                flippedCards[2] = -1;
                flippedCards[3] = -1;
            }
        }
    }
    
    printf("Congratulations, you won the game!\n");
    return 0;
}

// Populate game board with random card pairs
void populateBoard(int board[][BOARD_SIZE])
{
    int count = 0;
    while (count < BOARD_SIZE * BOARD_SIZE / 2) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        if (board[row][col] == 0) {
            board[row][col] = count + 1;
            board[BOARD_SIZE - 1 - row][BOARD_SIZE - 1 - col] = count + 1;
            count++;
        }
    }
}

// Print the current state of the game board
void printBoard(int board[][BOARD_SIZE])
{
    printf("-----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf(". ");
            } else if (board[i][j] == -1) {
                printf("  ");   // Card has been matched
            } else {
                printf("%c ", board[i][j] + 64);   // Convert card number to letter
            }
        }
        printf("|\n");
    }
    printf("-----------------\n");
}

// Convert the row character input to a row index on the game board
int getCardRow(char card)
{
    if (card < 'A' || card > 'Z') {
        return -1;
    } else {
        return card - 'A';
    }
}

// Convert the column number input to a column index on the game board
int getCardCol(char card)
{
    if (card < '1' || card > '9') {
        return -1;
    } else {
        return card - '1';
    }
}

// Flip a chosen card on the game board and store its position
void flipCard(int *cards, int board[][BOARD_SIZE], int row, int col)
{
    if (board[row][col] == -1) {
        return;   // Card has already been matched
    }
    
    board[row][col] = abs(board[row][col]) * -1;   // Flip the card
    
    if (cards[0] == -1) {
        cards[0] = row;
        cards[1] = col;
    } else if (cards[2] == -1) {
        cards[2] = row;
        cards[3] = col;
    }
}