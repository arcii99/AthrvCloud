//FormAI DATASET v1.0 Category: Checkers Game ; Style: happy
#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

int board[SIZE][SIZE];
int turn = 0, winner = -1;

void initialize_board() {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            if((i+j)%2 == 0) {
                if(i<3)
                    board[i][j] = 1;
                else if(i>4)
                    board[i][j] = 2;
                else
                    board[i][j] = 0;
            }
            else
                board[i][j] = -1;
        }
    }
}

int check_valid_move(int player, int row1, int col1, int row2, int col2) {
    if(board[row2][col2] != 0 || (row2+col2)%2 != 0)
        return 0;
    int r_diff = row2 - row1;
    if(player == 1) {
        if(r_diff < 0)
            return 0;
        if(board[row1][col1] == 1 && r_diff == -1 && abs(col2-col1) == 1)
            return 1;
        if(board[row1][col1] == 2 && abs(r_diff) == 1 && abs(col2-col1) == 1)
            return 1;
        if(abs(r_diff) == 2 && abs(col2-col1) == 2 && board[row1 + (r_diff/2)][col1 + (col2-col1)/2] == 2)
            return 1;
    }
    else {
        if(r_diff > 0)
            return 0;
        if(board[row1][col1] == 2 && r_diff == 1 && abs(col2-col1) == 1)
            return 1;
        if(board[row1][col1] == 1 && abs(r_diff) == 1 && abs(col2-col1) == 1)
            return 1;
        if(abs(r_diff) == 2 && abs(col2-col1) == 2 && board[row1 + (r_diff/2)][col1 + (col2-col1)/2] == 1)
            return 1;
    }
    return 0;
}

void move(int player, int row1, int col1, int row2, int col2) {
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = 0;
    if(abs(row2 - row1) == 2 && abs(col2 - col1) == 2)
        board[row1 + (row2-row1)/2][col1 + (col2-col1)/2] = 0;
    if(player == 1) {
        if(row2 == SIZE - 1)
            board[row2][col2] = 2;
    }
    else {
        if(row2 == 0)
            board[row2][col2] = 1;
    }
}

int check_win() {
    int c1 = 0, c2 = 0;
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            if(board[i][j] == 1)
                c1++;
            else if(board[i][j] == 2)
                c2++;
        }
    }
    if(c1 == 0)
        return 2;
    if(c2 == 0)
        return 1;
    return -1;
}

void print_board() {
    printf("Player 1 : X\tPlayer 2 : O\n");
    printf("   ");
    for(int i=0;i<SIZE;i++) {
        printf("%d  ", i);
    }
    printf("\n");
    for(int i=0;i<SIZE;i++) {
        printf("%d ", i);
        for(int j=0;j<SIZE;j++) {
            if(board[i][j] == 0)
                printf("-  ");
            else if(board[i][j] == 1)
                printf("X  ");
            else if(board[i][j] == 2)
                printf("O  ");
            else if(board[i][j] == -1)
                printf("   ");
        }
        printf("\n");
    }
}

int main() {
    initialize_board();
    while(winner == -1) {
        print_board();
        int row1, col1, row2, col2;
        printf("Player %d's turn\n", turn%2+1);
        printf("Enter initial position (row, column): ");
        scanf("%d%d", &row1, &col1);
        printf("Enter final position (row, column): ");
        scanf("%d%d", &row2, &col2);
        if(check_valid_move(turn%2+1, row1, col1, row2, col2)) {
            move(turn%2+1, row1, col1, row2, col2);
            winner = check_win();
            turn ++;
        }
        else {
            printf("Invalid Move. Try Again.\n");
        }
    }
    print_board();
    printf("Player %d wins!", winner);
    return 0;
}