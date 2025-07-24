//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE]; // 3x3 game board
char human_player = 'X'; // human player is X
char computer_player = 'O'; // computer player is O

// function to print the current state of the board
void print_board() {
    printf("-------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// function to check if the game is over
bool game_over() {
    // check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    // check if board is full (tie)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// function to evaluate the current state of the board
int evaluate_board() {
    // check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == computer_player) {
                return 10;
            } else if (board[i][0] == human_player) {
                return -10;
            }
        }
    }
    // check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == computer_player) {
                return 10;
            } else if (board[0][j] == human_player) {
                return -10;
            }
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == computer_player) {
            return 10;
        } else if (board[0][0] == human_player) {
            return -10;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == computer_player) {
            return 10;
        } else if (board[0][2] == human_player) {
            return -10;
        }
    }
    // return 0 if board is not full (game not over)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 0; // game is a tie
}

// function to recursively find the best move using minimax algorithm with alpha-beta pruning
int minimax(int depth, bool is_maximizer, int alpha, int beta) {
    // evaluate board if game is over or maximum depth is reached
    if (game_over() || depth == 0) {
        return evaluate_board();
    }
    // maximize if it is the computer's turn, minimize if it is the human's turn
    if (is_maximizer) {
        int best_score = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = computer_player;
                    int score = minimax(depth-1, false, alpha, beta);
                    board[i][j] = ' ';
                    best_score = (score > best_score) ? score : best_score;
                    alpha = (best_score > alpha) ? best_score : alpha;
                    if (beta <= alpha) {
                        break; // beta cut-off
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = human_player;
                    int score = minimax(depth-1, true, alpha, beta);
                    board[i][j] = ' ';
                    best_score = (score < best_score) ? score : best_score;
                    beta = (best_score < beta) ? best_score : beta;
                    if (beta <= alpha) {
                        break; // alpha cut-off
                    }
                }
            }
        }
        return best_score;
    }
}

// function to find the best move using minimax algorithm with alpha-beta pruning
int find_best_move() {
    int best_score = -1000;
    int best_i = -1;
    int best_j = -1;
    int alpha = -1000;
    int beta = 1000;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = computer_player;
                int score = minimax(5, false, alpha, beta); // search depth of 5
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    best_i = i;
                    best_j = j;
                }
                alpha = (best_score > alpha) ? best_score : alpha;
                if (beta <= alpha) {
                    break; // beta cut-off
                }
            }
        }
    }
    return best_i * 3 + best_j + 1; // convert i, j to cell number (1-9)
}

// function to get human player's move
int get_human_move() {
    int cell;
    do {
        printf("Enter a cell number (1-9) to place %c: ", human_player);
        scanf("%d", &cell);
    } while (cell < 1 || cell > 9 || board[(cell-1)/3][(cell-1)%3] != ' ');
    return cell;
}

// function to play the game
void play_game() {
    printf("Tic Tac Toe\n");
    printf("Human: %c, Computer: %c\n", human_player, computer_player);
    printf("Enter a number (1-9) to place your mark.\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    print_board();
    while (!game_over()) {
        int cell;
        // human move
        cell = get_human_move();
        board[(cell-1)/3][(cell-1)%3] = human_player;
        print_board();
        if (game_over()) {
            break;
        }
        // computer move
        printf("Computer plays...\n");
        cell = find_best_move();
        board[(cell-1)/3][(cell-1)%3] = computer_player;
        print_board();
    }
    int score = evaluate_board();
    if (score == 10) {
        printf("Computer wins!\n");
    } else if (score == -10) {
        printf("Human wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    play_game();
    return 0;
}