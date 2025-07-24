//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>

char board[3][3];  // the game board
int player;        // current player (0 or 1)

/* This function displays the game board */
void display_board() {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

/* This function checks if the game has been won */
int check_win() {
    int i;
    // check rows
    for(i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return 1;
    }
    // check columns
    for(i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return 1;
    }
    // check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return 1;
    if(board[2][0] == board[1][1] && board[2][0] == board[0][2])
        return 1;
    return 0;
}

/* This function checks if the game is a tie */
int check_tie() {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

/* This function makes a move for the AI player */
void ai_move() {
    int row, col;
    // try to win
    if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == ' ')
        row = 0, col = 2;
    else if(board[0][0] == 'O' && board[0][2] == 'O' && board[0][1] == ' ')
        row = 0, col = 1;
    else if(board[0][1] == 'O' && board[0][2] == 'O' && board[0][0] == ' ')
        row = 0, col = 0;
    else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == ' ')
        row = 1, col = 2;
    else if(board[1][0] == 'O' && board[1][2] == 'O' && board[1][1] == ' ')
        row = 1, col = 1;
    else if(board[1][1] == 'O' && board[1][2] == 'O' && board[1][0] == ' ')
        row = 1, col = 0;
    else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == ' ')
        row = 2, col = 2;
    else if(board[2][0] == 'O' && board[2][2] == 'O' && board[2][1] == ' ')
        row = 2, col = 1;
    else if(board[2][1] == 'O' && board[2][2] == 'O' && board[2][0] == ' ')
        row = 2, col = 0;
    // try to block
    else if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == ' ')
        row = 0, col = 2;
    else if(board[0][0] == 'X' && board[0][2] == 'X' && board[0][1] == ' ')
        row = 0, col = 1;
    else if(board[0][1] == 'X' && board[0][2] == 'X' && board[0][0] == ' ')
        row = 0, col = 0;
    else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == ' ')
        row = 1, col = 2;
    else if(board[1][0] == 'X' && board[1][2] == 'X' && board[1][1] == ' ')
        row = 1, col = 1;
    else if(board[1][1] == 'X' && board[1][2] == 'X' && board[1][0] == ' ')
        row = 1, col = 0;
    else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == ' ')
        row = 2, col = 2;
    else if(board[2][0] == 'X' && board[2][2] == 'X' && board[2][1] == ' ')
        row = 2, col = 1;
    else if(board[2][1] == 'X' && board[2][2] == 'X' && board[2][0] == ' ')
        row = 2, col = 0;
    // try to take a corner
    else if(board[0][0] == ' ')
        row = 0, col = 0;
    else if(board[0][2] == ' ')
        row = 0, col = 2;
    else if(board[2][0] == ' ')
        row = 2, col = 0;
    else if(board[2][2] == ' ')
        row = 2, col = 2;
    // take the center
    else if(board[1][1] == ' ')
        row = 1, col = 1;
    // pick a random move
    else {
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while(board[row][col] != ' ');
    }
    board[row][col] = 'O';
}

/* This function gets the user's move */
void get_move() {
    int row, col;
    printf("Player %d, enter your move (row col): ", player+1);
    scanf("%d %d", &row, &col);
    row--, col--;
    if(board[row][col] != ' ') {
        printf("Invalid move!\n");
        get_move();
    }
    else {
        board[row][col] = (player == 0) ? 'X' : 'O';
    }
}

/* This function switches the players */
void switch_players() {
    player = (player == 0) ? 1 : 0;
}

int main() {
    int i, j;
    // initialize the game board
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            board[i][j] = ' ';
    }
    // play the game
    player = 0;
    while(!check_win() && !check_tie()) {
        display_board();
        if(player == 0)
            get_move();
        else
            ai_move();
        switch_players();
    }
    // print the final board
    display_board();
    // print the result of the game
    if(check_win())
        printf("Player %d wins!\n", player+1);
    else
        printf("It's a tie!\n");
    return 0;
}