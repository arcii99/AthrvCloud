//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// constants for board size and maximum number of moves
#define BOARD_SIZE 3
#define MAX_MOVES 9

// constants for player marks
#define HUMAN_MARK 'X'
#define AI_MARK 'O'
#define EMPTY_CELL ' '

// function declarations
void init_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
int make_move(char board[][BOARD_SIZE], char mark, int move);
int get_human_move(char board[][BOARD_SIZE]);
int get_ai_move(char board[][BOARD_SIZE]);
int check_winner(char board[][BOARD_SIZE]);
int minmax(char board[][BOARD_SIZE], char mark, int depth, int alpha, int beta);
int evaluate_board(char board[][BOARD_SIZE], char mark);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int move, winner, turn = 0;

    srand(time(NULL));

    // initialize board
    init_board(board);

    // loop until game ends
    while (1) {
        // player's turn
        if (turn % 2 == 0) {
            move = get_human_move(board);
            make_move(board, HUMAN_MARK, move);
        }
        // AI's turn
        else {
            move = get_ai_move(board);
            make_move(board, AI_MARK, move);
        }

        // print board after move
        print_board(board);

        // check for winner
        winner = check_winner(board);
        if (winner != 0) {
            if (winner == 1) {
                printf("Tie game!\n");
            }
            else if (winner == 2) {
                printf("Human player wins!\n");
            }
            else {
                printf("AI player wins!\n");
            }
            break;
        }

        turn++;
        if (turn == MAX_MOVES) {
            printf("Tie game!\n");
            break;
        }
    }

    return 0;
}

// initializes the game board with empty cells
void init_board(char board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }
}

// prints the game board to the console
void print_board(char board[][BOARD_SIZE]) {
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
            if (j != BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i != BOARD_SIZE - 1) {
            printf("-+-+-\n");
        }
    }
    printf("\n");
}

// attempts to make a move on the game board, returns 1 if successful and 0 if not
int make_move(char board[][BOARD_SIZE], char mark, int move) {
    int row = move / BOARD_SIZE;
    int col = move % BOARD_SIZE;
    if (board[row][col] == EMPTY_CELL) {
        board[row][col] = mark;
        return 1;
    }
    return 0;
}

// gets the human player's next move
int get_human_move(char board[][BOARD_SIZE]) {
    int move;
    while (1) {
        printf("Enter your next move (0-8): ");
        scanf("%d", &move);
        if (move < 0 || move >= MAX_MOVES) {
            printf("Invalid move, please try again.\n");
        }
        else if (make_move(board, HUMAN_MARK, move)) {
            return move;
        }
        else {
            printf("That cell is already occupied, please try again.\n");
        }
    }
}

// gets the AI player's next move using the minimax algorithm
int get_ai_move(char board[][BOARD_SIZE]) {
    int move, i, j, score, max_score = -10000;
    int alpha = -10000, beta = 10000;
    int best_moves[MAX_MOVES];
    int num_best_moves = 0;

    // iterate through all possible moves and find the one with the highest score
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_CELL) {
                board[i][j] = AI_MARK;
                score = minmax(board, HUMAN_MARK, 0, alpha, beta);
                board[i][j] = EMPTY_CELL;
                if (score > max_score) {
                    num_best_moves = 0;
                    max_score = score;
                    best_moves[num_best_moves] = i * BOARD_SIZE + j;
                    num_best_moves++;
                }
                else if (score == max_score) {
                    best_moves[num_best_moves] = i * BOARD_SIZE + j;
                    num_best_moves++;
                }
            }
        }
    }

    // randomly choose one of the best moves
    move = best_moves[rand() % num_best_moves];

    return move;
}

