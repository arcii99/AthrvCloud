//FormAI DATASET v1.0 Category: Memory Game ; Style: accurate
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROW 4
#define COL 4

int board[ROW][COL];
int flippedCards[2][2];
int numberOfFlippedCards = 0;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void shuffle(int *arr, int n) {
    srand(time(NULL));
    for(int i=n-1; i>0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

void generateBoard() {
    int tileValues[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
    shuffle(tileValues, 16);

    int i, j;
    // initialize board with tile values
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            board[i][j] = tileValues[i*COL + j];
        }
    }
}

void printBoard() {
    int i, j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

void clearFlippedCards() {
    flippedCards[0][0] = -1;
    flippedCards[0][1] = -1;
    flippedCards[1][0] = -1;
    flippedCards[1][1] = -1;
    numberOfFlippedCards = 0;
}

void flipTile(int row, int col) {
    if(numberOfFlippedCards >= 2) {
        return;
    }

    if(flippedCards[numberOfFlippedCards][0] == row && flippedCards[numberOfFlippedCards][1] == col) {
        return;
    }

    if(board[row][col] == -1) {
        return;
    }

    // flip the tile
    printf("Flipping tile at (%d, %d)...\n", row, col);
    printf("Tile value: %d\n", board[row][col]);
    printf("\n");

    numberOfFlippedCards++;
    flippedCards[numberOfFlippedCards-1][0] = row;
    flippedCards[numberOfFlippedCards-1][1] = col;
}

void checkFlippedCards() {
    if(numberOfFlippedCards != 2) {
        return;
    }

    // check if the tiles match
    if(board[flippedCards[0][0]][flippedCards[0][1]] == board[flippedCards[1][0]][flippedCards[1][1]]) {
        printf("Match found!\n");
        board[flippedCards[0][0]][flippedCards[0][1]] = -1;
        board[flippedCards[1][0]][flippedCards[1][1]] = -1;
    } else {
        printf("No match found.\n");
    }
}

int main() {
    generateBoard();
    clearFlippedCards();
    printBoard();

    int row, col;
    while(1) {
        printf("Enter row and column (separated by space) to flip tile: ");
        scanf("%d%d", &row, &col);
        flipTile(row, col);
        checkFlippedCards();

        if(board[0][0] == -1 && board[0][1] == -1 && board[0][2] == -1 && board[0][3] == -1 &&
           board[1][0] == -1 && board[1][1] == -1 && board[1][2] == -1 && board[1][3] == -1 &&
           board[2][0] == -1 && board[2][1] == -1 && board[2][2] == -1 && board[2][3] == -1 &&
           board[3][0] == -1 && board[3][1] == -1 && board[3][2] == -1 && board[3][3] == -1) {
            printf("Congratulations, you won the game!\n");
            break;
        }
    }

    return 0;
}