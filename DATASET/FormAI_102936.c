//FormAI DATASET v1.0 Category: Chess AI ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

char current_board[BOARD_SIZE][BOARD_SIZE];

// Function for displaying current_board
void display_board(){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            printf("%c ",current_board[i][j]);
        }
        printf("\n");
    }
}

//Initial setup of chess board
void initialize_board(){
    current_board[0][0] = 'R';
    current_board[0][1] = 'N';
    current_board[0][2] = 'B';
    current_board[0][3] = 'Q';
    current_board[0][4] = 'K';
    current_board[0][5] = 'B';
    current_board[0][6] = 'N';
    current_board[0][7] = 'R';
    for(int i=0;i<BOARD_SIZE;i++){
        current_board[1][i] = 'P';
        current_board[6][i] = 'p';
    }
    current_board[7][0] = 'r';
    current_board[7][1] = 'n';
    current_board[7][2] = 'b';
    current_board[7][3] = 'q';
    current_board[7][4] = 'k';
    current_board[7][5] = 'b';
    current_board[7][6] = 'n';
    current_board[7][7] = 'r';
}

// Function for checking if move is valid or not
int is_valid_move(int x1, int y1, int x2, int y2, char player){
    char original_piece = current_board[x1][y1];
    char dest_piece = current_board[x2][y2];
    
    // If same space or invalid move
    if (x1 == x2 && y1 == y2 || x1 >= BOARD_SIZE || y1 >= BOARD_SIZE || x2 >= BOARD_SIZE || y2 >= BOARD_SIZE)
        return 0;
    
    // If destination has player's own piece
    if (dest_piece != '-' && dest_piece < 'a')
        return 0;

    // Moving black piece in white's turn or vice-versa
    if ((player == 'w' && original_piece >= 'a') || (player == 'b' && original_piece < 'a'))
        return 0;

    // Move logic depending on piece
    switch (original_piece) {
        case 'P':
        case 'p': {
            if (original_piece == 'P') {
                if ((y2 - y1 == 1 && x1 - x2 == 1) || (y2 - y1 == -1 && x1 - x2 == 1)) {
                    if (dest_piece != '-')
                        return 0;
                }
                else if (y2 - y1 == 0 && x1 - x2 == 1) {
                    if (dest_piece != '-')
                        return 0;
                }
                else if (y2 - y1 == 0 && x1 - x2 == 2) {
                    if (dest_piece != '-')
                        return 0;
                }
                else
                    return 0;
            }
            else {
                if ((y2 - y1 == 1 && x2 - x1 == 1) || (y2 - y1 == -1 && x2 - x1 == 1)) {
                    if (dest_piece != '-')
                        return 0;
                }
                else if (y2 - y1 == 0 && x2 - x1 == 1) {
                    if (dest_piece != '-')
                        return 0;
                }
                else if (y2 - y1 == 0 && x2 - x1 == 2) {
                    if (dest_piece != '-')
                        return 0;
                }
                else
                    return 0;
            }
            break;
        }
        case 'R':
        case 'r': {
            if (x1 != x2 && y1 != y2)
                return 0;
            if (x1 > x2) {
                for (int i = x1 - 1; i >= x2; --i) {
                    if (current_board[i][y1] != '-' && i != x2)
                        return 0;
                }
            } else if (x2 > x1) {
                for (int i = x1 + 1; i <= x2; ++i) {
                    if (current_board[i][y1] != '-' && i != x2)
                        return 0;
                }
            } else if (y1 > y2) {
                for (int i = y1 - 1; i >= y2; --i) {
                    if (current_board[x1][i] != '-' && i != y2)
                        return 0;
                }
            } else {
                for (int i = y1 + 1; i <= y2; ++i) {
                    if (current_board[x1][i] != '-' && i != y2)
                        return 0;
                }
            }
            break;
        }
        case 'N':
        case 'n': {
            if (!((x1 - x2 == 1 && y1 - y2 == 2) || (x1 - x2 == 2 && y1 - y2 == 1) ||
                  (x1 - x2 == -1 && y1 - y2 == 2) || (x1 - x2 == -2 && y1 - y2 == 1) ||
                  (x1 - x2 == 1 && y1 - y2 == -2) || (x1 - x2 == 2 && y1 - y2 == -1) ||
                  (x1 - x2 == -1 && y1 - y2 == -2) || (x1 - x2 == -2 && y1 - y2 == -1)))
                return 0;
            break;
        }
        case 'B':
        case 'b': {
            if (abs(x1 - x2) != abs(y1 - y2))
                return 0;
            int xdir, ydir;
            if (x1 > x2)
                xdir = -1;
            else
                xdir = 1;
            if (y1 > y2)
                ydir = -1;
            else
                ydir = 1;
            int i = x1 + xdir, j = y1 + ydir;
            while (i != x2 && j != y2) {
                if (current_board[i][j] != '-')
                    return 0;
                i = i + xdir;
                j = j + ydir;
            }
            break;
        }
        case 'Q':
        case 'q': {
            if (x1 != x2 && y1 != y2) {
                if (abs(x1 - x2) != abs(y1 - y2))
                    return 0;
                int xdir, ydir;
                if (x1 > x2)
                    xdir = -1;
                else
                    xdir = 1;
                if (y1 > y2)
                    ydir = -1;
                else
                    ydir = 1;
                int i = x1 + xdir, j = y1 + ydir;
                while (i != x2 && j != y2) {
                    if (current_board[i][j] != '-')
                        return 0;
                    i = i + xdir;
                    j = j + ydir;
                }
            } else {
                if (x1 != x2 && y1 != y2)
                    return 0;
                if (x1 > x2) {
                    for (int i = x1 - 1; i >= x2; --i) {
                        if (current_board[i][y1] != '-' && i != x2)
                            return 0;
                    }
                } else if (x2 > x1) {
                    for (int i = x1 + 1; i <= x2; ++i) {
                        if (current_board[i][y1] != '-' && i != x2)
                            return 0;
                    }
                } else if (y1 > y2) {
                    for (int i = y1 - 1; i >= y2; --i) {
                        if (current_board[x1][i] != '-' && i != y2)
                            return 0;
                    }
                } else {
                    for (int i = y1 + 1; i <= y2; ++i) {
                        if (current_board[x1][i] != '-' && i != y2)
                            return 0;
                    }
                }
            }
            break;
        }
        case 'K':
        case 'k': {
            if (abs(x1 - x2) > 1 || abs(y1 - y2) > 1)
                return 0;
            break;
        }
        default:
            return 0;
    }
    return 1;
}

