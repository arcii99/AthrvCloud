//FormAI DATASET v1.0 Category: Memory Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// function prototypes
void initializeBoard(int board[][COLS], int num);
void shuffle(int board[][COLS]);
void printBoard(int board[][COLS]);
int checkWin(int board[][COLS]);
int isValid(int row, int col);
int isMatch(int board[][COLS], int row1, int col1, int row2, int col2);
void playGame(int board[][COLS]);

int main() {
    int board[ROWS][COLS];
    initializeBoard(board, (ROWS * COLS) / 2);
    shuffle(board);
    playGame(board);
    return 0;
}

void initializeBoard(int board[][COLS], int num) {
    srand(time(NULL));
    int arr[num];
    for(int i=0; i<num; i++){
        arr[i] = i+1;
    }
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            int index = rand() % num;
            board[i][j] = arr[index];
            arr[index] = arr[num-1];
            num--;
        }
    }
}

void shuffle(int board[][COLS]) {
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            int x1 = rand() % ROWS;
            int y1 = rand() % COLS;
            int x2 = rand() % ROWS;
            int y2 = rand() % COLS;
            int temp = board[x1][y1];
            board[x1][y1] = board[x2][y2];
            board[x2][y2] = temp;
        }
    }
}

void printBoard(int board[][COLS]) {
    printf("------------------\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("|%2d  ", board[i][j]);
        }
        printf("|\n");
        printf("------------------\n");
    }
}

int checkWin(int board[][COLS]) {
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(board[i][j] != -1){
                return 0;
            }
        }
    }
    return 1;
}

int isValid(int row, int col) {
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS){
        printf("Invalid Input!\n");
        return 0;
    }
    return 1;
}

int isMatch(int board[][COLS], int row1, int col1, int row2, int col2) {
    if(board[row1][col1] == board[row2][col2]){
        board[row1][col1] = board[row2][col2] = -1;
        return 1;
    }
    printf("Sorry, Try Again!\n");
    return 0;
}

void playGame(int board[][COLS]) {
    int row1, col1, row2, col2, counter = 0;
    printf("*** Welcome to Memory Game ***\n");
    while(!checkWin(board)){
        printf("Enter the row and column of first card: ");
        scanf("%d %d", &row1, &col1);
        if(!isValid(row1, col1)){
            continue;
        }
        if(board[row1][col1] == -1){
            printf("This card is already matched!\n");
            continue;
        }
        printf("Enter the row and column of second card: ");
        scanf("%d %d", &row2, &col2);
        if(!isValid(row2, col2)){
            continue;
        }
        if(board[row2][col2] == -1){
            printf("This card is already matched!\n");
            continue;
        }
        if(isMatch(board, row1, col1, row2, col2)){
            counter++;
        }
        printBoard(board);
    }
    printf("Congratulations! You won in %d moves\n", counter);
}