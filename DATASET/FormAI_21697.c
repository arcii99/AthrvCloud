//FormAI DATASET v1.0 Category: Chess AI ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define board_size 8

int board[board_size][board_size] = {
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1}
};

int evaluate_board() {
    int i,j;
    int score = 0;
    for(i=0;i<board_size;i++){
        for(j=0;j<board_size;j++){
            if(board[i][j] == 1)      // if it's chess piece
            {
                if(i == 0 || i == 1)  // if it is in the 1st or 2nd row of the enemy
                {
                    score += 10;
                }
                if(j == 3)           // if it is in the column 'd'
                {
                    score += 50;
                }
                if(j < 3)            // if it is in the left half of the board
                {
                    score += 1;
                }
                else                 // if it is in the right half of the board
                {
                    score -= 1;
                }
            }
        }
    }
    return score;
}

void print_board() {
    int i,j;
    for(i=0;i<board_size;i++) {
        for(j=0;j<board_size;j++) {
            if(board[i][j] == -1) {
                printf(". ");
            }
            else {
                printf("%d ",board[i][j]);
            }
        }
        printf("\n");
    }
}

int is_move_possible(int x1,int y1,int x2,int y2,int color) {
    if(x1<0 || x1>=board_size || y1<0 || y1>=board_size || x2<0 || x2>=board_size ||y2<0 || y2>=board_size || (x1==x2 && y1==y2)){     // if not within the board or same position
        return 0;
    }
    if(color == 1)                        // if it is a white chess piece
    {
        if(board[x1][y1] != 1){
            return 0;
        }
        if(board[x2][y2] == 1){           // if there is a white chess piece in new position
            return 0;
        }
        if(x2+1 == x1 && (y1+1 == y2||y1-1 == y2) && board[x2][y2] == 0){   // if it is a move of taking the black chess piece
            return 1;
        }
        if(x2+1 == x1 && y1 == y2 && board[x2][y2] == 0){   // if it is a simple forward move
            return 1;
        }
    }
    else if(color == 2)                 // if it is a black chess piece
    {
        if(board[x1][y1] != 2){
            return 0;
        }
        if(board[x2][y2] == 2){          // if there is a black chess piece in new position
            return 0;
        }
        if(x1-1 == x2 && (y1+1 == y2 || y1-1 == y2) && board[x2][y2] == 0){  // if it is a move of taking the white chess piece
            return 1;
        }
        if(x1-1 == x2 && y1 == y2 && board[x2][y2] == 0){   //if it is a simple forward move
            return 1;
        }
    }
    return 0;
}

int is_game_finished() {
    
    int i,j,white_count = 0,black_count = 0;
    
    for(i=0;i<board_size;i++) {
        for(j=0;j<board_size;j++) {
            if(board[i][j] == 1) {     // if white chess piece exist in this position
                white_count++;
            }
            else if(board[i][j]==2) {  // if black chess piece exist in this position
                black_count++;
            }
        }
    }
    
    if(white_count==0 || black_count==0) {  // if there is no white or black chess piece exists
        if(evaluate_board() > 0) {  // if the white pieces have more score than black
            printf("Game Finished! White wins.");
        }
        else {
            printf("Game Finished! Black wins.");  // if the black pieces have more score than white
        }
        return 1;
    }
    return 0;
}

int main() {
    
    int i,j,x1,y1,x2,y2,color=1;

    while(!is_game_finished()) {  // loop until the game is not finished
        
        printf("colour %d\n",color);
        printf("Enter current position [x1 y1]: ");
        scanf("%d %d",&x1,&y1);
        
        if(board[x1][y1] == -1 || board[x1][y1] == 0 || (color==1 && board[x1][y1]!=1) || (color==2 && board[x1][y1]!=2)){ // if there is no chess piece or colour conflict
            printf("Invalid move. Please try again.\n");
            continue;
        }
        
        printf("Enter new position [x2 y2]: ");
        scanf("%d %d",&x2,&y2);
        
        if(!is_move_possible(x1,y1,x2,y2,color)){
            printf("Invalid move. Please try again.\n");
            continue;
        }
        
        if(color == 1) {
            board[x2][y2] = 1;
            board[x1][y1] = 0;
        }
        else if(color == 2){
            board[x2][y2] = 2;
            board[x1][y1] = 0;
        }
        
        print_board();
        
        color = (color==1)?2:1;   // changing the colour
    }
    
    return 0;
}