//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to clear the screen
void clear_screen() {
    system("clear");
}

//function to render the game board
void render(char board[][3]) {
    clear_screen();
    printf("\n-------------------\n");
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n-------------------\n");
    }
}

//function to check if someone won
char check_win(char board[][3]) {
    //check horizontally
    for(int i=0;i<3;i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    //check vertically
    for(int i=0;i<3;i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    //check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return ' ';
}

int main() {
    char board[3][3];
    char player1 = 'X';
    char player2 = 'O';
    char current_player = player1;
    int turn_count = 0;
    //initialize board
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            board[i][j] = '-';
        }
    }
    render(board);
    while(turn_count < 9 && check_win(board) == ' ') {
        int row, col;
        //input row and column from current player
        printf("Player %c, enter row and column [1-3],[1-3]: ", current_player);
        scanf("%d,%d", &row, &col);
        //decrement row and col as they start from 1
        row--;
        col--;
        //check if the cell is empty
        if(board[row][col] == '-') {
            board[row][col] = current_player;
            turn_count++;
            //switch player
            if(current_player == player1) {
                current_player = player2;
            } else {
                current_player = player1;
            }
            render(board);
        } else {
            printf("Cell not empty. Try again.\n");
        }
    }
    char winner = check_win(board);
    if(winner != ' ') {
        printf("Player %c wins!\n", winner);
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}