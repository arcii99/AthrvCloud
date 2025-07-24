//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <time.h> 

#define ROWS 15
#define COLUMNS 15
#define NUMBER_OF_MINES 40

bool gameover = false;
int totalOpenCells = 0;
char minefield[ROWS][COLUMNS];
bool cellOpened[ROWS][COLUMNS];
int adjacentMineCount[ROWS][COLUMNS];
int mines[NUMBER_OF_MINES][2];

void generateMines() {
    int i = 0;
    while (i < NUMBER_OF_MINES) {
        int randomRow = rand() % ROWS;
        int randomColumn = rand() % COLUMNS;

        if (minefield[randomRow][randomColumn] != '*') {
            minefield[randomRow][randomColumn] = '*';
            mines[i][0] = randomRow;
            mines[i][1] = randomColumn;
            i++;
        }
    }
}

void initialize() {
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            minefield[row][column] = '-';
            cellOpened[row][column] = false;
            adjacentMineCount[row][column] = 0;
        }
    }
    generateMines();
}

void displayFirstScreen() {
    printf("\n------------------\n");
    printf("      MINESWEEPER\n");
    printf("------------------\n\n");
    printf("Rules:\n");
    printf("1. You need to open all the cells without detonating a mine.\n");
    printf("2. You can open a cell using its row and column index (e.g. 2 3).\n");
    printf("3. If a cell has a number, it indicates the number of adjacent mines.\n\n");
}

bool isMine(int row, int column) {
    for (int i = 0; i < NUMBER_OF_MINES; i++) {
        if (mines[i][0] == row && mines[i][1] == column) {
            return true;
        }
    }
    return false;
}

bool isValid(int row, int column) {
    return row >= 0 && row < ROWS && column >= 0 && column < COLUMNS;
}

int getAdjacentMineCount(int row, int column) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = column - 1; j <= column + 1; j++) {
            if (isValid(i, j) && isMine(i, j)) {
                count++;
            }
        }
    }
    return count;
}

void setAdjacentMineCounts() {
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            if (minefield[row][column] == '-') {
                int count = getAdjacentMineCount(row, column);
                adjacentMineCount[row][column] = count;
            }
        }
    }
}

void openAllCells() {
    for (int i = 0; i < NUMBER_OF_MINES; i++) {
        int row = mines[i][0];
        int column = mines[i][1];
        minefield[row][column] = 'X';
    }
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            if (minefield[row][column] == '-') {
                int count = adjacentMineCount[row][column];
                if (count > 0) {
                    minefield[row][column] = count + 48;
                } else {
                    minefield[row][column] = ' ';
                }
            }
        }
    }
}

void displayMinefield() {
    printf("\n  ");
    for (int column = 0; column < COLUMNS; column++) {
        printf("%d ", column);
    }
    printf("\n");
    for (int row = 0; row < ROWS; row++) {
        printf("%d ", row);
        for (int column = 0; column < COLUMNS; column++) {
            printf("%c ", minefield[row][column]);
        }
        printf("\n");
    }
    printf("\n");
}

void openAdjacentCells(int row, int column) {
    if (isValid(row, column) && !cellOpened[row][column]) {
        cellOpened[row][column] = true;
        totalOpenCells++;
        int count = adjacentMineCount[row][column];
        if (count > 0) {
            minefield[row][column] = count + 48;
            return;
        } else {
            minefield[row][column] = ' ';
        }
        openAdjacentCells(row - 1, column);
        openAdjacentCells(row + 1, column);
        openAdjacentCells(row, column - 1);
        openAdjacentCells(row, column + 1);
    }
}

void checkForWin() {
    if (totalOpenCells == ROWS * COLUMNS - NUMBER_OF_MINES) {
        openAllCells();
        displayMinefield();
        printf("Congratulations! You have won the game.\n");
        gameover = true;
        exit(0);
    }
}

void revealAllMines() {
    for (int i = 0; i < NUMBER_OF_MINES; i++) {
        int row = mines[i][0];
        int column = mines[i][1];
        minefield[row][column] = 'X';
    }
}

void checkForLoss(int row, int column) {
    if (isMine(row, column)) {
        revealAllMines();
        displayMinefield();
        printf("Game over! You stepped on a mine.\n");
        gameover = true;
        exit(0);
    }
}

void play() {
    while (!gameover) {
        displayMinefield();
        printf("Enter cell row and column: ");
        int row, column;
        scanf("%d%d", &row, &column);
        if (!isValid(row, column) || cellOpened[row][column]) {
            printf("Invalid cell.\n");
            continue;
        }
        openAdjacentCells(row, column);
        checkForLoss(row, column);
        checkForWin();
    }
}

int main() {
    srand(time(NULL));
    initialize();
    setAdjacentMineCounts();
    displayFirstScreen();
    play();

    return 0;
}