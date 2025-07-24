//FormAI DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int board[8][8];
int player = 1;
int gameOver = 0;

void init_board() {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(i%2 == j%2) {
                if(i < 3) {
                    board[i][j] = 1;
                } else if(i > 4) {
                    board[i][j] = 2;
                } else {
                    board[i][j] = 0;
                }
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void print_board() {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == 0) {
                printf(". ");
            } else if(board[i][j] == 1) {
                printf("x ");
            } else if(board[i][j] == 2) {
                printf("o ");
            } else if(board[i][j] == 3) {
                printf("X ");
            } else if(board[i][j] == 4) {
                printf("O ");
            }
        }
        printf("\n");
    }
}

int validate_move(int row, int col, int dest_row, int dest_col) {
    if(dest_row < 0 || dest_col < 0 || dest_row > 7 || dest_col > 7) {
        return 0;
    }

    if(board[dest_row][dest_col] != 0) {
        return 0;
    }

    if(player == 1 && board[row][col] == 1 && dest_row > row) {
        return 0;
    }

    if(player == 2 && board[row][col] == 2 && dest_row < row) {
        return 0;
    }

    if(abs(dest_row - row) == 1 && abs(dest_col - col) == 1 && board[row][col] < 3) {
        return 1;
    }

    if(abs(dest_row - row) == 2 && abs(dest_col - col) == 2) {
        int captured_row = (dest_row + row) / 2;
        int captured_col = (dest_col + col) / 2;

        if(board[captured_row][captured_col] == 0 ||
           board[captured_row][captured_col] == player ||
           board[captured_row][captured_col] == player+2) {
            return 0;
        }

        return 2;
    }

    return 0;
}

void perform_move(int row, int col, int dest_row, int dest_col) {
    board[dest_row][dest_col] = board[row][col];
    board[row][col] = 0;

    if(abs(dest_row - row) == 2) {
        int captured_row = (dest_row + row) / 2;
        int captured_col = (dest_col + col) / 2;

        board[captured_row][captured_col] = 0;
    }

    if(player == 1 && dest_row == 0) {
        board[dest_row][dest_col] = 3;
    }

    if(player == 2 && dest_row == 7) {
        board[dest_row][dest_col] = 4;
    }
}

void switch_player() {
    player = player == 1 ? 2 : 1;
}

void check_game_over() {
    int count_player1 = 0;
    int count_player2 = 0;

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == 1 || board[i][j] == 3) {
                count_player1++;
            } else if(board[i][j] == 2 || board[i][j] == 4) {
                count_player2++;
            }
        }
    }

    if(count_player1 == 0 || count_player2 == 0) {
        gameOver = 1;
        printf("Game Over!\n");

        if(count_player1 == 0) {
            printf("Player 2 wins!\n");
        } else {
            printf("Player 1 wins!\n");
        }
    }
}

int main() {
    init_board();

    while(!gameOver) {
        printf("Player %d's turn:\n", player);
        print_board();

        int row, col, dest_row, dest_col, move_type = 0;
        printf("Enter row and col of checker you want to move: ");
        scanf("%d %d", &row, &col);
        printf("Enter destination row and col: ");
        scanf("%d %d", &dest_row, &dest_col);

        move_type = validate_move(row, col, dest_row, dest_col);

        if(move_type == 0) {
            printf("Invalid Move!\n");
            continue;
        }

        perform_move(row, col, dest_row, dest_col);

        if(move_type == 2) {
            printf("Capture move!\n");

            int next_move_possible = 0;
            for(int i=-2; i<=2; i+=4) {
                for(int j=-2; j<=2; j+=4) {
                    int new_row = dest_row + i;
                    int new_col = dest_col + j;

                    if(validate_move(dest_row, dest_col, new_row, new_col) == 2) {
                        next_move_possible = 1;
                        printf("Possible next capture move: [%d,%d] to [%d,%d]\n", dest_row, dest_col, new_row, new_col);
                    }
                }
            }

            if(next_move_possible) {
                printf("You can capture again!\n");
            } else {
                switch_player();
            }
        } else {
            switch_player();
        }

        check_game_over();
    }

    return 0;
}