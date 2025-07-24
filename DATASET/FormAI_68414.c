//FormAI DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#define ROWS 8
#define COLS 8

char board[ROWS][COLS] = {
    {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
    {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
    {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
    {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
    {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '}
};

void print_board(){
    int i,j;
    printf("  1 2 3 4 5 6 7 8\n");
    for (i=0;i<ROWS;i++){
        printf("%d",i+1);
        for (j=0;j<COLS;j++){
            printf("[%c]",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void move_piece(int current_pos[],int new_pos[]){
    board[new_pos[0]][new_pos[1]] = board[current_pos[0]][current_pos[1]];
    board[current_pos[0]][current_pos[1]] = ' ';
}

int is_possible(int current_pos[],int new_pos[]){
    if (new_pos[0]>7  || new_pos[1]>7 || new_pos[0]<0 || new_pos[1]<0){
        return 0;
    }
    if (board[new_pos[0]][new_pos[1]]!=' '){
        return 0;
    }
    if (current_pos[0]-new_pos[0]==1 || current_pos[0]-new_pos[0]==-1){
        //moving 1 row up or down
        if (current_pos[1]-new_pos[1]==1 || current_pos[1]-new_pos[1]==-1){
            //moving 1 column left or right
            return 1;
        }
    }
    return 0;
}

int is_valid_move(char piece,int current_pos[],int new_pos[]){
    //Checking if the move can be made by a regular piece
    if (piece=='O' && (new_pos[0]-current_pos[0])==1){
        //moving 1 row down
        if (current_pos[1]-new_pos[1]==1 || current_pos[1]-new_pos[1]==-1){
            //moving 1 column left or right
            return 1;
        }
    }
    if (piece=='X' && (new_pos[0]-current_pos[0])==-1){
        //moving 1 row up
        if (current_pos[1]-new_pos[1]==1 || current_pos[1]-new_pos[1]==-1){
            //moving 1 column left or right
            return 1;
        }
    }
    //checking if the move can be made by a king
    if (piece=='O' || piece=='X'){ //the piece is either kinged from previous move or starting board position.
        if ((new_pos[0]-current_pos[0])==1 || (new_pos[0]-current_pos[0])==-1){
            //moving 1 row up or down
            if (current_pos[1]-new_pos[1]==1 || current_pos[1]-new_pos[1]==-1){
                //moving 1 column left or right
                return 1;
            }
        }
    }
    return 0;
}

void input_pos(int current_pos[],int new_pos[]){
    printf("Enter current row position for the piece you want to move: ");
    scanf("%d",&current_pos[0]);
    printf("Enter current column position for the piece you want to move: ");
    scanf("%d",&current_pos[1]);
    printf("Enter new row position for the piece: ");
    scanf("%d",&new_pos[0]);
    printf("Enter new column position for the piece: ");
    scanf("%d",&new_pos[1]);
    printf("\n");
}

int check_win(){
    int i,j,count_o=0,count_x=0;
    for (i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if (board[i][j]=='O' || board[i][j]=='K'){
                count_o++;
            }
            if (board[i][j]=='X' || board[i][j]=='K'){
                count_x++;
            }
        }
    }
    if (count_o==0){
        printf("Congratulations player 'X', you won!\n");
        return 1;
    }
    if (count_x==0){
        printf("Congratulations player 'O', you won!\n");
        return 1;
    }
    return 0;
}

void king_piece(int new_pos[]){
    char piece = board[new_pos[0]][new_pos[1]];
    if (piece=='O' && new_pos[0]==7){
        board[new_pos[0]][new_pos[1]] = 'K';
    }
    if (piece=='X' && new_pos[0]==0){
        board[new_pos[0]][new_pos[1]] = 'K';
    }
}

int main(){
    int current_pos[2],new_pos[2],valid_move=0,win=0;
    char piece;
    print_board();
    while (!win){
        printf("Player 'O', enter move: \n");
        input_pos(current_pos,new_pos);
        piece = board[current_pos[0]][current_pos[1]];
        valid_move = is_valid_move(piece,current_pos,new_pos);
        if (valid_move){
            move_piece(current_pos,new_pos);
            king_piece(new_pos);
            print_board();
            win = check_win();
        }
        else{
            printf("Not a valid move, try again!\n");
        }   
    }
    return 0;
}