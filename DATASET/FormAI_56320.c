//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

// Initialize the board with empty spaces
void initialize() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the current board state
void display() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Check if a given row or column or diagonal is contain same player's mark
int check_line(char c1, char c2, char c3) {
    return ((c1 != ' ') && (c1 == c2) && (c2 == c3));
}

// Check if game is finished with a win or tie
char check_win() {
    int i;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (check_line(board[i][0], board[i][1], board[i][2])) {
            return board[i][0];
        }
    }

    // Check columns
    for (i = 0; i < 3; i++) {
        if (check_line(board[0][i], board[1][i], board[2][i])) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (check_line(board[0][0], board[1][1], board[2][2])) {
        return board[0][0];
    }
    if (check_line(board[0][2], board[1][1], board[2][0])) {
        return board[0][2];
    }

    // Check tie
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return '\0';
            }
        }
    }

    return ' ';
}

// Get a random integer within a given range
int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// This is where the magic happens. You can customize this function to improve the AI's performance
void ai_move() {
    int i, j;

    // First, check if there is a winning move for the AI
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                if (check_win() == 'O') {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Then, check if there is a blocking move for the player
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                if (check_win() == 'X') {
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Otherwise, make a random move
    int row, col;
    do {
        row = get_random(0, 2);
        col = get_random(0, 2);
    } while (board[row][col] != ' ');
    board[row][col] = 'O';
}

int main() {
    srand(time(NULL));
    initialize();
    display();

    while (1) {
        // Player's move
        int row, col;
        printf("Enter your move (row column): ");
        scanf("%d %d", &row, &col);
        if (board[row][col] != ' ') {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[row][col] = 'X';
        display();

        // Check if the game is finished
        char winner = check_win();
        if (winner != ' ') {
            if (winner == 'X') {
                printf("Congratulation! You won!\n");
            } else if (winner == 'O') {
                printf("Sorry, you lost...\n");
            } else {
                printf("It's a tie!\n");
            }
            break;
        }

        // AI's move
        printf("AI is thinking...\n");
        ai_move();
        display();

        // Check if the game is finished
        winner = check_win();
        if (winner != ' ') {
            if (winner == 'X') {
                printf("Congratulation! You won!\n");
            } else if (winner == 'O') {
                printf("Sorry, you lost...\n");
            } else {
                printf("It's a tie!\n");
            }
            break;
        }
    }

    return 0;
}