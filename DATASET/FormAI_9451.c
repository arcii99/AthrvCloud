//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'
#define AI_PLAYER 'O'

char board[BOARD_SIZE][BOARD_SIZE];
int player_count = 2;
int ai_difficulty = 2;

int is_board_full() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int check_for_win(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}

int minimax(char player, int depth, int alpha, int beta) {
    int score = 0;
    if (check_for_win(PLAYER_ONE))
        return depth - 10;
    if (check_for_win(AI_PLAYER))
        return 10 - depth;
    if (is_board_full())
        return 0;

    if (player == AI_PLAYER) {
        int best_score = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = AI_PLAYER;
                    score = minimax(PLAYER_ONE, depth + 1, alpha, beta);
                    board[i][j] = ' ';
                    if (score > best_score) {
                        best_score = score;
                    }
                    if (best_score > alpha) {
                        alpha = best_score;
                    }
                    if (beta <= alpha) {
                        break;
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
                    board[i][j] = PLAYER_ONE;
                    score = minimax(AI_PLAYER, depth + 1, alpha, beta);
                    board[i][j] = ' ';
                    if (score < best_score) {
                        best_score = score;
                    }
                    if (best_score < beta) {
                        beta = best_score;
                    }
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return best_score;
    }
}

void make_ai_move() {
    int best_score = -1000;
    int row, col;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = AI_PLAYER;
                int score = minimax(PLAYER_ONE, 0, -1000, 1000);
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    board[row][col] = AI_PLAYER;
}

void display_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("---");
                if (j < BOARD_SIZE - 1)
                    printf("+");
            }
            printf("\n");
        }
    }
}

void clear_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void play_game() {
    char player = PLAYER_ONE;
    while (!is_board_full() && !check_for_win(PLAYER_ONE) && !check_for_win(PLAYER_TWO)) {
        printf("\n\nPlayer %c's turn\n\n", player);
        if (player == AI_PLAYER) {
            make_ai_move();
        } else {
            int row, col;
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            row--;
            col--;
            while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
                printf("Invalid move, try again\n\n");
                printf("Enter row (1-3): ");
                scanf("%d", &row);
                printf("Enter column (1-3): ");
                scanf("%d", &col);
                row--;
                col--;
            }
            board[row][col] = player;
        }
        display_board();
        if (player_count == 2)
            player = (player == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
        else
            player = (player == PLAYER_ONE) ? AI_PLAYER : PLAYER_ONE;
    }
    if (check_for_win(PLAYER_ONE))
        printf("\n\nPlayer %c wins!", PLAYER_ONE);
    else if (check_for_win(PLAYER_TWO))
        printf("\n\nPlayer %c wins!", PLAYER_TWO);
    else
        printf("\n\nGame over, it's a tie!");
}

void select_game_options() {
    clear_board();
    printf("Welcome to Tic Tac Toe!\n\n");
    printf("Select game options:\n");
    printf("1. Two player game\n");
    printf("2. Play against the computer\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &player_count);
    while (player_count < 1 || player_count > 2) {
        printf("Invalid choice, try again\n\n");
        printf("Select game options:\n");
        printf("1. Two player game\n");
        printf("2. Play against the computer\n");
        printf("Enter choice (1-2): ");
        scanf("%d", &player_count);
    }
    if (player_count == 2) {
        printf("Game starting with two players:\n\n");
        display_board();
        play_game();
    } else {
        printf("Select AI difficulty:\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &ai_difficulty);
        while (ai_difficulty < 1 || ai_difficulty > 3) {
            printf("Invalid choice, try again\n\n");
            printf("Select AI difficulty:\n");
            printf("1. Easy\n");
            printf("2. Medium\n");
            printf("3. Hard\n");
            printf("Enter choice (1-3): ");
            scanf("%d", &ai_difficulty);
        }
        if (ai_difficulty == 1)
            printf("Game starting against Easy difficulty AI:\n\n");
        else if (ai_difficulty == 2)
            printf("Game starting against Medium difficulty AI:\n\n");
        else
            printf("Game starting against Hard difficulty AI:\n\n");
        display_board();
        play_game();
    }
}

int main() {
    select_game_options();
    return 0;
}