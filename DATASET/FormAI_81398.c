//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

//Function prototypes
void print_board(char board[][3]);
int check_win(char board[][3], char player);
int minimax(char board[][3], int depth, int is_maximizing);
int get_best_move(char board[][3]);
int is_board_full(char board[][3]);

int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player = 'X';

    print_board(board);
    printf("You are 'X'\n\n");

    while (!check_win(board, 'X') && !check_win(board, 'O') && !is_board_full(board)) {
        int row, col, move;

        if (player == 'X') {
            //Player's turn
            printf("Enter row and column (0-2): ");
            scanf("%d %d", &row, &col);

            if (board[row][col] == ' ') {
                board[row][col] = player;
            } else {
                printf("\nInvalid move. Try again.\n");
                continue;
            }
        } else {
            //AI's turn
            move = get_best_move(board);
            row = move / 3;
            col = move % 3;
            board[row][col] = player;
            printf("AI played at row %d, col %d\n", row, col);
        }

        print_board(board);

        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }

    if (check_win(board, 'X')) {
        printf("Congratulations! You won!\n");
    } else if (check_win(board, 'O')) {
        printf("Better luck next time! You lost.\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

void print_board(char board[][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int check_win(char board[][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int minimax(char board[][3], int depth, int is_maximizing) {
    if (check_win(board, 'X')) {
        return -10;
    }
    if (check_win(board, 'O')) {
        return 10;
    }
    if (is_board_full(board)) {
        return 0;
    }

    if (is_maximizing) {
        int best_score = -100;
        for (int i = 0; i < 9; i++) {
            int row = i / 3;
            int col = i % 3;
            if (board[row][col] == ' ') {
                board[row][col] = 'O';
                int score = minimax(board, depth+1, 0);
                board[row][col] = ' ';
                if (score > best_score) {
                    best_score = score;
                }
            }
        }
        return best_score;
    } else {
        int best_score = 100;
        for (int i = 0; i < 9; i++) {
            int row = i / 3;
            int col = i % 3;
            if (board[row][col] == ' ') {
                board[row][col] = 'X';
                int score = minimax(board, depth+1, 1);
                board[row][col] = ' ';
                if (score < best_score) {
                    best_score = score;
                }
            }
        }
        return best_score;
    }
}

int get_best_move(char board[][3]) {
    int best_score = -100;
    int best_move = -1;
    for (int i = 0; i < 9; i++) {
        int row = i / 3;
        int col = i % 3;
        if (board[row][col] == ' ') {
            board[row][col] = 'O';
            int score = minimax(board, 0, 0);
            board[row][col] = ' ';
            if (score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
    }
    return best_move;
}

int is_board_full(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}