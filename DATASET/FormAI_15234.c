//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the board
void printBoard(char board[]) {
    printf("\n");
    printf("\t %c | %c | %c \n", board[0], board[1], board[2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[3], board[4], board[5]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

// Function to check if player has won
int checkWinner(char board[], char player) {
    if ((board[0] == player && board[1] == player && board[2] == player) || 
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return 1;
    }
    return 0;
}

// Function to get user input
int getUserInput(char board[], char player) {
    int position;
    printf("Player %c, enter a number (1-9): ", player);
    scanf("%d", &position);
    while (position < 1 || position > 9 || board[position-1] != ' ') {
        printf("Invalid input. Please try again.\n");
        printf("Player %c, enter a number (1-9): ", player);
        scanf("%d", &position);
    }
    return position;
}

// Function to get computer input
int getComputerInput(char board[]) {
    int position;
    do {
        position = rand() % 9;
    } while (board[position] != ' ');
    return position + 1;
}

int main() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1 = 'X', player2 = 'O';
    char current_player;
    int position;
    int winner = 0;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Choose player to start
    if (rand() % 2 == 0) {
        printf("Player X will start.\n");
        current_player = player1;
    } else {
        printf("Player O will start.\n");
        current_player = player2;
    }
    
    // Loop until there is a winner or the board is full
    while (!winner) {
        if (current_player == player1) {
            position = getUserInput(board, player1);
        } else {
            position = getComputerInput(board);
            printf("Computer chose position %d.\n", position);
        }
        board[position-1] = current_player;
        printBoard(board);
        winner = checkWinner(board, current_player);
        if (winner) {
            printf("Player %c wins!\n", current_player);
        } else if (board[0] != ' ' && board[1] != ' ' && board[2] != ' ' &&
                   board[3] != ' ' && board[4] != ' ' && board[5] != ' ' &&
                   board[6] != ' ' && board[7] != ' ' && board[8] != ' ') {
            printf("The game is a tie.\n");
            break;
        }
        if (current_player == player1) {
            current_player = player2;
        } else {
            current_player = player1;
        }
    }
    return 0;
}