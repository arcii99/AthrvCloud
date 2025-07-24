//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: authentic
#include <stdio.h>

// declare functions
void print_board(char board[3][3]);
int check_win(char board[3][3], char symbol);
int minimax(char board[3][3], int depth, int is_max_player, char ai_symbol, char human_symbol);
int get_best_move(char board[3][3], char ai_symbol);
int is_valid_move(char board[3][3], int row, int col);

// main function
int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // initialize empty board
    char ai_symbol = 'O';
    char human_symbol = 'X';
    int turn = 0; // variable to keep track of whose turn it is
    int game_over = 0;
    
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are playing as X and the AI is playing as O.\n");
    printf("The board is laid out as follows:\n");
    printf("1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9\n");
    
    while (!game_over) {
        print_board(board);
        if (turn == 0) {
            // human turn
            int move;
            printf("Enter a number between 1 and 9 to make your move: ");
            scanf("%d", &move);
            int row = (move-1) / 3;
            int col = (move-1) % 3;
            if (is_valid_move(board, row, col)) {
                board[row][col] = human_symbol;
                if (check_win(board, human_symbol)) {
                    print_board(board);
                    printf("You win!\n");
                    game_over = 1;
                } else if (check_win(board, ai_symbol)) {
                    print_board(board);
                    printf("AI wins!\n");
                    game_over = 1;
                }
                turn = 1;
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else {
            // AI turn
            int best_move = get_best_move(board, ai_symbol);
            int row = best_move / 3;
            int col = best_move % 3;
            board[row][col] = ai_symbol;
            if (check_win(board, ai_symbol)) {
                print_board(board);
                printf("AI wins!\n");
                game_over = 1;
            } else if (check_win(board, human_symbol)) {
                print_board(board);
                printf("You win!\n");
                game_over = 1;
            }
            turn = 0;
        }
        // check for tie
        int i, j;
        int is_tie = 1;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    is_tie = 0;
                }
            }
        }
        if (is_tie) {
            print_board(board);
            printf("It's a tie!\n");
            game_over = 1;
        }
    }
    
    return 0;
}

// function to print the tic tac toe board
void print_board(char board[3][3]) {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// function to check if a player has won
int check_win(char board[3][3], char symbol) {
    int i, j;
    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }
    // check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    return 0;
}

// function that uses minimax algorithm to get the best next move for the AI
int minimax(char board[3][3], int depth, int is_max_player, char ai_symbol, char human_symbol) {
    int i, j, score;
    // base cases
    if (check_win(board, ai_symbol)) {
        return 10 - depth;
    }
    if (check_win(board, human_symbol)) {
        return depth - 10;
    }
    int is_tie = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                is_tie = 0;
            }
        }
    }
    if (is_tie) {
        return 0;
    }
    if (is_max_player) {
        // maximize score
        int best_score = -10000; 
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = ai_symbol;
                    score = minimax(board, depth + 1, 0, ai_symbol, human_symbol);
                    board[i][j] = ' ';
                    if (score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    } else {
        // minimize score
        int best_score = 10000;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = human_symbol;
                    score = minimax(board, depth + 1, 1, ai_symbol, human_symbol);
                    board[i][j] = ' ';
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

// function that uses minimax algorithm to get the best move for the AI
int get_best_move(char board[3][3], char ai_symbol) {
    int i, j, best_move, score, best_score = -10000;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai_symbol;
                score = minimax(board, 0, 0, ai_symbol, (ai_symbol == 'X' ? 'O' : 'X'));
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    best_move = i*3 + j;
                }
            }
        }
    }
    return best_move;
}

// function to check if a move is valid
int is_valid_move(char board[3][3], int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) { // check if coordinates are out of range
        return 0;
    }
    if (board[row][col] != ' ') { // check if spot is already taken
        return 0;
    }
    return 1;
}