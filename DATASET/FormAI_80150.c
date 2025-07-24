//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// The size of the game board
#define BOARD_SIZE 3

// Define the different player options
#define HUMAN_PLAYER 'X'
#define AI_PLAYER 'O'

// Define the different game states
#define RUNNING 0
#define DRAW 1
#define HUMAN_WIN 2
#define AI_WIN 3

// Function declarations
void display_board(char board[BOARD_SIZE][BOARD_SIZE]);
char get_winner(char board[BOARD_SIZE][BOARD_SIZE]);
char get_move(char board[BOARD_SIZE][BOARD_SIZE], char player);
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, int is_maximizer);
int get_best_move(char board[BOARD_SIZE][BOARD_SIZE]);

// The main game loop
int main(void) {
    // Initialize the game board
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // Define the current game state
    int game_state = RUNNING;

    // Define the current player
    char current_player = HUMAN_PLAYER;

    // Define the move coordinates
    int x, y;

    // The main game loop
    while (game_state == RUNNING) {
        // Display the game board
        display_board(board);

        // Get the current player's move
        if (current_player == HUMAN_PLAYER) {
            printf("Enter your move (row column): ");
            scanf("%d %d", &x, &y);
            x--;
            y--;
        } else {
            printf("AI is thinking...\n");
            int best_move = get_best_move(board);
            x = best_move / BOARD_SIZE;
            y = best_move % BOARD_SIZE;
        }

        // Check if the move is valid
        if (board[x][y] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Update the game board
        board[x][y] = current_player;

        // Check if a player has won
        char winner = get_winner(board);
        if (winner != ' ') {
            if (winner == HUMAN_PLAYER) {
                game_state = HUMAN_WIN;
            } else {
                game_state = AI_WIN;
            }
        } else {
            // Check if the game is a draw
            int i, j, count = 0;
            for (i = 0; i < BOARD_SIZE; i++) {
                for (j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == ' ') {
                        count++;
                    }
                }
            }
            if (count == 0) {
                game_state = DRAW;
            } else {
                current_player = (current_player == HUMAN_PLAYER) ? AI_PLAYER : HUMAN_PLAYER;
            }
        }
    }

    // Display the final game state
    display_board(board);
    if (game_state == DRAW) {
        printf("The game is a draw!\n");
    } else if (game_state == HUMAN_WIN) {
        printf("You win!\n");
    } else {
        printf("The AI wins!\n");
    }
    return 0;
}

// Display the game board
void display_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("-----\n");
        }
    }
}

// Get the winner of the game (if any)
char get_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i;
    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // If no winner, return an empty char
    return ' ';
}

// Get a move from the player or the AI
char get_move(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    if (player == HUMAN_PLAYER) {
        printf("Enter your move (row column): ");
        int x, y;
        scanf("%d %d", &x, &y);
        return board[x - 1][y - 1];
    } else {
        printf("AI is thinking...\n");
        return get_best_move(board);
    }
}

// The minimax algorithm for the AI's move selection
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, int is_maximizer) {
    // Check if the game is over (base case)
    char winner = get_winner(board);
    if (winner == AI_PLAYER) {
        return 10 - depth;
    } else if (winner == HUMAN_PLAYER) {
        return depth - 10;
    } else if (winner == ' ' && depth == 9) {
        return 0;
    }

    // Recursive case
    int i, j;
    int best_score = (is_maximizer) ? -1000 : 1000;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = (is_maximizer) ? AI_PLAYER : HUMAN_PLAYER;
                int score = minimax(board, depth + 1, !is_maximizer);
                board[i][j] = ' ';
                if (is_maximizer) {
                    if (score > best_score) {
                        best_score = score;
                    }
                } else {
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
    }
    return best_score;
}

// Get the best move for the AI to make
int get_best_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    int best_move = -1;
    int best_score = -1000;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = AI_PLAYER;
                int score = minimax(board, 0, 0);
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    best_move = i * BOARD_SIZE + j;
                }
            }
        }
    }
    return best_move;
}