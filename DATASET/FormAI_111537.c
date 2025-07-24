//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY_BOX '-'
#define USER_MARKER 'X'
#define AI_MARKER 'O'

// Function to display the tic tac toe board
void display_board(char board[][3]) {
    printf("\nTic Tac Toe Board:\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Function to check if a row or column or diagonal has same markers
int check_line(char marker, char line[]) {
    return (line[0] == marker && line[1] == marker && line[2] == marker);
}

// Function to check if any player has won the game or not
int check_win(char board[][3]) {
    char line[3];
    // Rows
    for (int i = 0; i < 3; i++) {
        line[0] = board[i][0];
        line[1] = board[i][1];
        line[2] = board[i][2];
        if (check_line(USER_MARKER, line)) {
            return -1;
        }
        else if (check_line(AI_MARKER, line)) {
            return 1;
        }
    }

    // Columns
    for (int j = 0; j < 3; j++) {
        line[0] = board[0][j];
        line[1] = board[1][j];
        line[2] = board[2][j];
        if (check_line(USER_MARKER, line)) {
            return -1;
        }
        else if (check_line(AI_MARKER, line)) {
            return 1;
        }
    }

    // Diagonals
    line[0] = board[0][0];
    line[1] = board[1][1];
    line[2] = board[2][2];
    if (check_line(USER_MARKER, line)) {
        return -1;
    }
    else if (check_line(AI_MARKER, line)) {
        return 1;
    }

    line[0] = board[0][2];
    line[1] = board[1][1];
    line[2] = board[2][0];
    if (check_line(USER_MARKER, line)) {
        return -1;
    }
    else if (check_line(AI_MARKER, line)) {
        return 1;
    }

    return 0; // If no player has won yet
}

// Function to check if the board is full or not
int is_board_full(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY_BOX) {
                return 0; // Board is not full yet
            }
        }
    }
    return 1; // Board is full
}

// Function to get the user's move
void get_user_move(char board[][3], int *row, int *col) {
    printf("Enter the row number (1-3): ");
    scanf("%d", row);
    printf("Enter the column number (1-3): ");
    scanf("%d", col);
    *row -= 1; // Convert to 0-based indexing
    *col -= 1;
    if (board[*row][*col] != EMPTY_BOX) {
        printf("Box is already occupied!\n");
        get_user_move(board, row, col);
    }
}

// Function to get a random AI move
void get_ai_move(char board[][3], int *row, int *col) {
    srand(time(0));
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while (board[*row][*col] != EMPTY_BOX);
}

// Function to get the best AI move
void get_best_ai_move(char board[][3], int *row, int *col) {
    srand(time(0));
    // First, check if there is any winning move available
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == AI_MARKER && board[i][1] == AI_MARKER && board[i][2] == EMPTY_BOX) {
            *row = i;
            *col = 2;
            return;
        }
        else if (board[i][1] == AI_MARKER && board[i][2] == AI_MARKER && board[i][0] == EMPTY_BOX) {
            *row = i;
            *col = 0;
            return;
        }
        else if (board[i][0] == AI_MARKER && board[i][2] == AI_MARKER && board[i][1] == EMPTY_BOX) {
            *row = i;
            *col = 1;
            return;
        }
    }

    // Columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == AI_MARKER && board[1][j] == AI_MARKER && board[2][j] == EMPTY_BOX) {
            *row = 2;
            *col = j;
            return;
        }
        else if (board[1][j] == AI_MARKER && board[2][j] == AI_MARKER && board[0][j] == EMPTY_BOX) {
            *row = 0;
            *col = j;
            return;
        }
        else if (board[0][j] == AI_MARKER && board[2][j] == AI_MARKER && board[1][j] == EMPTY_BOX) {
            *row = 1;
            *col = j;
            return;
        }
    }

    // Diagonal 1
    if (board[0][0] == AI_MARKER && board[1][1] == AI_MARKER && board[2][2] == EMPTY_BOX) {
        *row = 2;
        *col = 2;
        return;
    }
    else if (board[1][1] == AI_MARKER && board[2][2] == AI_MARKER && board[0][0] == EMPTY_BOX) {
        *row = 0;
        *col = 0;
        return;
    }
    else if (board[0][0] == AI_MARKER && board[2][2] == AI_MARKER && board[1][1] == EMPTY_BOX) {
        *row = 1;
        *col = 1;
        return;
    }

    // Diagonal 2
    if (board[0][2] == AI_MARKER && board[1][1] == AI_MARKER && board[2][0] == EMPTY_BOX) {
        *row = 2;
        *col = 0;
        return;
    }
    else if (board[1][1] == AI_MARKER && board[2][0] == AI_MARKER && board[0][2] == EMPTY_BOX) {
        *row = 0;
        *col = 2;
        return;
    }
    else if (board[0][2] == AI_MARKER && board[2][0] == AI_MARKER && board[1][1] == EMPTY_BOX) {
        *row = 1;
        *col = 1;
        return;
    }

    // If there is no winning move, then select a random move
    get_ai_move(board, row, col);
}

// Function to play the game
void play() {
    char board[3][3];
    int row, col, turn, result;
    printf("Welcome to Tic Tac Toe\n");
    printf("You are playing as X.\n");
    printf("Enter the row and column numbers to place your marker (1-3).\n\n");
    // Initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY_BOX;
        }
    }
    display_board(board);
    // Choose who goes first randomly
    srand(time(0));
    turn = rand() % 2;
    while (1) {
        if (turn == 0) {
            printf("Your turn...\n");
            get_user_move(board, &row, &col);
            board[row][col] = USER_MARKER;
        }
        else {
            printf("Computer's turn...\n");
            printf("The computer is thinking...\n");
            get_best_ai_move(board, &row, &col);
            board[row][col] = AI_MARKER;
        }
        display_board(board);
        result = check_win(board);
        if (result == -1) {
            printf("Congratulations! You won the game.\n");
            break;
        }
        else if (result == 1) {
            printf("Sorry! The computer won the game.\n");
            break;
        }
        if (is_board_full(board)) {
            printf("The game is a tie.\n");
            break;
        }
        // Switch the turn
        turn = (turn + 1) % 2;
    }
}

int main() {
    char choice;
    do {
        play();
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("Thank you for playing!\n");
    return 0;
}