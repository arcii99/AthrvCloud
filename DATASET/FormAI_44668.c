//FormAI DATASET v1.0 Category: Checkers Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int board[SIZE][SIZE];

/* Function to initialize the game board */
void init_board() {
    int i, j;

    for(i=0;i<SIZE;i++) {
        for(j=0;j<SIZE;j++) {
            board[i][j] = 0;
        }
    }

    for(i=0;i<3;i++) {
        for(j=0;j<SIZE;j++) {
            if((i+j)%2==0) {
                board[i][j] = 1;
            }
        }
    }

    for(i=SIZE-3;i<SIZE;i++) {
        for(j=0;j<SIZE;j++) {
            if((i+j)%2==0) {
                board[i][j] = 2;
            }
        }
    }
}

/* Function to print the game board */
void print_board() {
    int i, j;

    for(i=0;i<SIZE;i++) {
        for(j=0;j<SIZE;j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

/* Function to perform a move */
void move(int from_row, int from_col, int to_row, int to_col) {
    if(board[to_row][to_col]!=0) {
        printf("Invalid move!\n");
        return;
    }

    if(board[from_row][from_col]==1) {
        if(to_row<from_row) {
            printf("Invalid move!\n");
            return;
        }

        if(to_row-from_row==1&&(to_col-from_col==1||to_col-from_col==-1)) {
            board[to_row][to_col] = 1;
            board[from_row][from_col] = 0;

            return;
        }

        if(to_row-from_row==2&&abs(to_col-from_col)==2) {
            int middle_row = (from_row+to_row)/2;
            int middle_col = (from_col+to_col)/2;

            if(board[middle_row][middle_col]!=2) {
                printf("Invalid move!\n");
                return;
            }

            board[to_row][to_col] = 1;
            board[from_row][from_col] = 0;
            board[middle_row][middle_col] = 0;

            return;
        }
    }

    if(board[from_row][from_col]==2) {
        if(to_row>from_row) {
            printf("Invalid move!\n");
            return;
        }

        if(to_row-from_row==-1&&(to_col-from_col==1||to_col-from_col==-1)) {
            board[to_row][to_col] = 2;
            board[from_row][from_col] = 0;

            return;
        }

        if(to_row-from_row==-2&&abs(to_col-from_col)==2) {
            int middle_row = (from_row+to_row)/2;
            int middle_col = (from_col+to_col)/2;

            if(board[middle_row][middle_col]!=1) {
                printf("Invalid move!\n");
                return;
            }

            board[to_row][to_col] = 2;
            board[from_row][from_col] = 0;
            board[middle_row][middle_col] = 0;

            return;
        }
    }

    printf("Invalid move!\n");
}

/* Function to check if the game is over */
int is_game_over() {
    int i, j;
    int player1_count = 0;
    int player2_count = 0;

    for(i=0;i<SIZE;i++) {
        for(j=0;j<SIZE;j++) {
            if(board[i][j]==1||board[i][j]==2) {
                if(board[i][j]==1) {
                    player1_count++;
                } else {
                    player2_count++;
                }
            }
        }
    }

    if(player1_count==0||player2_count==0) {
        return 1;
    }

    return 0;
}

int main() {
    init_board();

    while(!is_game_over()) {
        print_board();

        int from_row, from_col, to_row, to_col;
        printf("Player 1's turn (1): ");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
        move(from_row, from_col, to_row, to_col);

        print_board();

        if(is_game_over()) {
            break;
        }

        printf("Player 2's turn (2): ");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
        move(from_row, from_col, to_row, to_col);
    }

    print_board();
    printf("Game Over!\n");

    return 0;
}