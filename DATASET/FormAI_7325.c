//FormAI DATASET v1.0 Category: Chess engine ; Style: multivariable
#include <stdio.h>

#define WHITE 0
#define BLACK 1

// The chess board representation
int board[8][8] = { {2, 3, 4, 5, 6, 4, 3, 2},
                    {1, 1, 1, 1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {-1,-1,-1,-1,-1,-1,-1,-1},
                    {-2,-3,-4,-5,-6,-4,-3,-2} };

// The current player
int current_player = WHITE;

// Print the board
void print_board(){
    int i,j;
    printf("\n   A B C D E F G H\n");
    for(i=0;i<8;i++){
        printf("%d  ",8-i);
        for(j=0;j<8;j++){
            if(board[i][j] == 1) printf("P ");
            else if(board[i][j] == -1) printf("p ");
            else if(board[i][j] == 2) printf("R ");
            else if(board[i][j] == -2) printf("r ");
            else if(board[i][j] == 3) printf("N ");
            else if(board[i][j] == -3) printf("n ");
            else if(board[i][j] == 4) printf("B ");
            else if(board[i][j] == -4) printf("b ");
            else if(board[i][j] == 5) printf("Q ");
            else if(board[i][j] == -5) printf("q ");
            else if(board[i][j] == 6) printf("K ");
            else if(board[i][j] == -6) printf("k ");
            else printf("  ");
        }
        printf(" %d",8-i);
        printf("\n");
    }
    printf("   A B C D E F G H\n");
}

// Check if the given move is valid
int is_valid_move(int from_x, int from_y, int to_x, int to_y){
    // Check if the piece can move to the destination
    switch(board[from_x][from_y]) {
        // Pawn
        case 1: {
            if(to_x == from_x + 1 && to_y == from_y && board[to_x][to_y] == 0) return 1;
            else if(to_x == from_x + 2 && to_y == from_y && board[to_x][to_y] == 0 &&
                board[from_x+1][from_y] == 0 && from_x == 1) return 1;
            else if(to_x == from_x + 1 && (to_y == from_y - 1 || to_y == from_y + 1) &&
                board[to_x][to_y] != 0 && board[to_x][to_y] < 0) return 1;
            break;
        }
        // Rook
        case 2: {
            if(from_x==to_x || from_y==to_y) {
                int i,j;
                if(from_x == to_x){
                    if(to_y > from_y){
                        for(i=from_y+1;i<to_y;i++){
                            if(board[from_x][i]!=0) return 0;
                        }
                    }
                    else {
                        for(i=from_y-1;i>to_y;i--){
                            if(board[from_x][i]!=0) return 0;
                        }
                    }
                    if(board[from_x][to_y] != 0 && board[from_x][to_y] > 0) return 0;
                    return 1;
                }
                else {
                    if(to_x > from_x){
                        for(i=from_x+1;i<to_x;i++){
                            if(board[i][from_y]!=0) return 0;
                        }
                    }
                    else {
                        for(i=from_x-1;i>to_x;i--){
                            if(board[i][from_y]!=0) return 0;
                        }
                    }
                    if(board[to_x][from_y] != 0 && board[to_x][from_y] > 0) return 0;
                    return 1;
                }
            }
            break;
        }
        // Knight
        case 3: {
            if((to_x == from_x + 1 && to_y == from_y + 2) ||
                (to_x == from_x + 2 && to_y == from_y + 1) ||
                (to_x == from_x + 2 && to_y == from_y - 1) ||
                (to_x == from_x + 1 && to_y == from_y - 2) ||
                (to_x == from_x - 1 && to_y == from_y - 2) ||
                (to_x == from_x - 2 && to_y == from_y - 1) ||
                (to_x == from_x - 2 && to_y == from_y + 1) ||
                (to_x == from_x - 1 && to_y == from_y + 2)) {
                    if(board[to_x][to_y] != 0 && board[to_x][to_y] > 0) return 0;
                    return 1;
                }
                break;
        }
        // Bishop
        case 4: {
            if(to_x - from_x == to_y - from_y || to_x - from_x == from_y - to_y) {
                int i,j;
                if(to_x - from_x > 0){
                    if(to_y - from_y > 0){
                        for(i=1;i<to_x-from_x;i++){
                            if(board[from_x+i][from_y+i]!=0) return 0;
                        }
                    }
                    else {
                        for(i=1;i<to_x-from_x;i++){
                            if(board[from_x+i][from_y-i]!=0) return 0;
                        }
                    }
                }
                else {
                    if(to_y - from_y > 0){
                        for(i=1;i<from_x-to_x;i++){
                            if(board[from_x-i][from_y+i]!=0) return 0;
                        }
                    }
                    else {
                        for(i=1;i<from_x-to_x;i++){
                            if(board[from_x-i][from_y-i]!=0) return 0;
                        }
                    }
                }
                if(board[to_x][to_y] != 0 && board[to_x][to_y] > 0) return 0;
                return 1;
            }
            break;
        }
        // Queen
        case 5: {
            if((to_x == from_x || to_y == from_y) || 
                (to_x - from_x == to_y - from_y || to_x - from_x == from_y - to_y)) {
                int i,j;
                if(from_x == to_x){
                    if(to_y > from_y){
                        for(i=from_y+1;i<to_y;i++){
                            if(board[from_x][i]!=0) return 0;
                        }
                    }
                    else {
                        for(i=from_y-1;i>to_y;i--){
                            if(board[from_x][i]!=0) return 0;
                        }
                    }
                    if(board[from_x][to_y] != 0 && board[from_x][to_y] > 0) return 0;
                    return 1;
                }
                else if(from_y == to_y){
                    if(to_x > from_x){
                        for(i=from_x+1;i<to_x;i++){
                            if(board[i][from_y]!=0) return 0;
                        }
                    }
                    else {
                        for(i=from_x-1;i>to_x;i--){
                            if(board[i][from_y]!=0) return 0;
                        }
                    }
                    if(board[to_x][from_y] != 0 && board[to_x][from_y] > 0) return 0;
                    return 1;
                }
                else if(to_x - from_x == to_y - from_y) {
                    if(to_x - from_x > 0){
                        if(to_y - from_y > 0){
                            for(i=1;i<to_x-from_x;i++){
                                if(board[from_x+i][from_y+i]!=0) return 0;
                            }
                        }
                        else {
                            for(i=1;i<to_x-from_x;i++){
                                if(board[from_x+i][from_y-i]!=0) return 0;
                            }
                        }
                    }
                    else {
                        if(to_y - from_y > 0){
                            for(i=1;i<from_x-to_x;i++){
                                if(board[from_x-i][from_y+i]!=0) return 0;
                            }
                        }
                        else {
                            for(i=1;i<from_x-to_x;i++){
                                if(board[from_x-i][from_y-i]!=0) return 0;
                            }
                        }
                    }
                    if(board[to_x][to_y] != 0 && board[to_x][to_y] > 0) return 0;
                    return 1;
                }
                else if(to_x - from_x == from_y - to_y) {
                    if(to_x - from_x > 0){
                        if(to_y - from_y > 0){
                            for(i=1;i<to_x-from_x;i++){
                                if(board[from_x+i][from_y+i]!=0) return 0;
                            }
                        }
                        else {
                            for(i=1;i<to_x-from_x;i++){
                                if(board[from_x+i][from_y-i]!=0) return 0;
                            }
                        }
                    }
                    else {
                        if(to_y - from_y > 0){
                            for(i=1;i<from_x-to_x;i++){
                                if(board[from_x-i][from_y+i]!=0) return 0;
                            }
                        }
                        else {
                            for(i=1;i<from_x-to_x;i++){
                                if(board[from_x-i][from_y-i]!=0) return 0;
                            }
                        }
                    }
                    if(board[to_x][to_y] != 0 && board[to_x][to_y] > 0) return 0;
                    return 1;
                }
            }
            break;
        }
        // King
        case 6: {
            if((to_x == from_x && (to_y == from_y + 1 || to_y == from_y - 1)) ||
                (to_y == from_y && (to_x == from_x + 1 || to_x == from_x - 1)) ||
                ((to_x == from_x + 1 || to_x == from_x - 1) &&
                (to_y == from_y + 1 || to_y == from_y - 1))) {
                    if(board[to_x][to_y] != 0 && board[to_x][to_y] > 0) return 0;
                    return 1;
                }
                break;
        }
    }
    return 0;
}

// Move a piece
void move_piece(int from_x, int from_y, int to_x, int to_y){
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = 0;
    if(current_player == WHITE) current_player = BLACK;
    else current_player = WHITE;
}

// Get the player's move
void get_move(){
    int from_x,from_y,to_x,to_y;
    printf("\n%c's move: ",current_player==WHITE?'W':'B');
    scanf(" %c%d %c%d",&from_y,&from_x,&to_y,&to_x);
    from_y -= 'A';
    to_y -= 'A';
    from_x = 8 - from_x;
    to_x = 8 - to_x;
    if(is_valid_move(from_x,from_y,to_x,to_y)){
        move_piece(from_x,from_y,to_x,to_y);
    }
    else {
        printf("Invalid move!\n");
        get_move();
    }
}

int main(){
    printf("Welcome to the chess game!\n");
    while(1){
        print_board();
        get_move();
    }
    return 0;
}