// checks if there is a winner on the game board, returns 0 for no winner, 1 for tie game, 2 for human player win and 3 for AI player win
int check_winner(char board[][BOARD_SIZE]) {
    int i, j, num_marked;

    // check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        num_marked = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == HUMAN_MARK) {
                num_marked++;
            }
            else if (board[i][j] == AI_MARK) {
                num_marked--;
            }
        }
        if (num_marked == BOARD_SIZE) {
            return 2;
        }
        else if (num_marked == -BOARD_SIZE) {
            return 3;
        }
    }

    // check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        num_marked = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] == HUMAN_MARK) {
                num_marked++;
            }
            else if (board[i][j] == AI_MARK) {
                num_marked--;
            }
        }
        if (num_marked == BOARD_SIZE) {
            return 2;
        }
        else if (num_marked == -BOARD_SIZE) {
            return 3;
        }
    }

    // check diagonals
    num_marked = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] == HUMAN_MARK) {
            num_marked++;
        }
        else if (board[i][i] == AI_MARK) {
            num_marked--;
        }
    }
    if (num_marked == BOARD_SIZE) {
        return 2;
    }
    else if (num_marked == -BOARD_SIZE) {
        return 3;
    }

    num_marked = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE - i - 1] == HUMAN_MARK) {
            num_marked++;
        }
        else if (board[i][BOARD_SIZE - i - 1] == AI_MARK) {
            num_marked--;
        }
    }
    if (num_marked == BOARD_SIZE) {
        return 2;
    }
    else if (num_marked == -BOARD_SIZE) {
        return 3;
    }

    // check for tie game
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_CELL) {
                return 0;
            }
        }
    }

    return 1;
}

// implementation of the minimax algorithm with alpha-beta pruning
int minmax(char board[][BOARD_SIZE], char mark, int depth, int alpha, int beta) {
    int i, j, score;
    int best_score;
    int other_mark = (mark == HUMAN_MARK) ? AI_MARK : HUMAN_MARK;

    // base case for recursive evaluation
    if (depth == 4) {
        return evaluate_board(board, mark);
    }

    // maximize score if current mark is AI player
    if (mark == AI_MARK) {
        best_score = -10000;

        // iterate through all possible moves and recursively evaluate their scores
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == EMPTY_CELL) {
                    board[i][j] = AI_MARK;
                    score = minmax(board, other_mark, depth + 1, alpha, beta);
                    board[i][j] = EMPTY_CELL;
                    if (score > best_score) {
                        best_score = score;
                    }
                    if (best_score > alpha) {
                        alpha = best_score;
                    }
                    if (alpha >= beta) {
                        return best_score;
                    }
                }
            }
        }

        return best_score;
    }
    // minimize score if current mark is human player
    else {
        best_score = 10000;

        // iterate through all possible moves and recursively evaluate their scores
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == EMPTY_CELL) {
                    board[i][j] = HUMAN_MARK;
                    score = minmax(board, other_mark, depth + 1, alpha, beta);
                    board[i][j] = EMPTY_CELL;
                    if (score < best_score) {
                        best_score = score;
                    }
                    if (best_score < beta) {
                        beta = best_score;
                    }
                    if (beta <= alpha) {
                        return best_score;
                    }
                }
            }
        }

        return best_score;
    }
}

// evaluates the current state of the board and returns a score based on the number of potential wins for the given mark
int evaluate_board(char board[][BOARD_SIZE], char mark) {
    int i, j, num_potential_wins = 0;

    // check rows and columns for potential wins
    for (i = 0; i < BOARD_SIZE; i++) {
        int num_marked_row = 0, num_marked_col = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == mark) {
                num_marked_row++;
            }
            if (board[j][i] == mark) {
                num_marked_col++;
            }
        }
        if (num_marked_row + BOARD_SIZE - i <= 3) {
            num_potential_wins++;
        }
        if (num_marked_col + BOARD_SIZE - i <= 3) {
            num_potential_wins++;
        }
    }

    // check diagonals for potential wins
    int num_marked_diag1 = 0, num_marked_diag2 = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] == mark) {
            num_marked_diag1++;
        }
        if (board[i][BOARD_SIZE - i - 1] == mark) {
            num_marked_diag2++;
        }
    }
    if (num_marked_diag1 + BOARD_SIZE <= 3) {
        num_potential_wins++;
    }
    if (num_marked_diag2 + BOARD_SIZE <= 3) {
        num_potential_wins++;
    }

    return num_potential_wins;
}