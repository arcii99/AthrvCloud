//FormAI DATASET v1.0 Category: Checkers Game ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

// Function to print the board
void print_board(char board[][8]){
    printf("--------------------------------\n");
    printf("|     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |\n");
    printf("--------------------------------\n");
    for(int i=0;i<8;i++){
        printf("|  %d  ",i+1);
        for(int j=0;j<8;j++){
            printf("| %c ",board[i][j]);
        }
        printf("| %d\n",i+1);
        printf("--------------------------------\n");
    }
    printf("|     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |\n");
    printf("--------------------------------\n");
}

// Function to initialize the board
void initialize_board(char board[][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i%2 != j%2){
                if(i<3){
                    board[i][j]='B';
                }
                else if(i>4){
                    board[i][j]='W';
                }
                else{
                    board[i][j]=' ';
                }
            }
            else{
                board[i][j]=' ';
            }
        }
    }
}

// Function to check if move made by the player is valid or not
int check_validity(char curr_player,char opp_player,char board[][8],int start_row,int start_col,int end_row,int end_col){

    // Checking if the move is valid for the King
    if(board[start_row][start_col] == 'K'){
        if(abs(start_row - end_row) == 1 && abs(start_col - end_col) == 1){
            if(board[end_row][end_col] == opp_player || board[end_row][end_col] == ' '){
                return 1;
            }
        }
    }
    // Checking if the move is valid for the Player
    else if(curr_player == 'W'){
        if(end_row - start_row == -1){
            if(abs(start_col-end_col) == 1){
                if(board[end_row][end_col] == opp_player){
                    return 1;
                }
            }
            else if(start_col-end_col == 0){
                if(board[end_row][end_col] == ' '){
                    return 1;
                }
            }
        }
        else if(end_row - start_row == -2 ){
                if(abs(start_col-end_col) == 2){
                    if(board[start_row-1][(start_col+end_col)/2] == opp_player && board[end_row][end_col] == ' '){
                        board[start_row-1][(start_col+end_col)/2] = ' ';
                        printf("Great! You have eaten your opponent's coin!\n");
                        return 1;
                    }
                }
        }
    }
    // Checking if the move is valid for the Opponent
    else{
        if(end_row - start_row == 1){
            if(abs(start_col-end_col) == 1){
                if(board[end_row][end_col] == opp_player){
                    return 1;
                }
            }
            else if(start_col-end_col == 0){
                if(board[end_row][end_col] == ' '){
                    return 1;
                }
            }
        }
        else if(end_row - start_row == 2 ){
                if(abs(start_col-end_col) == 2){
                    if(board[start_row+1][(start_col+end_col)/2] == opp_player && board[end_row][end_col] == ' '){
                        board[start_row+1][(start_col+end_col)/2] = ' ';
                        printf("Great! You have eaten your opponent's coin!\n");
                        return 1;
                    }
                }
        }
    }
    return 0;
}

// Function to make move on the board
void make_move(char curr_player,char opp_player,char board[][8],int start_row,int start_col,int end_row,int end_col){
    char temp = board[start_row][start_col];
    board[start_row][start_col] = ' ';
    board[end_row][end_col] = temp;
    if(curr_player == 'W' && end_row == 0){
        board[end_row][end_col] = 'K';
        printf("Congratulations! You have a king now!\n");
    }
    else if(curr_player == 'B' && end_row == 7){
        board[end_row][end_col] = 'K';
        printf("Congratulations! You have a king now!\n");
    }
}

// Function to check if the player can make any moves
int can_move(char curr_player,char opp_player,char board[][8]){
    int flag=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j] == curr_player || board[i][j] == curr_player+'K'){
                if(i>0){
                    if(j>0){
                        if(check_validity(curr_player,opp_player,board,i,j,i-1,j-1) == 1){
                            flag=1;
                        }
                    }
                    if(j<7){
                        if(check_validity(curr_player,opp_player,board,i,j,i-1,j+1) == 1){
                            flag=1;
                        }
                    }
                }
                if(board[i][j] == curr_player+'K'){
                    if(i<7){
                        if(j>0){
                            if(check_validity(curr_player,opp_player,board,i,j,i+1,j-1) == 1){
                                flag=1;
                            }
                        }
                        if(j<7){
                            if(check_validity(curr_player,opp_player,board,i,j,i+1,j+1) == 1){
                                flag=1;
                            }
                        }
                    }
                }
                if(i<7){
                    if(j>0){
                        if(check_validity(curr_player,opp_player,board,i,j,i+1,j-1) == 1){
                            flag=1;
                        }
                    }
                    if(j<7){
                        if(check_validity(curr_player,opp_player,board,i,j,i+1,j+1) == 1){
                            flag=1;
                        }
                    }
                }
            }
        }
    }
    return flag;
}

// Function to play the game
void play_game(char board[][8]){
    int curr_row,curr_col,end_row,end_col,flag,validity;
    char curr_player = 'W',opp_player = 'B';
    while(1){
        flag = can_move(curr_player,opp_player,board);
        if(flag == 0){
            printf("Oh no! You cannot move, opponent wins!\n");
            break;
        }
        printf("\nCurrent Board:\n");
        print_board(board);
        printf("%c Player's Turn: ",curr_player);
        printf("Enter Position of Coin You Want to Move (row col): ");
        scanf("%d %d",&curr_row,&curr_col);
        if(board[curr_row-1][curr_col-1] == curr_player || board[curr_row-1][curr_col-1] == curr_player+'K'){
            printf("Enter Position To Which You Want to Move The Coin (row col): ");
            scanf("%d %d",&end_row,&end_col);
            validity = check_validity(curr_player,opp_player,board,curr_row-1,curr_col-1,end_row-1,end_col-1);
            if(validity == 1){
                make_move(curr_player,opp_player,board,curr_row-1,curr_col-1,end_row-1,end_col-1);
                printf("Great Move!\n");
                if(curr_player == 'W'){
                    curr_player = 'B';
                    opp_player = 'W';
                }
                else{
                    curr_player = 'W';
                    opp_player = 'B';
                }
            }
            else{
                printf("Oh no! Invalid Move\n");
            }
        }
        else{
            printf("Oh no! Invalid Move\n");
        }
        int countW=0,countB=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j] == 'W' || board[i][j] == 'K'){
                    countW++;
                }
                if(board[i][j] == 'B' || board[i][j] == 'K'){
                    countB++;
                }
            }
        }
        if(countW == 0){
            printf("Oh no! Black Player Wins!\n");
            break;
        }
        else if(countB == 0){
            printf("Oh no! White Player Wins!\n");
            break;
        }
    }
    printf("\nFinal Board:\n");
    print_board(board);
}

// Main function to run the program
int main(){
    char board[8][8];
    initialize_board(board);
    printf("Welcome to the Checkers Game!\n");
    printf("White Pieces: W | Black Pieces: B | King Pieces: K\n");
    play_game(board);
    return 0;
}