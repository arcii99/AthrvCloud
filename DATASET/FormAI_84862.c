//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int count(char board[3][3], char cell) {
    int i, j, c = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] == cell)
                c++;
    return c;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int evaluate(char board[3][3], char player) {
    int i;
    int score = 0;
    char opponent = (player == 'X') ? 'O' : 'X';

    // Rows
    for (i = 0; i < 3; i++) {
        if (count(board[i], player) == 3)
            score += 1000;
        else if (count(board[i], player) == 2 && count(board[i], '_') == 1)
            score += 10;
        else if (count(board[i], player) == 1 && count(board[i], '_') == 2)
            score += 1;

        if (count(board[i], opponent) == 3)
            score -= 1000;
        else if (count(board[i], opponent) == 2 && count(board[i], '_') == 1)
            score -= 10;
        else if (count(board[i], opponent) == 1 && count(board[i], '_') == 2)
            score -= 1;
    }

    // Columns
    for (i = 0; i < 3; i++) {
        char column[3] = { board[0][i], board[1][i], board[2][i] };
        if (count(column, player) == 3)
            score += 1000;
        else if (count(column, player) == 2 && count(column, '_') == 1)
            score += 10;
        else if (count(column, player) == 1 && count(column, '_') == 2)
            score += 1;

        if (count(column, opponent) == 3)
            score -= 1000;
        else if (count(column, opponent) == 2 && count(column, '_') == 1)
            score -= 10;
        else if (count(column, opponent) == 1 && count(column, '_') == 2)
            score -= 1;
    }

    // Diagonal 1
    char diagonal1[3] = { board[0][0], board[1][1], board[2][2] };
    if (count(diagonal1, player) == 3)
        score += 1000;
    else if (count(diagonal1, player) == 2 && count(diagonal1, '_') == 1)
        score += 10;
    else if (count(diagonal1, player) == 1 && count(diagonal1, '_') == 2)
        score += 1;

    if (count(diagonal1, opponent) == 3)
        score -= 1000;
    else if (count(diagonal1, opponent) == 2 && count(diagonal1, '_') == 1)
        score -= 10;
    else if (count(diagonal1, opponent) == 1 && count(diagonal1, '_') == 2)
        score -= 1;

    // Diagonal 2
    char diagonal2[3] = { board[0][2], board[1][1], board[2][0] };
    if (count(diagonal2, player) == 3)
        score += 1000;
    else if (count(diagonal2, player) == 2 && count(diagonal2, '_') == 1)
        score += 10;
    else if (count(diagonal2, player) == 1 && count(diagonal2, '_') == 2)
        score += 1;

    if (count(diagonal2, opponent) == 3)
        score -= 1000;
    else if (count(diagonal2, opponent) == 2 && count(diagonal2, '_') == 1)
        score -= 10;
    else if (count(diagonal2, opponent) == 1 && count(diagonal2, '_') == 2)
        score -= 1;

    return score;
}

int is_game_over(char board[3][3]) {
    int i, j;

    // Rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != '_' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }

    // Columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] != '_' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    // Diagonal 1
    if (board[0][0] != '_' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    // Diagonal 2
    if (board[0][2] != '_' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    // Draw
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '_')
                return 0;
        }
    }

    return 2;
}

int min_max(char board[3][3], int depth, int is_max, char player) {
    int i, j, score, best_score;
    char opponent;

    if (player == 'X')
        opponent = 'O';
    else
        opponent = 'X';

    if (is_game_over(board) == 1)
        return evaluate(board, player);

    if (is_game_over(board) == 2)
        return 0;

    if (is_max) {
        best_score = INT_MIN;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    score = min_max(board, depth+1, !is_max, player);
                    board[i][j] = '_';
                    best_score = max(best_score, score);
                }
            }
        }
    } else {
        best_score = INT_MAX;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = opponent;
                    score = min_max(board, depth+1, !is_max, player);
                    board[i][j] = '_';
                    best_score = min(best_score, score);
                }
            }
        }
    }

    return best_score;
}

void ai_play(char board[3][3], char player) {
    int i, j, score, best_score = INT_MIN;
    int row, col;
    char opponent;

    if (player == 'X')
        opponent = 'O';
    else
        opponent = 'X';

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                board[i][j] = player;
                score = min_max(board, 0, 0, player);
                board[i][j] = '_';
                if (score > best_score) {
                    best_score = score;
                    row = i;
                    col = j;
                }
            }
        }
    }

    printf("\nAI %c plays at (%d, %d)\n", player, row+1, col+1);
    board[row][col] = player;
}

int main() {
    char board[3][3] = { { '_', '_', '_' }, { '_', '_', '_' }, { '_', '_', '_' } };
    int i, j, row, col, turn = 1;

    while (1) {
        printf("=== Turn %d ===\n", turn);
        printf("Current board:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // User plays
        printf("\nUser plays: ");
        printf("\nEnter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        if (board[row-1][col-1] != '_') {
            printf("Invalid move!\n");
            continue;
        } else {
            board[row-1][col-1] = 'O';
        }
        turn++;

        if (is_game_over(board) == 1) {
            printf("User wins!\n");
            break;
        }

        if (is_game_over(board) == 2) {
            printf("Draw!\n");
            break;
        }

        // AI plays
        ai_play(board, 'X');
        turn++;

        if (is_game_over(board) == 1) {
            printf("AI wins!\n");
            break;
        }

        if (is_game_over(board) == 2) {
            printf("Draw!\n");
            break;
        }
    }

    return 0;
}