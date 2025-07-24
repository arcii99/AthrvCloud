//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: complete
#include <stdio.h>
#include <stdbool.h>

void draw_board(char board[3][3]) {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

bool make_move(char board[3][3], int row, int col, char player) {
    if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
        return false;
    }
    board[row][col] = player;
    return true;
}

char winner(char board[3][3]) {
    // check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return board[i][0];
        }
    }
    // check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return board[0][i];
        }
    }
    // check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return board[0][2];
    }
    // check for tie
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                return '-';
            }
        }
    }
    return 'T';
}

int minimax(char board[3][3], char ai_player, char human_player, int depth, bool is_maximizing) {
    char result = winner(board);
    if(result == ai_player) {
        return 10;
    }
    if(result == human_player) {
        return -10;
    }
    if(result == 'T') {
        return 0;
    }
    if(is_maximizing) {
        int best_score = -1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = ai_player;
                    int score = minimax(board, ai_player, human_player, depth + 1, false);
                    board[i][j] = '-';
                    if(score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = human_player;
                    int score = minimax(board, ai_player, human_player, depth + 1, true);
                    board[i][j] = '-';
                    if(score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

void ai_turn(char board[3][3], char ai_player, char human_player) {
    int best_score = -1000;
    int move_row, move_col;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = ai_player;
                int score = minimax(board, ai_player, human_player, 0, false);
                board[i][j] = '-';
                if(score > best_score) {
                    best_score = score;
                    move_row = i;
                    move_col = j;
                }
            }
        }
    }
    make_move(board, move_row, move_col, ai_player);
    printf("AI played at row %d, column %d\n", move_row + 1, move_col + 1);
}

void human_turn(char board[3][3], char human_player) {
    int row, col;
    printf("Enter a row (1-3) and column (1-3), separated by a space: ");
    scanf("%d %d", &row, &col);
    row--;
    col--;
    if(make_move(board, row, col, human_player)) {
        printf("You played at row %d, column %d\n", row + 1, col + 1);
    } else {
        printf("Invalid move. Try again.\n");
        human_turn(board, human_player);
    }
}

int main() {
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    char ai_player = 'X';
    char human_player = 'O';
    bool ai_turn_first = true;
    while(winner(board) == '-') {
        draw_board(board);
        if(ai_turn_first) {
            ai_turn(board, ai_player, human_player);
            ai_turn_first = false;
        } else {
            human_turn(board, human_player);
        }
        if(winner(board) != '-') {
            break;
        }
        ai_turn(board, ai_player, human_player);
    }
    draw_board(board);
    char the_winner = winner(board);
    if(the_winner == 'T') {
        printf("It's a tie!");
    } else if(the_winner == ai_player) {
        printf("The AI wins!");
    } else {
        printf("You win!");
    }
    return 0;
}