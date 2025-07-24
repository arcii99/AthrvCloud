//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 3 // size of the game board
#define MAX_NAME_LENGTH 20 // maximum length for player name input

void display_board(char board[BOARD_SIZE][BOARD_SIZE]);
int get_move(char board[BOARD_SIZE][BOARD_SIZE], char player, int* row, int* col);
int check_win(char board[BOARD_SIZE][BOARD_SIZE]);
void clear_screen();

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char player1[MAX_NAME_LENGTH], player2[MAX_NAME_LENGTH];
    char current_player;
    int row, col, winner, move_count;
    
    // Initialize the game board
    for(int i=0; i<BOARD_SIZE;i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    
    // Prompt for player names
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1, please enter your name: ");
    fgets(player1, MAX_NAME_LENGTH, stdin);
    player1[strcspn(player1, "\n")] = 0; // remove newline character
    printf("Player 2, please enter your name: ");
    fgets(player2, MAX_NAME_LENGTH, stdin);
    player2[strcspn(player2, "\n")] = 0; // remove newline character
    
    // Choose random starting player
    srand(time(NULL));
    if(rand()%2 == 0) {
        current_player = 'X';
        printf("%s goes first!\n", player1);
    } else {
        current_player = 'O';
        printf("%s goes first!\n", player2);
    }
    
    // Game loop
    winner = 0;
    move_count = 0;
    while(!winner && move_count < BOARD_SIZE*BOARD_SIZE) {
        display_board(board);
        printf("%s's turn:\n", current_player == 'X' ? player1 : player2);
        if(get_move(board, current_player, &row, &col)) {
            board[row][col] = current_player;
            winner = check_win(board);
            current_player = current_player == 'X' ? 'O' : 'X'; // switch players
            move_count++;
        } else {
            printf("That move is invalid. Please try again.\n");
        }
    }
    
    // Display final game state
    display_board(board);
    if(winner) {
        printf("%s wins!! Congratulations!\n", winner == 'X' ? player1 : player2);
    } else {
        printf("It's a tie. Better luck next time!\n");
    }
    
    return 0;
}

void display_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    clear_screen();
    printf("  1 2 3\n");
    printf(" -------\n");
    for(int i=0; i<BOARD_SIZE;i++) {
        printf("%d|", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n -------\n");
    }
}

int get_move(char board[BOARD_SIZE][BOARD_SIZE], char player, int* row, int* col) {
    char input[MAX_NAME_LENGTH]; // temporary buffer for player input
    printf("Enter your move (row column): ");
    fgets(input, MAX_NAME_LENGTH, stdin);
    *row = input[0] - '1'; // convert to integer row and column
    *col = input[2] - '1';
    if((*row < 0) || (*row >= BOARD_SIZE) || (*col < 0) || (*col >= BOARD_SIZE)) {
        return 0; // invalid move
    }
    if(board[*row][*col] != ' ') {
        return 0; // move already taken
    }
    return 1;
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for(int i=0; i<BOARD_SIZE;i++) {
        if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != ' ')) {
            return board[i][0];
        }
    }
    // Check columns
    for(int j=0; j<BOARD_SIZE;j++) {
        if((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[0][j] != ' ')) {
            return board[0][j];
        }
    }
    // Check diagonals
    if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != ' ')) {
        return board[0][0];
    }
    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] != ' ')) {
        return board[0][2];
    }
    return 0; // no winner yet
}

void clear_screen() {
    printf("\033[2J\033[1;1H"); // ANSI escape code to clear the screen
}