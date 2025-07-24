//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

// Function to display the game board
void display_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("--------------------------------\n");
    printf("          C TERMINAL GAME       \n");
    printf("--------------------------------\n");
    printf("  | 0 1 2 3 4 5 6 7 8 9\n");
    printf("--+--------------------\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%2d| ", i);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to randomly place the mines on the board
void set_mines(char board[BOARD_SIZE][BOARD_SIZE], int num_mines) {
    int count = 0;
    while(count < num_mines) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if(board[x][y] == '.') {
            board[x][y] = '*';
            count++;
        }
    }
}

// Function to update the game board after user input
void update_board(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    if(board[x][y] == '*') {
        printf("Oops! You stepped on a mine. Game over!\n");
        exit(0);
    } else {
        int count = 0;
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                int x_new = x + i;
                int y_new = y + j;
                if(x_new >= 0 && x_new < BOARD_SIZE && y_new >= 0 && y_new < BOARD_SIZE) {
                    if(board[x_new][y_new] == '*') {
                        count++;
                    }
                }
            }
        }
        board[x][y] = count + '0';
    }
}

// Function to check if the game has been won
int check_win(char board[BOARD_SIZE][BOARD_SIZE], int num_mines) {
    int count = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] >= '0' && board[i][j] <= '9') {
                count++;
            }
        }
    }
    if(count == BOARD_SIZE * BOARD_SIZE - num_mines) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    char board[BOARD_SIZE][BOARD_SIZE];

    // Initialize the board with '.'
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }

    // Set the number of mines
    srand(time(NULL));
    int num_mines = BOARD_SIZE * BOARD_SIZE / 8;

    // Set the mines on the board
    set_mines(board, num_mines);

    // Display the initial board
    display_board(board);

    // Game loop
    while(1) {
        int x, y;
        printf("Enter the row and column indices (separated by a space) of the cell you want to explore: ");
        scanf("%d %d", &x, &y);
        if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            printf("Invalid input! Please enter valid indices.\n");
            continue;
        }
        if(board[x][y] >= '0' && board[x][y] <= '9') {
            printf("This cell has already been explored! Please enter another cell.\n");
            continue;
        }
        update_board(board, x, y);
        display_board(board);
        if(check_win(board, num_mines)) {
            printf("Congratulations! You have won the game!\n");
            break;
        }
    }

    return 0;
}