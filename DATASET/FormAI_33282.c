//FormAI DATASET v1.0 Category: Checkers Game ; Style: retro
#include<stdio.h>

char board[8][8] = {
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '},
    {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
    {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '}
};

void print_board(){
    for(int i=0;i<8;++i){
        printf("\n\n");
        for(int j=0;j<8;++j){
            printf("%c\t", board[i][j]);
        }
    }
    printf("\n");
}

int check_move(int fs_i, int fs_j, int ts_i, int ts_j){
    if(board[fs_i][fs_j]==' '){
        printf("\nInvalid Move: No Piece Found in the Starting Position!");
        return 0;
    }
    if(board[ts_i][ts_j]!=' '){
        printf("\nInvalid Move: Destination Position Already Occupied!");
        return 0;
    }
    if(((fs_j-ts_j==2) || (fs_j-ts_j==-2)) && (fs_i-ts_i==2)){
        int x=(fs_i+ts_i)/2;
        int y=(fs_j+ts_j)/2;
        if(board[x][y]=='b'){
            return 1;
        }
        printf("\nInvalid Move: Jump Possible but No Piece Found to Jump!");
        return 0;
    }
    else if(((fs_j-ts_j==2) || (fs_j-ts_j==-2)) && (ts_i-fs_i==2)){
        int x=(fs_i+ts_i)/2;
        int y=(fs_j+ts_j)/2;
        if(board[x][y]=='w'){
            return 1;
        }
        printf("\nInvalid Move: Jump Possible but No Piece Found to Jump!");
        return 0;
    }
    else if((fs_j-ts_j==1) || (fs_j-ts_j==-1)){
        if((board[fs_i][fs_j]=='w') && (fs_i-ts_i==1)){
            return 1;
        }
        else if((board[fs_i][fs_j]=='b') && (ts_i-fs_i==1)){
            return 1;
        }
        printf("\nInvalid Move: Regular Move Not Possible!");
        return 0;
    }
    printf("\nInvalid Move: Unknown Error!");
    return 0;
}

int check_dx(int fs_i, int fs_j, int ts_i, int ts_j){
    int dx=fs_i-ts_i;
    if(dx<0) dx*=-1;
    int dy=fs_j-ts_j;
    if(dy<0) dy*=-1;
    if(dx==dy) return 1;
    return 0;
}

int check_turn(int fs_i, int fs_j, int ts_i, int ts_j, char player){
    if(player=='b'){
        if(board[fs_i][fs_j]!='b'){
            printf("\nInvalid Move: Black Player's Turn to Move!");
            return 0;
        }
        else if(check_dx(fs_i, fs_j, ts_i, ts_j)==0){
            printf("\nInvalid Move: Bishop Can Only Move Diagonally!");
            return 0;
        }
        else if(check_move(fs_i, fs_j, ts_i, ts_j)==0){
            return 0;
        }
        return 1;
    }
    else if(player=='w'){
        if(board[fs_i][fs_j]!='w'){
            printf("\nInvalid Move: White Player's Turn to Move!");
            return 0;
        }
        else if(check_dx(fs_i, fs_j, ts_i, ts_j)==0){
            printf("\nInvalid Move: Bishop Can Only Move Diagonally!");
            return 0;
        }
        else if(check_move(fs_i, fs_j, ts_i, ts_j)==0){
            return 0;
        }
        return 1;
    }
    printf("\nInvalid Move: Unknown Error!");
    return 0;
}

void move_pieces(int fs_i, int fs_j, int ts_i, int ts_j){
    board[fs_i][fs_j]=' ';
    if((fs_j-ts_j==2) && (fs_i-ts_i==2)){
        int x=(fs_i+ts_i)/2;
        int y=(fs_j+ts_j)/2;
        board[x][y]=' ';
    }
    else if((fs_j-ts_j==-2) && (fs_i-ts_i==2)){
        int x=(fs_i+ts_i)/2;
        int y=(fs_j+ts_j)/2;
        board[x][y]=' ';
    }
    else if((fs_j-ts_j==2) && (ts_i-fs_i==2)){
        int x=(fs_i+ts_i)/2;
        int y=(fs_j+ts_j)/2;
        board[x][y]=' ';
    }
    else if((fs_j-ts_j==-2) && (ts_i-fs_i==2)){
        int x=(fs_i+ts_i)/2;
        int y=(fs_j+ts_j)/2;
        board[x][y]=' ';
    }
    board[ts_i][ts_j]=board[fs_i][fs_j];
}

void play_game(){
    int game_over=0;
    int moves=0;
    printf("\n\nWELCOME TO RETRO C CHECKERS GAME!\n\n");
    printf("RULES:\n1. Bishops can only move diagonally.\n2. Bishops can move any number of steps diagonally.\n3. If a jump is possible, it must be made.\n\n");
    printf("\n\nSTARTING BOARD:\n\n");
    print_board();
    while(game_over==0){
        if((moves%2)==0){
            printf("\nBlack Player's Move: ");
            int fs_i,fs_j,ts_i,ts_j;
            scanf("%d %d %d %d", &fs_i,&fs_j,&ts_i,&ts_j);
            if(check_turn(fs_i,fs_j,ts_i,ts_j,'b')==0){
                continue;
            }
            move_pieces(fs_i,fs_j,ts_i,ts_j);
            printf("\nNEW BOARD:\n\n");
            print_board();
            moves++;
        }
        else{
            printf("\nWhite Player's Move: ");
            int fs_i,fs_j,ts_i,ts_j;
            scanf("%d %d %d %d", &fs_i,&fs_j,&ts_i,&ts_j);
            if(check_turn(fs_i,fs_j,ts_i,ts_j,'w')==0){
                continue;
            }
            move_pieces(fs_i,fs_j,ts_i,ts_j);
            printf("\nNEW BOARD:\n\n");
            print_board();
            moves++;
        }
    }
}

int main(){
    play_game();
    return 0;
}