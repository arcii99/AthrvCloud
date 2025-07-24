//FormAI DATASET v1.0 Category: Checkers Game ; Style: authentic
#include<stdio.h>

int board[8][8]; // 2D array representing the checkerboard
int player = 0, moves = 0; // player variable keeps track of current player, moves variable keeps track of total moves made
int pieceCount[2] = {12,12}; // array to keep track of remaining pieces for each player

void init_board(); // function to initialize board
void print_board(); // function to print board
void move_piece(int x1, int y1, int x2, int y2); // function to move the piece
int is_valid_move(int x1, int y1, int x2, int y2); // function to check if given move is valid

int main(){

    init_board();

    while(1){

        printf("\nPlayer %d's move\n", (player%2)+1);
        print_board();

        int x1,y1,x2,y2;
        printf("Enter coordinates of piece to move: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter coordinates of destination: ");
        scanf("%d %d", &x2, &y2);

        if(is_valid_move(x1,y1,x2,y2)){
            move_piece(x1,y1,x2,y2);
            moves++;
            player++;
        }
        else{
            printf("Invalid move, try again...\n");
        }

        if(pieceCount[0]==0){
            printf("\nPlayer 2 Wins!!\n");
            break;
        }
        if(pieceCount[1]==0){
            printf("\nPlayer 1 Wins!!\n");
            break;
        }
    }

    return 0;
}

void init_board(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i%2 == 0 && j%2 == 1){
                if(i<3) board[i][j] = 1;
                else if(i>4) board[i][j] = 2;
                else board[i][j] = 0;
            }
            else if(i%2 == 1 && j%2 == 0){
                if(i<3) board[i][j] = 1;
                else if(i>4) board[i][j] = 2;
                else board[i][j] = 0;
            }
            else{
                board[i][j] = 0;
            }
        }
    }
}

void print_board(){
    printf("\n  1 2 3 4 5 6 7 8\n");
    for(int i=0; i<8; i++){
        printf("%d ", i+1);
        for(int j=0; j<8; j++){
            if(board[i][j] == 1) printf("O ");
            else if(board[i][j] == 2) printf("X ");
            else printf("- ");
        }
        printf("\n");
    }
}

int is_valid_move(int x1, int y1, int x2, int y2){

    if(board[x1-1][y1-1] == 0){
        printf("No piece found at given coordinates...\n");
        return 0;
    }

    if(board[x2-1][y2-1] != 0){
        printf("Destination occupied, choose another destination...\n");
        return 0;
    }

    if(player%2 == 0){ // Player 1's turn
        if(board[x1-1][y1-1] != 1 && board[x1-1][y1-1] != -1){
            printf("Invalid piece selected, choose a piece belonging to Player 1...\n");
            return 0;
        }
        if(x2-x1==1 && abs(y2-y1)==1){ // Regular Move
            return 1;
        }
        else if(x2-x1==2 && abs(y2-y1)==2){ // Capture Move
            int mid_x = (x1+x2)/2, mid_y = (y1+y2)/2;
            if(board[mid_x-1][mid_y-1] != 2){
                printf("Invalid capture, the piece being captured by the move must belong to Player 2...\n");
                return 0;
            }
            board[mid_x-1][mid_y-1] = 0; // Remove captured piece from board
            pieceCount[1]--; // Decrease Player 2's remaining pieces
            return 1;
        }
        else{
            printf("Invalid move, try again...\n");
            return 0;
        }
    }
    else{ // Player 2's turn
        if(board[x1-1][y1-1] != 2 && board[x1-1][y1-1] != -2){
            printf("Invalid piece selected, choose a piece belonging to Player 2...\n");
            return 0;
        }
        if(x1-x2==1 && abs(y2-y1)==1){ // Regular move
            return 1;
        }
        else if(x1-x2==2 && abs(y2-y1)==2){ // Capture Move 
            int mid_x = (x1+x2)/2, mid_y = (y1+y2)/2;
            if(board[mid_x-1][mid_y-1] != 1){
                printf("Invalid capture, the piece being captured by the move must belong to Player 1...\n");
                return 0;
            }
            board[mid_x-1][mid_y-1] = 0; // Remove captured piece
            pieceCount[0]--; // Decrease Player 1's remaining pieces
            return 1;
        }
        else{
            printf("Invalid move, try again...\n");
            return 0;
        }
    }

}

void move_piece(int x1, int y1, int x2, int y2){
    // Move piece to new location
    board[x2-1][y2-1] = board[x1-1][y1-1];
    // Remove piece from old location
    board[x1-1][y1-1] = 0;
    //Make king if piece reaches opposite end of board
    if(x2-1 == 0 && board[x2-1][y2-1] == 1) board[x2-1][y2-1] = -1; 
    if(x2-1 == 7 && board[x2-1][y2-1] == 2) board[x2-1][y2-1] = -2;
}