//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

char board[3][3]; // global board variable

// function to print the board
void print_board() {
    int i, j;
    printf("-------------\n");
    for (i = 0; i < 3; i++) {
        printf("|");
        for (j = 0; j < 3; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// function to check if the move is valid or not
int is_move_valid(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return 0;
    }
    if (board[row][col] != '-') {
        return 0;
    }
    return 1;
}

// function to check if the game is over or not
int is_game_over() {
    int i, j;

    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return 1;
        }
    }

    // check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return 1;
    }

    // Check if the game is draw
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }

    return 2;
}

// function to implement the minimax algorithm
int minimax(int depth, int is_max) {
    int i, j, score;
    int best_score = is_max ? -1000 : 1000;

    int result = is_game_over();
    if (result == 1) { // Max player has won
        return 10 - depth;
    } else if (result == 0) { // the game is still going on
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == '-') { // if cell is empty
                    if (is_max) {
                        board[i][j] = 'x'; // make a move
                        score = minimax(depth + 1, 0); // call the minimax function recursively for the other player
                        if (score > best_score) { // update the best score if needed
                            best_score = score;
                        }
                    } else {
                        board[i][j] = 'o';
                        score = minimax(depth + 1, 1);
                        if (score < best_score) {
                            best_score = score;
                        }
                    }
                    board[i][j] = '-'; // undo the move
                }
            }
        }
        return best_score;
    } else { // the game is over
        return -10 + depth;
    }
}

// function to get the best move for the AI
int get_best_move() {
    int i, j, score;
    int best_score = -1000;
    int best_row = -1;
    int best_col = -1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                board[i][j] = 'x';
                score = minimax(0, 0); // call minimax for the other player
                board[i][j] = '-';
                if (score > best_score) {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    return best_row * 3 + best_col;
}

// main function to run the game
int main() {
    int row, col, move;
    int is_max_turn = 1;

    // initialize the board
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }

    printf("Welcome to Tic Tac Toe!\n");

    while (1) {
        print_board();
        if (is_max_turn) {
            move = get_best_move();
            row = move / 3;
            col = move % 3;
            printf("The computer has made a move at (%d, %d)\n", row + 1, col + 1);
        } else {
            printf("Enter your move (row column): ");
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (!is_move_valid(row, col)) {
                printf("Invalid move. Try again.\n");
                continue;
            }
        }

        if (is_max_turn) {
            board[row][col] = 'x';
        } else {
            board[row][col] = 'o';
        }

        int result = is_game_over();
        if (result == 1) {
            printf("Game Over. ");
            if (is_max_turn) {
                printf("The computer has won!\n");
            } else {
                printf("You have won!\n");
            }
            print_board();
            break;
        } else if (result == 2) {
            printf("Game over. It's a draw.\n");
            print_board();
            break;
        }

        is_max_turn = !is_max_turn;
    }

    return 0;
}