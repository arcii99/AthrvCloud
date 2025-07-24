//FormAI DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_VALUE 20

void printBoard(int board[][COLS], int rows);
void shuffle(int board[][COLS], int rows);
int checkMatch(int board[][COLS], int r1, int c1, int r2, int c2);
int checkWin(int board[][COLS], int rows);

int main() {
    int board[ROWS][COLS] = {0};
    int choices[ROWS*COLS] = {0};
    int row1, col1, row2, col2;
    int turns = 0;
    int match;

    srand(time(NULL));

    // Fill board with random values
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            board[r][c] = rand() % MAX_VALUE + 1;
        }
    }

    shuffle(board, ROWS);
    printBoard(board, ROWS);

    while(checkWin(board, ROWS) != ROWS*COLS / 2) {
        printf("Turn %d\n", turns + 1);
        printf("Enter first card (row column): ");
        scanf("%d %d", &row1, &col1);
        printf("Enter second card (row column): ");
        scanf("%d %d", &row2, &col2);

        // Check if input is valid 
        if(row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLS ||
           row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Check if cards are already matched
        if(board[row1][col1] == 0 || board[row2][col2] == 0) {
            printf("Cards already matched. Try again.\n");
            continue;
        }

        match = checkMatch(board, row1, col1, row2, col2);
        if(match) {
            printf("Match found!\n");
        } else {
            printf("No match found.\n");
        }

        // Update board and print 
        printBoard(board, ROWS);

        turns++;
    }

    printf("Congrats! You won in %d turns.\n", turns);
    return 0;
}

void printBoard(int board[][COLS], int rows) {
    printf("\n\n");
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < COLS; c++) {
            if(board[r][c] == 0) {
                printf("X ");
            } else {
                printf("%d ", board[r][c]);
            }
        }
        printf("\n");
    }
}

void shuffle(int board[][COLS], int rows) {
    int choices[ROWS*COLS] = {0};
    int count = 0;

    // Add all non-zero values to choices array
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < COLS; c++) {
            if(board[r][c] != 0) {
                choices[count] = board[r][c];
                count++;
            }
        }
    }

    // Shuffle choices array
    for(int i = 0; i < count; i++) {
        int temp = choices[i];
        int randomIndex = rand() % count;

        choices[i] = choices[randomIndex];
        choices[randomIndex] = temp;
    }

    // Update board with shuffled values
    count = 0;
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < COLS; c++) {
            if(board[r][c] != 0) {
                board[r][c] = choices[count];
                count++;
            }
        }
    }
}

int checkMatch(int board[][COLS], int r1, int c1, int r2, int c2) {
    // Check if values match
    if(board[r1][c1] == board[r2][c2]) {
        board[r1][c1] = 0;
        board[r2][c2] = 0;
        return 1;
    } else {
        return 0;
    }
}

int checkWin(int board[][COLS], int rows) {
    int count = 0;
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < COLS; c++) {
            if(board[r][c] == 0) {
                count++;
            }
        }
    }

    return count;
}