//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define BOARD_SIZE 3
#define AI_PLAYER 'X'
#define HUMAN_PLAYER 'O'

char board[BOARD_SIZE][BOARD_SIZE];
int ai_move[2];
bool game_over = false;
time_t start_time;

// Function to clear the console screen
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to print the current state of the board
void print_board() {
    clear_screen();
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
bool check_win(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check row
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        // Check column
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    } 
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool check_draw() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

// Function to get the human's move
void get_human_move() {
    int row, col; 
    do {
        printf("Enter row and column (1-3): ");
        scanf("%d%d", &row, &col);
        row--;
        col--;
    } while (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE || board[row][col] != '.');
    board[row][col] = HUMAN_PLAYER;
}

// Function to get the AI's move using the minimax algorithm
int minimax(int depth, bool is_maximizer, int alpha, int beta) {
    if (depth == 0 || game_over) {
        if (game_over && check_win(AI_PLAYER)) {
            return 10;
        } else if (game_over && check_win(HUMAN_PLAYER)) {
            return -10;
        } else {
            return 0;
        }
    }
    int best_score;
    if (is_maximizer) {
        best_score = -100;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == '.') {
                    board[i][j] = AI_PLAYER;
                    int score = minimax(depth - 1, !is_maximizer, alpha, beta);
                    board[i][j] = '.';
                    if (score > best_score) {
                        best_score = score;
                        if (depth == 5) {
                            ai_move[0] = i;
                            ai_move[1] = j;
                        }
                    }
                    alpha = (alpha > best_score) ? alpha : best_score;
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
    } else {
        best_score = 100;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == '.') {
                    board[i][j] = HUMAN_PLAYER;
                    int score = minimax(depth - 1, !is_maximizer, alpha, beta);
                    board[i][j] = '.';
                    if (score < best_score) {
                        best_score = score;
                    }
                    beta = (beta < best_score) ? beta : best_score;
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
    }
    return best_score;
}

// Function to get the AI's move asynchronously
void *get_ai_move() {
    int move_time = rand() % 3 + 2;
    sleep(move_time);
    minimax(5, true, -100, 100);
    board[ai_move[0]][ai_move[1]] = AI_PLAYER;
    printf("AI has made its move.\n");
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
    while (!game_over) {
        print_board();
        get_human_move();
        game_over = check_win(HUMAN_PLAYER) || check_draw();
        if (game_over) {
            break;
        }
        printf("AI is making its move...\n");
        pthread_t ai_thread;
        pthread_create(&ai_thread, NULL, get_ai_move, NULL);
        pthread_join(ai_thread, NULL);
        game_over = check_win(AI_PLAYER) || check_draw();
    }
    print_board();
    if (check_win(HUMAN_PLAYER)) {
        printf("Congratulations! You have won.\n");
    } else if (check_win(AI_PLAYER)) {
        printf("Sorry, you have lost.\n");
    } else {
        printf("It is a draw!\n");
    }
    return 0;
}