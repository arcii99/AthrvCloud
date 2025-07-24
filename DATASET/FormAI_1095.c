//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// defines the size of the board
#define BOARD_SIZE 3

// defines the values for each player on the board
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// function declarations
int minimax(char board[][BOARD_SIZE], int depth, int isMaxPlayer);
void print_board(char board[][BOARD_SIZE]);
int check_winner(char board[][BOARD_SIZE]);
int is_full(char board[][BOARD_SIZE]);
void make_move(char board[][BOARD_SIZE], int player);
int get_random_number(int low, int high);
int get_computer_move(char board[][BOARD_SIZE]);
int get_player_move(char board[][BOARD_SIZE]);

// main function
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;
    int winner = 0;
    int tie = 0;

    // initialize the board to empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Welcome to Tic Tac Toe!\n");

    // loop until the game is won or tied
    while (winner == 0 && !is_full(board)) {
        print_board(board);

        // make the move for the current player
        if (player == 1) {
            make_move(board, player);
        } else {
            int move = get_computer_move(board);
            board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_2;
            printf("Computer makes move: %d,%d\n", move / BOARD_SIZE, move % BOARD_SIZE);
        }

        // check if the game is won or tied
        winner = check_winner(board);
        if (winner == 0 && is_full(board)) {
            tie = 1;
        }

        // switch to the next player
        player = (player == 1) ? 2 : 1;
    }

    // print the final board and result
    print_board(board);
    if (winner != 0) {
        printf("Player %d wins!\n", winner);
    } else {
        printf("Tie game!\n");
    }

    return 0;
}

// function to print the board
void print_board(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("-------------\n");
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
    }
    printf("-------------\n");
}

// function to check if the game is won
int check_winner(char board[][BOARD_SIZE]) {
    int i, j;

    // check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == 'X' ? 1 : 2;
        }
    }

    // check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i] == 'X' ? 1 : 2;
        }
    }

    // check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == 'X' ? 1 : 2;
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == 'X' ? 1 : 2;
    }

    return 0;
}

// function to check if the board is full
int is_full(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

// function to get a random number between low and high (inclusive)
int get_random_number(int low, int high) {
    srand(time(NULL));
    int range = high - low + 1;
    int random_number = rand() % range + low;
    return random_number;
}

// function to get the computer's next move
int get_computer_move(char board[][BOARD_SIZE]) {
    int best_move_value = -1000;
    int best_move = -1;

    // if the center is available take it
    if (board[1][1] == ' ') {
        return (1 * BOARD_SIZE) + 1;
    }

    // use minimax to find the best move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = PLAYER_2;
                int move_value = minimax(board, 0, 0);
                if (move_value > best_move_value) {
                    best_move_value = move_value;
                    best_move = (i * BOARD_SIZE) + j;
                }
                board[i][j] = ' ';
            }
        }
    }

    return best_move;
}

// function to get the player's next move
int get_player_move(char board[][BOARD_SIZE]) {
    int move = -1;
    do {
        printf("Enter a move (1-9): ");
        fflush(stdout);
        scanf("%d", &move);
    } while (move < 1 || move > 9 || board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] != ' ');
    return move - 1;
}

// function to make a move for the current player
void make_move(char board[][BOARD_SIZE], int player) {
    if (player == 1) {
        int move = get_player_move(board);
        board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_1;
    } else {
        int move = get_computer_move(board);
        board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_2;
        printf("Computer makes move: %d,%d\n", move / BOARD_SIZE, move % BOARD_SIZE);
    }
}

// function to calculate the minimax value for the given board
int minimax(char board[][BOARD_SIZE], int depth, int is_max_player) {
    int winner = check_winner(board);
    if (winner != 0 || is_full(board) || depth == 5) {
        if (winner == 2) {
            return 10 - depth;
        } else if (winner == 1) {
            return depth - 10;
        } else {
            return 0;
        }
    }

    int best_value = is_max_player ? -1000 : 1000;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = is_max_player ? PLAYER_2 : PLAYER_1;
                int move_value = minimax(board, depth + 1, !is_max_player);
                board[i][j] = ' ';
                if ((is_max_player && move_value > best_value) || (!is_max_player && move_value < best_value)) {
                    best_value = move_value;
                }
            }
        }
    }

    return best_value;
}