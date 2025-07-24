//FormAI DATASET v1.0 Category: Checkers Game ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#define BOARD_SIZE 8
#define EMPTY '_'
#define WHITE 'W'
#define BLACK 'B'

char board[BOARD_SIZE][BOARD_SIZE] = {EMPTY};

// Initialize the game board
void init_board(){
    int i, j;
    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            if((i+j)%2 == 0)
                board[i][j] = EMPTY;
            else if(i<3)
                board[i][j] = BLACK;
            else if(i>4)
                board[i][j] = WHITE;
            else
                board[i][j] = EMPTY;
        }
    }
}

// Print the game board
void print_board(){
    int i, j;
    printf("   "); // Align the column labels
    for(i=0;i<BOARD_SIZE;i++)
        printf("%d ", i+1);
    printf("\n");

    for(i=0;i<BOARD_SIZE;i++){
        printf("%d  ", i+1);
        for(j=0;j<BOARD_SIZE;j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

// Move a piece from (x1, y1) to (x2, y2)
void move_piece(int x1, int y1, int x2, int y2){
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = EMPTY;
}

// Check if a piece can be moved from (x1, y1) to (x2, y2)
int valid_move(char player, int x1, int y1, int x2, int y2){
    if(x2<0 || y2<0 || x2>=BOARD_SIZE || y2>=BOARD_SIZE)
        return 0; // Out of bounds
    
    if(board[x2][y2] != EMPTY)
        return 0; // Square is not empty

    int dx = abs(x2-x1), dy = abs(y2-y1);
    if(dx != dy || dx<1 || dx>2)
        return 0; // Invalid move

    if(board[x1][y1] == WHITE && player == BLACK)
        return 0; // Wrong player
    
    if(board[x1][y1] == BLACK && player == WHITE)
        return 0; // Wrong player

    if(dx == 1){ // Move without capturing
        if(board[x1][y1] == WHITE && y2<y1)
            return 0; // Invalid direction
        if(board[x1][y1] == BLACK && y2>y1)
            return 0; // Invalid direction
    }
    else{ // Move with capturing
        int x3 = (x1+x2)/2, y3 = (y1+y2)/2;
        if(board[x3][y3] == EMPTY)
            return 0; // No piece to capture
        if(board[x3][y3] == board[x1][y1])
            return 0; // Cannot capture own piece
    }

    return 1; // Valid move
}

// Execute a move and return the number of captured pieces
int execute_move(char player, int x1, int y1, int x2, int y2){
    int x3 = (x1+x2)/2, y3 = (y1+y2)/2;
    int captured = 0;

    if(valid_move(player, x1, y1, x2, y2)){
        if(abs(x2-x1) == 1){ // Move without capturing
            move_piece(x1, y1, x2, y2);
        }
        else{ // Move with capturing
            move_piece(x1, y1, x2, y2);
            board[x3][y3] = EMPTY;
            captured = 1;
        }
    }

    return captured;
}

// Check if a player has won the game
int check_win(char player){
    int i, j;
    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            if(board[i][j] == player){
                if(player == WHITE){
                    if(i+1<BOARD_SIZE && j-1>=0 && board[i+1][j-1] == EMPTY)
                        return 0; // Game is not over
                    if(i+1<BOARD_SIZE && j+1<BOARD_SIZE && board[i+1][j+1] == EMPTY)
                        return 0; // Game is not over
                    if(i+2<BOARD_SIZE && j-2>=0 && board[i+1][j-1] == BLACK && board[i+2][j-2] == EMPTY)
                        return 0; // Game is not over
                    if(i+2<BOARD_SIZE && j+2<BOARD_SIZE && board[i+1][j+1] == BLACK && board[i+2][j+2] == EMPTY)
                        return 0; // Game is not over
                }
                else{ // player == BLACK
                    if(i-1>=0 && j-1>=0 && board[i-1][j-1] == EMPTY)
                        return 0; // Game is not over
                    if(i-1>=0 && j+1<BOARD_SIZE && board[i-1][j+1] == EMPTY)
                        return 0; // Game is not over
                    if(i-2>=0 && j-2>=0 && board[i-1][j-1] == WHITE && board[i-2][j-2] == EMPTY)
                        return 0; // Game is not over
                    if(i-2>=0 && j+2<BOARD_SIZE && board[i-1][j+1] == WHITE && board[i-2][j+2] == EMPTY)
                        return 0; // Game is not over
                }
            }
        }
    }

    return 1; // Game is over, player has won
}

// Main function to play the game
int main(){
    char player = WHITE;
    int x1, y1, x2, y2, captured;

    init_board();
    print_board();

    while(1){
        printf("%c's turn\n", player);
        printf("Enter coordinates of piece to move (row col): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter coordinates of destination (row col): ");
        scanf("%d %d", &x2, &y2);

        captured = execute_move(player, x1-1, y1-1, x2-1, y2-1);
        if(captured == 0){
            printf("Invalid move\n");
            continue;
        }

        if(check_win(player)){
            printf("%c wins!\n", player);
            break;
        }

        print_board();

        if(player == WHITE)
            player = BLACK;
        else
            player = WHITE;
    }

    return 0;
}