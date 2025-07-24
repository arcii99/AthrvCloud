//FormAI DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50 // Define the number of rows
#define COLUMNS 100 // Define the number of columns
#define GENERATIONS 100 // Define the number of generations

void initBoard(int board[ROWS][COLUMNS]){ // Initialize board with random cells
    srand(time(NULL)); // Seed random number generator
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            board[i][j] = rand() < RAND_MAX / 2 ? 1 : 0; // Randomly generate cells
        }
    }
}

void printBoard(int board[ROWS][COLUMNS]){ // Display the current state of the board
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            if(board[i][j] == 1){
                printf("*"); // Alive cell is represented by *
            }
            else{
                printf("-"); // Dead cell is represented by -
            }
        }
        printf("\n");
    }
}

int countNeighbors(int board[ROWS][COLUMNS], int row, int column){ // Count the number of live neighbors for a cell
    int count = 0;
    for(int i = row - 1; i <= row + 1; i++){
        for(int j = column - 1; j <= column + 1; j++){
            if(i == row && j == column){
                continue; // Ignore the cell itself
            }
            if(i < 0 || i >= ROWS || j < 0 || j >= COLUMNS){
                continue; // Ignore cells outside the board
            }
            if(board[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}

void nextGeneration(int board[ROWS][COLUMNS]){ // Calculate the next state of the game
    int newBoard[ROWS][COLUMNS] = {0}; // Initialize the new board to all dead cells
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            int neighbors = countNeighbors(board, i, j);
            if(board[i][j] == 1){ // If the cell is alive
                if(neighbors < 2 || neighbors > 3){ // Underpopulation or overpopulation
                    newBoard[i][j] = 0; // Cell dies
                }
                else{ // Survival
                    newBoard[i][j] = 1; // Cell stays alive
                }
            }
            else{ // If the cell is dead
                if(neighbors == 3){ // Reproduction
                    newBoard[i][j] = 1; // Cell comes alive
                }
            }
        }
    }
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            board[i][j] = newBoard[i][j]; // Copy the new board to the old board
        }
    }
}

int main(){
    int board[ROWS][COLUMNS];
    initBoard(board);
    printBoard(board);
    for(int i = 0; i < GENERATIONS; i++){
        nextGeneration(board);
        printBoard(board);
    }
    return 0;
}