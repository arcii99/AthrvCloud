//FormAI DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include<stdio.h>

char board[8][8] = {
    {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
    {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '},
    {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '}
};

void print_board() {
    printf("  A B C D E F G H\n");
    for (int i=0; i<8; i++) {
        printf("%d", i+1);
        for(int j=0; j<8; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }
}

int is_valid_move(int from_r, int from_c, int to_r, int to_c) {
    if (to_r < 0 || to_c < 0 || to_r > 7 || to_c > 7 || board[to_r][to_c] != ' ') {
        return 0;
    }

    if (board[from_r][from_c] == 'w') {
        if (to_r - from_r == 1 && abs(to_c - from_c) == 1) {
            return 1;
        } else if (to_r - from_r == 2 && abs(to_c - from_c) == 2 && board[(to_r+from_r)/2][(to_c+from_c)/2] == 'b') {
            return 1;
        }
    } else if (board[from_r][from_c] == 'b') {
        if (from_r - to_r == 1 && abs(to_c - from_c) == 1) {
            return 1;
        } else if (from_r - to_r == 2 && abs(to_c - from_c) == 2 && board[(to_r+from_r)/2][(to_c+from_c)/2] == 'w') {
            return 1;
        }
    }

    return 0;
}

int main() {
    int turn = 0;
    int game_over = 0;
    int from_r, from_c, to_r, to_c;

    while (!game_over) {
        print_board();
        if (turn == 0) {
            printf("White's turn:\n");
        } else {
            printf("Black's turn:\n");
        }
        printf("Enter from coordinates (e.g. 4A): ");
        scanf("%d%c", &from_r, &from_c);
        from_r--;
        from_c -= 'A';
        printf("Enter to coordinates (e.g. 3B): ");
        scanf("%d%c", &to_r, &to_c);
        to_r--;
        to_c -= 'A';

        if (is_valid_move(from_r, from_c, to_r, to_c)) {
            board[to_r][to_c] = board[from_r][from_c];
            board[from_r][from_c] = ' ';
        } else {
            printf("Invalid move. Try again.\n");
            continue;
        }

        //check for win condition
        //white win condition
        int white_win = 1;
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                if (board[i][j] == 'b' || board[i][j] == 'B') {
                    white_win = 0;
                    break;
                }
            }
            if (!white_win) {
                break;
            }
        }

        if (white_win) {
            printf("White wins!\n");
            game_over = 1;
            break;
        }

        //black win condition
        int black_win = 1;
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                if (board[i][j] == 'w' || board[i][j] == 'W') {
                    black_win = 0;
                    break;
                }
            }
            if (!black_win) {
                break;
            }
        }

        if (black_win) {
            printf("Black wins!\n");
            game_over = 1;
            break;
        }

        turn = (turn == 0) ? 1 : 0;
    }

    return 0;
}