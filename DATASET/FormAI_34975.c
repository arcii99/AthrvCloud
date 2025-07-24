//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
// It was a crisp autumn day in London, and Sherlock Holmes was eager to test his new Tic Tac Toe AI program.

#include <stdio.h>

void print_board(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ",board[i][0],board[i][1],board[i][2]);
        if (i != 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

int check_win(char board[3][3], char symbol) {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return 1;

    for (int j = 0; j < 3; j++) 
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
            return 1;

    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return 1;

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return 1;

    return 0;
}

int find_best_move(char board[3][3], int depth, char symbol) {
    int score = -1;
    int best_row = -1;
    int best_col = -1;

    if (check_win(board, 'X') == 1) return 10 - depth;
    if (check_win(board, 'O') == 1) return depth - 10;

    if (depth == 9) return 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                board[i][j] = symbol;

                int temp_score = -find_best_move(board, depth + 1, symbol == 'X' ? 'O' : 'X');

                if (temp_score > score) {
                    score = temp_score;
                    best_row = i;
                    best_col = j;
                }

                board[i][j] = '-';
            }
        }
    }

    if (best_row == -1 || best_col == -1) return 0;
    else return score;
}

void perform_move(char board[3][3], char symbol) {
    int best_row = -1;
    int best_col = -1;
    int score = -1;

    if (symbol == 'X') {
        printf("It's your turn. Please enter the row(1-3) and column(1-3) where you want to play: ");
        scanf("%d %d", &best_row, &best_col);
        best_row--; best_col--;
    }
    else {
        printf("\n\nThinking...");
        score = find_best_move(board, 0, symbol);
        printf(" I will play row %d, column %d", best_row+1, best_col+1);
    }

    while (best_row < 0 || best_row > 2 || best_col < 0 || best_col > 2 || board[best_row][best_col] != '-') {
        printf("\nInvalid move! Please enter the row(1-3) and column(1-3) where you want to play: ");
        scanf("%d %d", &best_row, &best_col);
        best_row--; best_col--;
    }
    board[best_row][best_col] = symbol;
}

void play_game() {
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    int turn = 0;

    printf("Welcome to Tic Tac Toe!\n");
    print_board(board);

    while (turn < 9) {
        char symbol = turn % 2 == 0 ? 'X' : 'O';
        perform_move(board, symbol);
        print_board(board);

        if (check_win(board, symbol) == 1) {
            printf("\nGame over! %c wins!", symbol);
            return;
        }
        turn++;
    }

    printf("It's a draw!");
}

int main() {
    play_game();
    return 0;
}