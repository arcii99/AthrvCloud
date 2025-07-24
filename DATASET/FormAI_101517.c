//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9 // Size of sudoku grid

void printGrid(int grid[][SIZE]);
int findEmptyLocation(int grid[][SIZE], int *row, int *col);
int isValid(int grid[][SIZE], int row, int col, int num);
int solveSudoku(int grid[][SIZE]);
void multiplayerMode(int grid[][SIZE]);

int main(){
    int grid[SIZE][SIZE] = {
        {0, 0, 0, 0, 6, 4, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 3, 0, 0, 9, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {6, 0, 0, 0, 8, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 0, 0}
    };

    multiplayerMode(grid);

    return 0;
}

void printGrid(int grid[][SIZE]){
    int i, j;
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++)
            printf("%2d", grid[i][j]);
        printf("\n");
    }
}

int findEmptyLocation(int grid[][SIZE], int *row, int *col){
    for (*row = 0; *row < SIZE; (*row)++){
        for (*col = 0; *col < SIZE; (*col)++){
            if (grid[*row][*col] == 0)
                return 1;
        }
    }
    return 0;
}

int isValid(int grid[][SIZE], int row, int col, int num){
    int i, j;
    for (i = 0; i < SIZE; i++){
        if (grid[row][i] == num)
            return 0;
        if (grid[i][col] == num)
            return 0;
    }
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;
    for (i = boxRowStart; i < boxRowStart + 3; i++){
        for (j = boxColStart; j < boxColStart + 3; j++){
            if (grid[i][j] == num)
                return 0;
        }
    }
    return 1;
}

int solveSudoku(int grid[][SIZE]){
    int row, col;
    if (!findEmptyLocation(grid, &row, &col))
        return 1;
    int num;
    for (num = 1; num <= 9; num++){
        if (isValid(grid, row, col, num)){
            grid[row][col] = num;
            if (solveSudoku(grid))
                return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}

void multiplayerMode(int grid[][SIZE]){
    int player1Turn = 1;
    int player2Turn = 0;
    while (!solveSudoku(grid)){
        if (player1Turn == 1){
            printf("\nPlayer 1 Turn\n");
            printGrid(grid);
            int row, col, num;
            printf("\nEnter the row number (1-9): ");
            scanf("%d", &row);
            printf("Enter the column number (1-9): ");
            scanf("%d", &col);
            printf("Enter the number (1-9): ");
            scanf("%d", &num);
            if (isValid(grid, row-1, col-1, num)){
                grid[row-1][col-1] = num;
                player1Turn = 0;
                player2Turn = 1;
            }
            else
                printf("\nInvalid move! Try again.\n");
        }
        else if (player2Turn == 1){
            printf("\nPlayer 2 Turn\n");
            printGrid(grid);
            int row, col, num;
            printf("\nEnter the row number (1-9): ");
            scanf("%d", &row);
            printf("Enter the column number (1-9): ");
            scanf("%d", &col);
            printf("Enter the number (1-9): ");
            scanf("%d", &num);
            if (isValid(grid, row-1, col-1, num)){
                grid[row-1][col-1] = num;
                player1Turn = 1;
                player2Turn = 0;
            }
            else
                printf("\nInvalid move! Try again.\n");
        }
    }
    printf("\nCongratulations, the grid is solved!\n");
    printGrid(grid);
}