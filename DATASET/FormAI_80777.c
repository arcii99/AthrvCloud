//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//define some constants
#define WIDTH 10
#define HEIGHT 10
#define BOMB_COUNT 20

//define the cell structure
typedef struct {
    bool hasMine;
    bool isHidden;
    bool isFlagged;
    int adjacentMines;
} Cell;

//function prototypes
void initializeBoard(Cell board[][WIDTH]);
void printBoard(Cell board[][WIDTH], bool revealMines);
bool uncoverCell(Cell board[][WIDTH], int row, int col);
void playGame(Cell board[][WIDTH]);

int main() {
    //seed the random number generator
    srand(time(NULL));
    
    //initialize the board, then play the game
    Cell board[HEIGHT][WIDTH];
    initializeBoard(board);
    playGame(board);
    
    return 0;
}

//initialize the board with random bombs and zero adjacent mines
void initializeBoard(Cell board[][WIDTH]) {
    //initialize all cells to hidden and zero adjacent mines
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            board[row][col].hasMine = false;
            board[row][col].isHidden = true;
            board[row][col].isFlagged = false;
            board[row][col].adjacentMines = 0;
        }
    }
    
    //place random bombs on the board
    int bombCount = 0;
    while (bombCount < BOMB_COUNT) {
        int row = rand() % HEIGHT;
        int col = rand() % WIDTH;
        if (!board[row][col].hasMine) {
            board[row][col].hasMine = true;
            bombCount++;
        }
    }
    
    //set the adjacentMines count for each non-bomb cell
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (!board[row][col].hasMine) {
                int count = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int r = row + i;
                        int c = col + j;
                        if (r >= 0 && r < HEIGHT && c >= 0 && c < WIDTH && board[r][c].hasMine) {
                            count++;
                        }
                    }
                }
                board[row][col].adjacentMines = count;
            }
        }
    }
}

//print the game board
void printBoard(Cell board[][WIDTH], bool revealMines) {
    printf("  ");
    for (int col = 0; col < WIDTH; col++) {
        printf(" %d", col);
    }
    printf("\n");
    for (int row = 0; row < HEIGHT; row++) {
        printf("%d ", row);
        for (int col = 0; col < WIDTH; col++) {
            if (board[row][col].isFlagged) {
                printf(" F");
            } else if (board[row][col].isHidden) {
                printf(" X");
            } else if (board[row][col].hasMine && revealMines) {
                printf(" *");
            } else if (board[row][col].adjacentMines > 0) {
                printf(" %d", board[row][col].adjacentMines);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//uncover a cell and return true if it wasn't a bomb, false if it was
bool uncoverCell(Cell board[][WIDTH], int row, int col) {
    //if cell is flagged, do nothing
    if (board[row][col].isFlagged) {
        return true;
    }
    
    //if cell is already uncovered, do nothing
    if (!board[row][col].isHidden) {
        return true;
    }
    
    //uncover the cell and return true if it wasn't a bomb
    board[row][col].isHidden = false;
    if (board[row][col].hasMine) {
        return false;
    }
    
    //if the cell has no adjacent mines, recursively uncover its neighbors
    if (board[row][col].adjacentMines == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int r = row + i;
                int c = col + j;
                if (r >= 0 && r < HEIGHT && c >= 0 && c < WIDTH && board[r][c].isHidden) {
                    uncoverCell(board, r, c);
                }
            }
        }
    }
    
    return true;
}

//play the game loop
void playGame(Cell board[][WIDTH]) {
    bool gameOver = false;
    bool win = false;
    int remainingCells = WIDTH * HEIGHT - BOMB_COUNT;
    
    while (!gameOver) {
        //print the board and prompt the user for a move
        printBoard(board, false);
        printf("Enter your move (row column f/i): ");
        int row, col;
        char move[5];
        scanf("%d %d %s", &row, &col, move);
        
        //handle flag and uncover moves
        if (move[0] == 'f') {
            board[row][col].isFlagged = true;
        } else if (move[0] == 'i') {
            board[row][col].isFlagged = false;
        } else {
            bool validMove = uncoverCell(board, row, col);
            if (!validMove) {
                gameOver = true;
            } else {
                remainingCells--;
                if (remainingCells == 0) {
                    gameOver = true;
                    win = true;
                }
            }
        }
    }
    
    //print the final board and message
    printBoard(board, true);
    if (win) {
        printf("Congratulations, you won!\n");
    } else {
        printf("Sorry, you lost...\n");
    }
}