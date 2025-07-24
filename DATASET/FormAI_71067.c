//FormAI DATASET v1.0 Category: Checkers Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define BOARD_SIZE 8

// Define the board and pieces
char board[BOARD_SIZE][BOARD_SIZE];
#define PLAYER_ONE 'O'
#define PLAYER_TWO 'X'
#define EMPTY_SPACE '-'

// Define async function to wait for user input
bool user_input_ready = false;
char user_input = '-';
void wait_for_input() {
    while (!user_input_ready) { usleep(100); }
    user_input_ready = false;
}

// Define async function to get user input
void get_user_input() {
    char input = '-';
    while (input != 'q') {
        scanf("%c", &input);
        if (input != '\n') {
            user_input = input;
            user_input_ready = true;
        }
    }
}

// Define function to print the board
void print_board() {
    printf("\n  1 2 3 4 5 6 7 8\n");
    printf(" +-+-+-+-+-+-+-+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("%d\n", i+1);
        printf(" +-+-+-+-+-+-+-+\n");
    }
    printf("  1 2 3 4 5 6 7 8\n\n");
}

// Define function to place a piece
bool place_piece(char player, int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    if (board[row][col] != EMPTY_SPACE) {
        return false;
    }
    board[row][col] = player;
    return true;
}

// Define function to remove a piece
void remove_piece(int row, int col) {
    board[row][col] = EMPTY_SPACE;
}

// Define function to check if a move is valid
bool valid_move(char player, int row, int col) {
    if (!place_piece(player, row, col)) {
        return false;
    }
    bool is_valid = false;
    if (row > 1 && col > 1) {
        is_valid |= (board[row-1][col-1] == player && board[row-2][col-2] == EMPTY_SPACE);
    }
    if (row > 1 && col < BOARD_SIZE-2) {
        is_valid |= (board[row-1][col+1] == player && board[row-2][col+2] == EMPTY_SPACE);
    }
    if (row < BOARD_SIZE-2 && col > 1) {
        is_valid |= (board[row+1][col-1] == player && board[row+2][col-2] == EMPTY_SPACE);
    }
    if (row < BOARD_SIZE-2 && col < BOARD_SIZE-2) {
        is_valid |= (board[row+1][col+1] == player && board[row+2][col+2] == EMPTY_SPACE);
    }
    remove_piece(row, col);
    return is_valid;
}

// Define function to get move from user
bool get_move(char player, int *row, int *col) {
    printf("%c's turn. Enter move (e.g. '3b'): ", player);
    wait_for_input();
    if (user_input == 'q') {
        return false;
    }
    *row = (int)(user_input - '1');
    wait_for_input();
    *col = (int)(user_input - 'a');
    if (*row < 0 || *row >= BOARD_SIZE || *col < 0 || *col >= BOARD_SIZE) {
        printf("Invalid move\n");
        return get_move(player, row, col);
    }
    if (!valid_move(player, *row, *col)) {
        printf("Invalid move\n");
        return get_move(player, row, col);
    }
    return true;
}

// Define function to check if game is over
bool game_over() {
    bool player_one_has_move = false;
    bool player_two_has_move = false;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == PLAYER_ONE) {
                player_one_has_move |= valid_move(PLAYER_ONE, i, j);
            }
            if (board[i][j] == PLAYER_TWO) {
                player_two_has_move |= valid_move(PLAYER_TWO, i, j);
            }
        }
    }
    return !player_one_has_move || !player_two_has_move;
}

// Define function to get the other player
char other_player(char player) {
    return (player == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
}

// Define function to execute a turn
bool execute_turn(char player) {
    int row, col;
    if (!get_move(player, &row, &col)) {
        return false;
    }
    place_piece(player, row, col);
    if (row == 0 && player == PLAYER_TWO) {
        board[row][col] = 'K';
    }
    if (row == BOARD_SIZE-1 && player == PLAYER_ONE) {
        board[row][col] = 'K';
    }
    if (row > 1 && col > 1) {
        if (board[row-1][col-1] == other_player(player) && board[row-2][col-2] == EMPTY_SPACE) {
            remove_piece(row-1, col-1);
        }
    }
    if (row > 1 && col < BOARD_SIZE-2) {
        if (board[row-1][col+1] == other_player(player) && board[row-2][col+2] == EMPTY_SPACE) {
            remove_piece(row-1, col+1);
        }
    }
    if (row < BOARD_SIZE-2 && col > 1) {
        if (board[row+1][col-1] == other_player(player) && board[row+2][col-2] == EMPTY_SPACE) {
            remove_piece(row+1, col-1);
        }
    }
    if (row < BOARD_SIZE-2 && col < BOARD_SIZE-2) {
        if (board[row+1][col+1] == other_player(player) && board[row+2][col+2] == EMPTY_SPACE) {
            remove_piece(row+1, col+1);
        }
    }
    return true;
}

// Define function to initialize the board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i+j) % 2 == 0) {
                board[i][j] = EMPTY_SPACE;
            } else {
                if (i < 3) {
                    board[i][j] = PLAYER_ONE;
                } else if (i > 4) {
                    board[i][j] = PLAYER_TWO;
                } else {
                    board[i][j] = EMPTY_SPACE;
                }
            }
        }
    }
}

// Define function to play the game
void play_game() {
    char current_player = PLAYER_ONE;
    while (!game_over()) {
        print_board();
        if (!execute_turn(current_player)) {
            break;
        }
        current_player = other_player(current_player);
    }
    print_board();
    printf("%c wins!\n", other_player(current_player));
}

// Define main function
int main() {
    // Initialize board
    initialize_board();

    // Start async input thread
    pthread_t input_thread;
    pthread_create(&input_thread, NULL, get_user_input, NULL);

    // Play the game
    play_game();

    return 0;
}