//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to print the Tic Tac Toe board
void print_board(char board[3][3]){
    printf("   1  2  3 \n");
    for(int i=0; i<3; i++){
        printf("%d ",i+1);
        for(int j=0; j<3; j++){
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
int check_win(char player, char board[3][3]){
    // checking horizontal rows
    for(int i=0; i<3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // checking vertical columns
    for(int i=0; i<3; i++){
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }

    // checking diagonal from top left to bottom right
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;

    // checking diagonal from top right to bottom left
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

// Function to check if the game is a tie
int check_tie(char board[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// Function to get the best move for the AI
void get_best_move(char board[3][3], char player, int *row, int *col){

    int best_score = -1000;
    int score;
    *row = -1;
    *col = -1;

    // Checking every possible empty position
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == ' '){
                board[i][j] = player;

                if(player == 'X')
                    get_best_move(board, 'O', &i, &j);
                else
                    get_best_move(board, 'X', &i, &j);

                board[i][j] = ' ';

                // Giving the move a score based on its potential outcome
                if(player == 'X')
                    score = -1;
                else
                    score = 1;

                if(score > best_score){
                    best_score = score;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
}

int main(){
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col;
    int turn = 0;
    char player = 'X';

    int game_status = 0;

    while(!game_status){
        print_board(board);

        // Getting player's move
        printf("Player %c's turn.\n", player);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);

        // Checking if the move is valid
        if(row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' '){
            printf("Invalid move!\n");
            continue;
        }

        // Updating the board with the player's move
        board[row-1][col-1] = player;

        // Checking if the game has ended
        if(check_win(player, board)){
            printf("Player %c wins!\n", player);
            game_status = 1;
            break;
        }

        if(check_tie(board)){
            printf("It's a tie!\n");
            game_status = 1;
            break;
        }

        // Getting AI's move
        if(turn == 8){
            printf("Game is over! It's a tie.\n");
            break;
        }

        if(player == 'X')
            player = 'O';
        else
            player = 'X';

        printf("AI's turn...\n");

        get_best_move(board, player, &row, &col);

        board[row][col] = player;

        // Checking if the game has ended
        if(check_win(player, board)){
            printf("Player %c wins!\n", player);
            game_status = 1;
            break;
        }

        if(check_tie(board)){
            printf("It's a tie!\n");
            game_status = 1;
            break;
        }

        turn++;
    }

    print_board(board);

    return 0;
}