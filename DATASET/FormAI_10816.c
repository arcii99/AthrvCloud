//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

// Function Prototypes
void initializeBoard(char board[][COLUMNS]);
void playGame(char board[][COLUMNS], int *score);
void printBoard(char board[][COLUMNS]);
void movePlayer(char board[][COLUMNS], int *playerRow, int *playerColumn, int direction, int *score);
void generateGhost(char board[][COLUMNS]);
void generateTreasure(char board[][COLUMNS]);

// Main Function
int main(void){
    char board[ROWS][COLUMNS];
    int score = 0;
    
    initializeBoard(board);
    playGame(board, &score);
    
    printf("Game Over! Your score was %d.\n", score);
    
    return 0;
}

// Function Definitions

// Initializes the game board
void initializeBoard(char board[][COLUMNS]){
    int i, j;
    
    // Initialize all cells to empty
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            board[i][j] = '.';
        }
    }
    
    // Place the player in the center
    board[ROWS/2][COLUMNS/2] = 'P';
    
    // Generate initial ghosts and treasure
    srand((unsigned int) time(NULL));
    generateGhost(board);
    generateTreasure(board);
}

// Plays the game
void playGame(char board[][COLUMNS], int *score){
    int playerRow = ROWS/2;
    int playerColumn = COLUMNS/2;
    char direction;
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are currently in room (%d,%d).\n", playerRow, playerColumn);
    
    while(1){
        printBoard(board);
        printf("Your current score is %d.\n", *score);
        printf("Enter a direction to move (WASD): ");
        scanf(" %c", &direction);
        movePlayer(board, &playerRow, &playerColumn, direction, score);
        
        // Check if player wins or loses
        if(board[playerRow][playerColumn] == 'T'){
            printf("Congratulations! You found the treasure and escaped the haunted house.\n");
            break;
        } else if(board[playerRow][playerColumn] == 'G'){
            printf("You encountered a ghost and lost the game.\n");
            break;
        }
    }
}

// Prints the game board
void printBoard(char board[][COLUMNS]){
    int i, j;
    
    printf(" ");
    for(i = 0; i < COLUMNS; i++){
        printf("%d", i);
    }
    printf("\n");
    
    for(i = 0; i < ROWS; i++){
        printf("%d", i);
        for(j = 0; j < COLUMNS; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Moves the player in the specified direction
void movePlayer(char board[][COLUMNS], int *playerRow, int *playerColumn, int direction, int *score){
    int newRow = *playerRow;
    int newColumn = *playerColumn;
    
    switch(direction){
        case 'w':
        case 'W':
            newRow -= 1;
            break;
        case 'a':
        case 'A':
            newColumn -= 1;
            break;
        case 's':
        case 'S':
            newRow += 1;
            break;
        case 'd':
        case 'D':
            newColumn += 1;
            break;
    }
    
    // Check if new position is within board bounds
    if(newRow < 0 || newRow >= ROWS || newColumn < 0 || newColumn >= COLUMNS){
        printf("Invalid move.\n");
        return;
    }
    
    // Move the player to the new position
    if(board[newRow][newColumn] == '.'){
        board[*playerRow][*playerColumn] = '.';
        board[newRow][newColumn] = 'P';
        *playerRow = newRow;
        *playerColumn = newColumn;
    } else if(board[newRow][newColumn] == 'G'){
        printf("You encountered a ghost and lost the game.\n");
        exit(0);
    } else if(board[newRow][newColumn] == 'T'){
        board[*playerRow][*playerColumn] = '.';
        board[newRow][newColumn] = 'P';
        *playerRow = newRow;
        *playerColumn = newColumn;
        *score += 100;
    }
    
    // Generate new ghosts and treasure
    generateGhost(board);
    generateTreasure(board);
}

// Generates a ghost in a random location on the board
void generateGhost(char board[][COLUMNS]){
    int row, column;
    
    // Remove all existing ghosts from the board
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            if(board[i][j] == 'G'){
                board[i][j] = '.';
            }
        }
    }
    
    // Generate a new ghost in a random location
    do {
        row = rand() % ROWS;
        column = rand() % COLUMNS;
    } while(board[row][column] != '.');
    
    board[row][column] = 'G';
}

// Generates the treasure in a random location on the board
void generateTreasure(char board[][COLUMNS]){
    int row, column;
    
    // Remove all existing treasure from the board
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            if(board[i][j] == 'T'){
                board[i][j] = '.';
            }
        }
    }
    
    // Generate a new treasure in a random location
    do {
        row = rand() % ROWS;
        column = rand() % COLUMNS;
    } while(board[row][column] != '.');
    
    board[row][column] = 'T';
}