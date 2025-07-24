//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include<stdio.h>

//function prototypes
void solveSudoku(int puzzle[][9], int x, int y);
int checkBox(int puzzle[][9], int x, int y, int n);
int checkRow(int puzzle[][9], int x, int n);
int checkCol(int puzzle[][9], int y, int n);
void printSudoku(int puzzle[][9]);

int main() {
    int puzzle[9][9]  = {{0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0}}; //initialize puzzle
    solveSudoku(puzzle, 0, 0); //start solving from top left
    printSudoku(puzzle); //print solved puzzle
}

void solveSudoku(int puzzle[][9], int x, int y) {
    if(x == 9) { //if end of row is reached, go to next row
        solveSudoku(puzzle, 0, y+1);
        return;
    }
    if(y == 9) { //if end of column is reached, puzzle is solved
        return;
    }
    if(puzzle[x][y] != 0) { //if cell is not empty, go to next cell
        solveSudoku(puzzle, x+1, y);
        return;
    }
    for(int i=1; i<=9; i++) { //try numbers from 1 to 9
        if(checkBox(puzzle, x, y, i) && checkRow(puzzle, x, i) && checkCol(puzzle, y, i)) {
            puzzle[x][y] = i; //if number is valid, insert in cell
            solveSudoku(puzzle, x+1, y); //continue with next cell
            puzzle[x][y] = 0; //backtrack if solution is incorrect
        }
    }
}

int checkBox(int puzzle[][9], int x, int y, int n) {
    int startX = x - (x%3);
    int startY = y - (y%3);
    for(int i=startX; i<startX+3; i++) {
        for(int j=startY; j<startY+3; j++) {
            if(puzzle[i][j] == n) {
                return 0; //number already exists in box
            }
        }
    }
    return 1; //number is valid in box
}

int checkRow(int puzzle[][9], int x, int n) {
    for(int i=0; i<9; i++) {
        if(puzzle[x][i] == n) {
            return 0; //number already exists in row
        }
    }
    return 1; //number is valid in row
}

int checkCol(int puzzle[][9], int y, int n) {
    for(int i=0; i<9; i++) {
        if(puzzle[i][y] == n) {
            return 0; //number already exists in column
        }
    }
    return 1; //number is valid in column
}

void printSudoku(int puzzle[][9]) {
    printf("+-------+-------+-------+\n");
    for(int i=0; i<9; i++) {
        printf("| ");
        for(int j=0; j<9; j++) {
            printf("%d ", puzzle[i][j]);
            if(j == 2 || j == 5) {
                printf("| ");
            }
        }
        printf("|\n");
        if(i == 2 || i == 5) {
            printf("+-------+-------+-------+\n");
        }
    }
    printf("+-------+-------+-------+\n");
}