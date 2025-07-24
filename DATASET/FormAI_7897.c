//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdio.h>

// Function to display the game board
void display_board(char board[3][3]) {
    printf("\n      Tic Tac Toe\n");
    printf("   |   |\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("___|___|___\n");
    printf("   |   |\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("___|___|___\n");
    printf("   |   |\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("   |   |\n");
}

// Function to check if the game is won
int winning_game(char board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return board[i][0];
        }
    }
    for (i = 0; i < 3; i++) {
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return board[0][i];
        }
    }
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return board[0][0];
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        return board[0][2];
    }
    return ' ';
}

// Function to evaluate the optimal move for the AI player
int evaluate(char board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'O') {
                return 10;
            }
            else if (board[i][0] == 'X') {
                return -10;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'O') {
                return 10;
            }
            else if (board[0][i] == 'X') {
                return -10;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0]=='O') {
            return 10;
        }
        else if (board[0][0]=='X') {
            return -10;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'O') {
            return 10;
        }
        else if (board[0][2] == 'X') {
            return -10;
        }
    }
    return 0;
}

// Function to find the best move using the minimax algorithm
int minimax(char board[3][3], int depth, int isMax) {
    int score = evaluate(board);
    // If the AI player has won the game
    if (score == 10) {
        return score - depth;
    }
    // If the human player has won the game
    if (score == -10) {
        return score + depth;
    }
    // If there are no more moves left and the game is a draw
    if (score == 0 && depth == 9) {
        return 0;
    }
    int best_move;
    // If it is the AI player's turn
    if (isMax) {
        int i, j;
        int best_score = -100;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int current_score = minimax(board, depth + 1, !isMax);
                    if (current_score > best_score) {
                        best_score = current_score;
                        best_move = (3 * i) + j + 1;
                    }
                    board[i][j] = ' ';
                }
            }
        }
    }
    // If it is the human player's turn
    else {
        int i, j;
        int best_score = 100;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int current_score = minimax(board, depth + 1, !isMax);
                    if (current_score < best_score) {
                        best_score = current_score;
                        best_move = (3 * i) + j + 1;
                    }
                    board[i][j] = ' ';
                }
            }
        }
    }
    return best_move;
}

// The main function
int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    printf("Two households, both alike in dignity,\n");
    printf("In fair Verona, where we lay our scene,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n\n");
    printf("The game will pit thee against mine AI,\n");
    printf("A perfect foe, no human frailty there.\n");
    printf("If thou canst win, thou wilt surely defy,\n");
    printf("The art of war, and break the very air.\n\n");
    printf("Enter the number of the cell where you would like to place your 'X' (1-9):\n");
    int human_move;
    scanf("%d", &human_move);
    int i, j;
    board[(human_move - 1) / 3][(human_move - 1) % 3] = 'X';
    int turn = 1;
    while (winning_game(board) == ' ' && turn < 9) {
        display_board(board);
        if (turn % 2 == 1) {
            int ai_move = minimax(board, 0, 1);
            board[(ai_move - 1) / 3][(ai_move - 1) % 3] = 'O';
        }
        else {
            printf("Enter the number of the cell where you would like to place your 'X' (1-9):\n");
            scanf("%d", &human_move);
            board[(human_move - 1) / 3][(human_move - 1) % 3] = 'X';
        }
        turn++;
    }
    display_board(board);
    if (winning_game(board) == 'X') {
        printf("O happy dagger! This is thy sheath;\n");
        printf("There rust, and let me die.\n");
    }
    else if (winning_game(board) == 'O') {
        printf("As one dead in the bottom of a tomb.\n");
        printf("Either my eyesight fails, or thou look'st pale.\n");
    }
    else {
        printf("O churl! drunk all, and left no friendly drop\n");
        printf("To help me after? I will kiss thy lips;\n");
        printf("Haply some poison yet doth hang on them,\n");
        printf("To make die with a restorative.\n");
    }
    return 0;
}