//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: visionary
#include <stdio.h>

enum { BLANK = 0, USER = 1, AI = 2};
enum { HUMAN_TURN = 0, AI_TURN, DRAW, USER_WIN, AI_WIN };
int board[3][3];

void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = BLANK;
        }
    }
}

void display_board() {
    printf("Current board state:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (board[i][j]) {
                case BLANK:
                    printf("  ");
                    break;
                case USER:
                    printf("X ");
                    break;
                case AI:
                    printf("O ");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}

int check_win(int player) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int get_winner() {
    if (check_win(USER)) {
        return USER_WIN;
    } else if (check_win(AI)) {
        return AI_WIN;
    } else {
        // check for draws
        int blank_spaces = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == BLANK) {
                    blank_spaces++;
                }
            }
        }
        if (blank_spaces == 0) {
            return DRAW;
        } else {
            // game still in progress
            return -1;
        }
    }
}

int minimax(int depth, int player) {
    int i, j, score;
    int best_score = (player == AI) ? -1000 : 1000;

    // base case: leaf node
    int winner = get_winner();
    if (winner == USER_WIN) {
        return -10 + depth;
    } else if (winner == AI_WIN) {
        return 10 - depth;
    } else if (winner == DRAW) {
        return 0;
    }

    // recurse on children
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == BLANK) {
                board[i][j] = player;
                score = minimax(depth + 1, (player == AI) ? USER : AI);
                if (player == AI) {
                    if (score > best_score) {
                        best_score = score;
                    }
                } else {
                    if (score < best_score) {
                        best_score = score;
                    }
                }
                board[i][j] = BLANK; // undo move
            }
        }
    }

    return best_score;
}

void get_ai_move(int *row, int *col) {
    int i, j, score;
    int best_score = -1000;

    // find the best move for AI using minimax
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == BLANK) {
                board[i][j] = AI;
                score = minimax(0, USER);
                if (score > best_score) {
                    best_score = score;
                    *row = i;
                    *col = j;
                }
                board[i][j] = BLANK; // undo move
            }
        }
    }
}

int main() {
    init_board();
    int turn = HUMAN_TURN;
    int row, col;
    int winner;

    printf("Welcome to Tic Tac Toe AI!\n");
    printf("You are playing 'X' and the AI is playing 'O'\n");
    printf("Enter your moves by typing the row and column number (starting at 1)\n");

    while (1) {
        display_board();

        if (turn == HUMAN_TURN) {
            printf("Your turn!\n");
            scanf("%d %d", &row, &col);
            row--; // convert to 0-based indexing
            col--;

            if (board[row][col] != BLANK) {
                printf("Sorry, that space is already taken. Please try again.\n");
                continue;
            }

            board[row][col] = USER;
            turn = AI_TURN;
        } else {
            printf("AI's turn...\n");
            get_ai_move(&row, &col);
            printf("AI chooses (%d,%d)\n", row+1, col+1);
            board[row][col] = AI;
            turn = HUMAN_TURN;
        }

        winner = get_winner();
        if (winner == USER_WIN) {
            printf("Congratulations, you win!\n");
            display_board();
            break;
        } else if (winner == AI_WIN) {
            printf("Sorry, you lose.\n");
            display_board();
            break;
        } else if (winner == DRAW) {
            printf("It's a draw!\n");
            display_board();
            break;
        }
    }

    return 0;
}