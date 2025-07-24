//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to display the Tic Tac Toe board
void display_board(char board[3][3])
{
    printf("  0 1 2\n");
    for(int i=0;i<3;i++){
        printf("%d %c %c %c\n", i, board[i][0], board[i][1], board[i][2]);
    }
}

// Function to check if there is a winner
char check_win(char board[3][3])
{
    char result = '-';

    for(int i=0;i<3;i++){
        // Check horizontal
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            result = board[i][0];
        }
        // Check vertical
        else if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            result = board[0][i];
        }
    }

    // Check diagonal
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        result = board[0][0];
    }
    else if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        result = board[0][2];
    }

    return result;
}

// Function to check if the board is full
int is_board_full(char board[3][3])
{
    int count = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] != '-'){
                count++;
            }
        }
    }
    if(count == 9){
        return 1;
    }
    else{
        return 0;
    }
}

// AI function to choose the best move
void get_best_move(char board[3][3], int *row, int *col)
{
    // If the center is empty, take it
    if(board[1][1] == '-'){
        *row = 1;
        *col = 1;
        return;
    }

    // Check if there is a winning move
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == '-'){
                board[i][j] = 'O';
                if(check_win(board) == 'O'){
                    *row = i;
                    *col = j;
                    board[i][j] = '-';
                    return;
                }
                board[i][j] = '-';
            }
        }
    }

    // Check if the opponent has a winning move
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == '-'){
                board[i][j] = 'X';
                if(check_win(board) == 'X'){
                    *row = i;
                    *col = j;
                    board[i][j] = '-';
                    return;
                }
                board[i][j] = '-';
            }
        }
    }

    // Choose a random move
    int range = 3;
    *row = rand() % range;
    *col = rand() % range;
}

// Main function
int main()
{
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    int row, col;

    while(!is_board_full(board)){
        display_board(board);
        printf("Enter row number (0-2) and column number (0-2): ");
        scanf("%d%d", &row, &col);

        if(board[row][col] == '-'){
            board[row][col] = 'X';
        }
        else{
            printf("Invalid move!\n\n");
            continue;
        }

        char winner = check_win(board);
        if(winner != '-'){
            printf("\n\nGame Over! %c wins!\n", winner);
            display_board(board);
            return 0;
        }

        get_best_move(board, &row, &col);
        board[row][col] = 'O';

        winner = check_win(board);
        if(winner != '-'){
            printf("\n\nGame Over! %c wins!\n", winner);
            display_board(board);
            return 0;
        }
    }

    printf("\n\nGame Over! It's a draw!\n");
    display_board(board);

    return 0;
}