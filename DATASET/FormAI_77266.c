//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to initialize the bingo board
void init_board(int board[ROWS][COLS]) {
    int num;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Each cell is assigned a random number between 1 and 75
            do {
                num = 1 + rand() % 75;
            } while (num_in_board(board, num));
            board[i][j] = num;
        }
    }
}

// Function to check if the number is already present in the board
int num_in_board(int board[ROWS][COLS], int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == num) {
                return 1; // Number exists in board
            }
        }
    }
    return 0; // Number does not exist in board
}

// Function to print the bingo board
void print_board(int board[ROWS][COLS], int selected[75]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf(" ___ ___ ___ ___ ___\n");
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == selected[board[i][j]-1]) {
                printf("|XX |");
            } else {
                printf("|%2d |", board[i][j]);
            }
        }
        printf("\n");
    }
    printf(" ___ ___ ___ ___ ___\n");
}

// Function to check if the player won
int check_win(int board[ROWS][COLS], int selected[75]) {
    int row, col, diag1 = 0, diag2 = 0;
    // Check for diagonal wins
    for (int i = 0; i < ROWS; i++) {
        if (board[i][i] == selected[board[i][i]-1]) {
            diag1++;
        }
        int j = COLS - 1 - i;
        if (board[i][j] == selected[board[i][j]-1]) {
            diag2++;
        }
    }
    if (diag1 == ROWS || diag2 == ROWS) {
        return 1; // Diagonal win
    }
    // Check for row and column wins
    for (int i = 0; i < ROWS; i++) {
        row = col = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == selected[board[i][j]-1]) {
                row++;
            }
            if (board[j][i] == selected[board[j][i]-1]) {
                col++;
            }
        }
        if (row == ROWS || col == COLS) {
            return 1; // Row or column win
        }
    }
    return 0; // No win yet
}

// Main function
int main() {
    srand(time(NULL)); // Used for random number generation
    int board[ROWS][COLS], selected[75] = { 0 }, count = 0, num;
    char ans;
    init_board(board);
    do {
        system("clear||cls");
        printf("\nSelected Numbers: ");
        for (int i = 0; i < 75; i++) {
            if (selected[i]) {
                printf("%d ", i+1);
            }
        }
        print_board(board, selected);
        printf("\nEnter a number (1 to 75): ");
        scanf("%d", &num);
        if (num < 1 || num > 75) {
            printf("Invalid input!\n");
            continue;
        }
        if (selected[num-1]) {
            printf("%d has already been selected!\n", num);
            continue;
        }
        selected[num-1] = num;
        count++;
        if (check_win(board, selected)) {
            printf("\nBingo! You won in %d tries!\n", count);
            break;
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ans);
    } while (ans == 'y' || ans == 'Y');
    printf("\nThank you for playing!\n");
    return 0;
}