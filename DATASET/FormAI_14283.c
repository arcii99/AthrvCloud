//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include<stdio.h>

//constants
#define SIZE 8

//function to print the board
void print_board(char board[][SIZE]){
    printf("   0 1 2 3 4 5 6 7\n");
    for(int i=0;i<SIZE;i++){
        printf("%d  ",i);
        for(int j=0;j<SIZE;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

//function to initialize the board
void initialize_board(char board[][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if((i+j)%2==0){
                if(i<3){
                    board[i][j]='B';
                }else if(i>4){
                    board[i][j]='W';
                }else{
                    board[i][j]=' ';
                }
            }else{
                board[i][j]=' ';
            }
        }
    }
}

//function to check if a move is valid or not
int is_valid_move(char board[][SIZE],int curr_pos_x,int curr_pos_y,int new_pos_x,int new_pos_y,char player){
    if(new_pos_x<0 || new_pos_x>=SIZE || new_pos_y<0 || new_pos_y>=SIZE){
        return 0;
    }
    if(board[new_pos_x][new_pos_y]!=' '){
        return 0;
    }
    if(player=='W'){
        if(curr_pos_x-new_pos_x!=1 && curr_pos_x-new_pos_x!=-1){
            return 0;
        }
        if(curr_pos_y-new_pos_y!=1 && curr_pos_y-new_pos_y!=-1){
            return 0;
        }
        if(curr_pos_x-new_pos_x==1 && board[curr_pos_x-1][curr_pos_y]!='B'){
            return 0;
        }
        if(curr_pos_x-new_pos_x==-1 && board[curr_pos_x+1][curr_pos_y]!='B'){
            return 0;
        }
    }else{
        if(curr_pos_x-new_pos_x!=1 && curr_pos_x-new_pos_x!=-1){
            return 0;
        }
        if(curr_pos_y-new_pos_y!=1 && curr_pos_y-new_pos_y!=-1){
            return 0;
        }
        if(curr_pos_x-new_pos_x==1 && board[curr_pos_x-1][curr_pos_y]!='W'){
            return 0;
        }
        if(curr_pos_x-new_pos_x==-1 && board[curr_pos_x+1][curr_pos_y]!='W'){
            return 0;
        }
    }
    return 1;
}

//function to make a move
void make_move(char board[][SIZE],int curr_pos_x,int curr_pos_y,int new_pos_x,int new_pos_y){
    char player = board[curr_pos_x][curr_pos_y];
    board[curr_pos_x][curr_pos_y]=' ';
    board[new_pos_x][new_pos_y]=player;
}

//function to perform a capture move
void capture_move(char board[][SIZE],int curr_pos_x,int curr_pos_y,int new_pos_x,int new_pos_y){
    char player = board[curr_pos_x][curr_pos_y];
    board[curr_pos_x][curr_pos_y]=' ';
    board[new_pos_x][new_pos_y]=player;
    if(new_pos_x-curr_pos_x==-2){
        board[curr_pos_x-1][curr_pos_y-1]=' ';
    }else if(new_pos_x-curr_pos_x==2){
        board[curr_pos_x+1][curr_pos_y-1]=' ';
    }else if(new_pos_x-curr_pos_x==-2){
        board[curr_pos_x-1][curr_pos_y+1]=' ';
    }else if(new_pos_x-curr_pos_x==2){
        board[curr_pos_x+1][curr_pos_y+1]=' ';
    }
}

int main(){

    //initialize the board
    char board[SIZE][SIZE];
    initialize_board(board);

    int game_over = 0; //flag variable to track end of game
    char curr_player = 'W'; //initialize player to White

    while(!game_over){
        print_board(board); //print the current state of the board
        int curr_pos_x,curr_pos_y,new_pos_x,new_pos_y;
        printf("Enter move for player %c\n",curr_player);
        printf("Enter current position (x,y): ");
        scanf("%d %d",&curr_pos_x,&curr_pos_y);
        printf("Enter new position (x,y): ");
        scanf("%d %d",&new_pos_x,&new_pos_y);
        if(is_valid_move(board,curr_pos_x,curr_pos_y,new_pos_x,new_pos_y,curr_player)){
            if((curr_pos_x-new_pos_x==2 || curr_pos_x-new_pos_x==-2) && (curr_pos_y-new_pos_y==2 || curr_pos_y-new_pos_y==-2)){
                capture_move(board,curr_pos_x,curr_pos_y,new_pos_x,new_pos_y); //perform capture move if required
            }else{
                make_move(board,curr_pos_x,curr_pos_y,new_pos_x,new_pos_y); //perform regular move
            }
            //check if the game has ended
            int w_count=0,b_count=0;
            for(int i=0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    if(board[i][j]=='W' || board[i][j]=='Q'){
                        w_count++;
                    }else if(board[i][j]=='B' || board[i][j]=='K'){
                        b_count++;
                    }
                }
            }
            if(w_count==0 || b_count==0){
                game_over = 1;
                printf("Game Over\n");
                if(w_count>b_count){
                    printf("White Wins\n");
                }else{
                    printf("Black Wins\n");
                }
            }
            //change the current player
            if(curr_player=='W'){
                curr_player='B';
            }else{
                curr_player='W';
            }
        }else{
            printf("Invalid move! Try again.\n");
        }
    }

    return 0;
}