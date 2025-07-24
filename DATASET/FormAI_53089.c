//FormAI DATASET v1.0 Category: Checkers Game ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX 8

char board[MAX][MAX];   // Initialize the checkers board
int turn;               // Whose turn is it
int red_kills;          // How many red checkers have been killed
int black_kills;        // How many black checkers have been killed
char piece;             // The character for a piece on the board
char player[10];        // The current player's name

// Display the checkers board
void display_board(){
    printf("\n   ");
    for(int i = 0; i < MAX; i++){
        printf("%d ", i+1);
    }
    printf("\n   ");
    for(int i = 0; i < MAX; i++){
        printf("__");
    }

    for(int i = 0; i < MAX; i++){
        printf("\n%d |", i+1);
        for(int j = 0; j < MAX; j++){
            piece = board[i][j];
            printf("%c|", piece);
        }
    }
    printf("\n   ");
    for(int i = 0; i < MAX; i++){
        printf("--");
    }
    printf("\n\n");
}

// Check if a move is valid
int valid_move(int row1, int col1, int row2, int col2){
    piece = board[row1][col1];
    if(piece == ' '){
        return 0;
    }
    if(turn == 1){
        if(piece == 'b' || piece == 'B'){
            return 0;
        }
    }else{
        if(piece == 'r' || piece == 'R'){
            return 0;
        }
    }
    if(abs(row2 - row1) != abs(col2 - col1)){
        return 0;
    }
    if(row2 < 0 || col2 < 0 || row2 > 7 || col2 > 7){
        return 0;
    }
    if(board[row2][col2] != ' '){
        return 0;
    }
    if(abs(row2 - row1) > 2){
        return 0;
    }
    if(abs(row2 - row1) == 2){
        int jump_row = (row1 + row2) / 2;
        int jump_col = (col1 + col2) / 2;
        char jump_piece = board[jump_row][jump_col];
        if((turn == 1 && (jump_piece == 'r' || jump_piece == 'R')) || (turn == 2 && (jump_piece == 'b' || jump_piece == 'B'))){
            board[jump_row][jump_col] == ' ';
            if(turn == 1){
                red_kills++;
            }else{
                black_kills++;
            }
        }else{
            return 0;
        }
    }
    if(piece == 'r' || piece == 'b'){
        if(abs(row2 - row1) != 1){
            return 0;
        }
    }
    if(piece == 'R' || piece == 'B'){
        int i, j;
        if(row2 < row1){
            i = -1;
        }else{
            i = 1;
        }
        if(col2 < col1){
            j = -1;
        }else{
            j = 1;
        }
        int row = row1 + i;
        int col = col1 + j;
        while(row != row2){
            if(board[row][col] != ' '){
                return 0;
            }
            row += i;
            col += j;
        }
    }
    return 1;
}

// Make a move
void make_move(int row1, int col1, int row2, int col2){
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = ' ';
    if((row2 == 0 && turn == 1 && board[row2][col2] == 'r') || (row2 == 7 && turn == 2 && board[row2][col2] == 'b')){
        board[row2][col2] = toupper(board[row2][col2]);
    }
}

int main(){
    // Initialize the game variables
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(i < 3){
                if((i+j)%2 == 0){
                    board[i][j] = 'b';
                }else{
                    board[i][j] = ' ';
                }
            }else if(i > 4){
                if((i+j)%2 == 0){
                    board[i][j] = 'r';
                }else{
                    board[i][j] = ' ';
                }
            }else{
                board[i][j] = ' ';
            }
        }
    }
    turn = 1;
    red_kills = 0;
    black_kills = 0;
    char winner[10] = " ";

    // Introduction
    printf("Welcome to Surrealist Checkers!\n\n");
    printf("Instructions:\n");
    printf("- Each player starts with 12 checkers.\n");
    printf("- Checkers can move diagonally.\n");
    printf("- To move, enter the row number and column number of the piece you want to move, followed by the row number and column number of the space you want to move it to.\n");
    printf("- Jumping over an opponent's piece removes it from the board.\n");
    printf("- If a checker reaches the other side of the board, it becomes a king and can move diagonally in any direction.\n");
    printf("- The game ends when one player captures all of the other player's checkers or when the other player cannot make a move.\n\n");

    // Get player names
    printf("Player 1, enter your name: ");
    scanf("%s", player);
    printf("Player 2, enter your name: ");
    scanf("%s", player);

    // Main loop
    int row1, col1, row2, col2;
    while(1){
        display_board();
        if(turn == 1){
            printf("%s's turn (Red)\n", player);
        }else{
            printf("%s's turn (Black)\n", player);
        }
        printf("Enter the row number and column number of the piece you want to move, separated by a space: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the row number and column number of the space you want to move it to, separated by a space: ");
        scanf("%d %d", &row2, &col2);
        if(valid_move(row1-1, col1-1, row2-1, col2-1)){
            make_move(row1-1, col1-1, row2-1, col2-1);
            if(turn == 1){
                turn = 2;
            }else{
                turn = 1;
            }
        }else{
            printf("Invalid move, please try again.\n");
        }
    }
    return 0;
}