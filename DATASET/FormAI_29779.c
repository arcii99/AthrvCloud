//FormAI DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_PLAYERS 2

// Function to print the game board
void print_board(char board[][BOARD_SIZE]) {
    printf("\nCurrent Board State:\n\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a player has won
int check_winner(char board[][BOARD_SIZE], char player) {
    int count;
    // Check Rows
    for(int i=0; i<BOARD_SIZE; i++) {
        count = 0;
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                count++;
            }
            if(count == BOARD_SIZE) {
                return 1;
            }
        }
    }
    // Check Columns
    for(int i=0; i<BOARD_SIZE; i++) {
        count = 0;
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[j][i] == player) {
                count++;
            }
            if(count == BOARD_SIZE) {
                return 1;
            }
        }
    }
    // Check Diagonals
    count = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[i][i] == player) {
            count++;
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
    }
    count = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[i][BOARD_SIZE-i-1] == player) {
            count++;
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
    }
    return 0;
}

int main() {
    printf("*** WELCOME TO THE C TABLE GAME! ***\n\n");
    printf("Players take turns entering a row and column number (e.g. 0,0)\n");
    printf("The first player to get a full row, column, or diagonal of their symbol wins!\n\n");

    // Set up game board
    char game_board[BOARD_SIZE][BOARD_SIZE];
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            game_board[i][j] = '-';
        }
    }

    // Choose starting player randomly
    srand(time(0));
    int current_player = rand() % NUM_PLAYERS;
    char player_symbol[NUM_PLAYERS];
    player_symbol[0] = 'X';
    player_symbol[1] = 'O';

    // Print starting board
    print_board(game_board);

    // Start game loop
    int num_turns = 0;
    while(num_turns < BOARD_SIZE*BOARD_SIZE) {
        printf("It's Player %d's turn. Enter row and column numbers (0-9): ", current_player+1);
        int row, col;
        scanf("%d,%d", &row, &col);
        getchar();
        if(row < 0 || row > BOARD_SIZE-1 || col < 0 || col > BOARD_SIZE-1) {
            printf("Invalid input! Try again.\n\n");
            continue;
        }
        if(game_board[row][col] != '-') {
            printf("That space is already taken! Try again.\n\n");
            continue;
        }
        game_board[row][col] = player_symbol[current_player];
        print_board(game_board);
        if(check_winner(game_board, player_symbol[current_player])) {
            printf("Congratulations Player %d! You win!\n", current_player+1);
            return 0;
        }
        num_turns++;
        current_player = (current_player + 1) % NUM_PLAYERS;
    }

    printf("Game over. It's a tie!\n");
    return 0;
}