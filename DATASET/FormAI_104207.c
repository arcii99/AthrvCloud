//FormAI DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

int player = 1;
char mark = 'X';
int choice;

char board[ROW][COL] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'}};

// Function declarations
void display_board();
void player_turn();
int check_winner();
int get_computer_move();
void computer_turn();

int main() {
    srand(time(NULL)); // Use current time as seed for random generator
    printf("Welcome to Tic-Tac-Toe\n\n");
    display_board();
    while(check_winner() == 0) { // Keep playing until someone wins or the board is full
        player_turn();
        if(check_winner() != 0) break;
        printf("\n");
        computer_turn();
        if(check_winner() != 0) break;
        printf("\n");
    }
    if (check_winner() == 1) {
        printf("\nPlayer %d wins!\n\n", player);
    }
    else if (check_winner() == 2) {
        printf("\nComputer wins!\n\n");
    }
    else {
        printf("\nIt's a tie!\n\n");
    }
    return 0;
}

// Display the Tic Tac Toe board
void display_board() {
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
}

// Prompt player to enter their move and check for validity
void player_turn() {
    printf("Player %d, enter your move (1-9): ", player);
    scanf("%d", &choice);

    // Convert choice to row and column indices
    int row = (choice - 1) / ROW;
    int col = (choice - 1) % COL;

    // Check if the move is valid
    if (choice < 1 || choice > 9) {
        printf("Invalid move, please choose a number from 1 to 9.\n");
        player_turn();
    }
    else if (board[row][col] == 'X' || board[row][col] == 'O') {
        printf("That square is already taken, choose another one.\n");
        player_turn();
    }
    else {
        board[row][col] = mark;
        display_board();
        if (check_winner() == 1) {
            printf("Player %d wins!\n", player);
            exit(0);
        }
        else if (check_winner() == 3) { // Board is full
            printf("It's a tie!\n");
            exit(0);
        }
        else {
            player = 2; // Switch to computer's turn
            mark = 'O';
        }
    }
}

// Check if someone has won or if the board is full
int check_winner() {
    // Check rows for a win
    for (int row = 0; row < ROW; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == 'X') {
                return 1;
            }
            else if (board[row][0] == 'O') {
                return 2;
            }
        }
    }

    // Check columns for a win
    for (int col = 0; col < COL; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == 'X') {
                return 1;
            }
            else if (board[0][col] == 'O') {
                return 2;
            }
        }
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            return 1;
        }
        else if (board[0][0] == 'O') {
            return 2;
        }
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        if (board[2][0] == 'X') {
            return 1;
        }
        else if (board[2][0] == 'O') {
            return 2;
        }
    }

    // Check if board is full
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // Board not full yet
            }
        }
    }
    return 3; // Board is full, it's a tie
}

// Generate random move for the computer
int get_computer_move() {
    int move = rand() % 9 + 1; // Choose random number between 1 and 9
    return move;
}

// Computer turns to make a move
void computer_turn() {
    printf("Computer's turn.\n");

    // Get a valid move for the computer
    int move = get_computer_move();
    int row = (move - 1) / ROW;
    int col = (move - 1) % COL;
    while (board[row][col] == 'X' || board[row][col] == 'O') {
        move = get_computer_move();
        row = (move - 1) / ROW;
        col = (move - 1) % COL;
    }

    board[row][col] = 'O';
    display_board();
    if (check_winner() == 2) {
        printf("Computer wins!\n");
        exit(0);
    }
    else if (check_winner() == 3) { // Board is full
        printf("It's a tie!\n");
        exit(0);
    }
    else {
        player = 1; // Switch to player's turn
        mark = 'X';
    }
}