// Function for computer move
void computer_move(){
    int best_score=0;
    int best_move[4];
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            for(int k=0;k<BOARD_SIZE;k++){
                for(int l=0;l<BOARD_SIZE;l++){
                    if(is_valid_move(i,j,k,l,'b')){
                        //Simulating move and scoring the move
                        char temp_dest=current_board[k][l];
                        current_board[k][l]=current_board[i][j];
                        current_board[i][j]='-';
                        int temp_score=0;
                        for(int m=0;m<BOARD_SIZE;m++){
                            for(int n=0;n<BOARD_SIZE;n++){
                                if(current_board[m][n]>='a' && current_board[m][n]<='z'){
                                    temp_score++;
                                }
                                else if(current_board[m][n]>='A' && current_board[m][n]<='Z'){
                                    temp_score--;
                                }
                            }
                        }
                        if(temp_score>best_score){
                            best_score=temp_score;
                            best_move[0]=i;
                            best_move[1]=j;
                            best_move[2]=k;
                            best_move[3]=l;
                        }
                        //Undoing the move
                        current_board[i][j]=current_board[k][l];
                        current_board[k][l]=temp_dest;
                    }
                }
            }
        }
    }
    current_board[best_move[2]][best_move[3]]=current_board[best_move[0]][best_move[1]];
    current_board[best_move[0]][best_move[1]]='-';
}

int main(){
    initialize_board();
    printf("Game starting!!\n");
    int user_turn=1;
    int x1,y1,x2,y2;
    while(1){
        display_board();
        if(user_turn==1){
            printf("Your turn\n");
            printf("Enter source coordinates (x y): ");
            scanf("%d %d",&x1,&y1);
            printf("Enter destination coordinates (x y): ");
            scanf("%d %d",&x2,&y2);
            if(is_valid_move(x1,y1,x2,y2,'w')){
                current_board[x2][y2]=current_board[x1][y1];
                current_board[x1][y1]='-';
                user_turn=0;
            }
            else{
                printf("Invalid move. Try again.\n");
            }
        }
        else{
            printf("Computer's turn\n");
            computer_move();
            user_turn=1;
        }
    }
    return 0;
}