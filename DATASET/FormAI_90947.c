//FormAI DATASET v1.0 Category: Checkers Game ; Style: thoughtful
#include<stdio.h>
#include<string.h>

#define size 8

char board[size][size]; //8x8 checker board
int turn = 0; //player1=0, player2=1
int turn_count = 0; //counting turns

void init_board();
void print_board();
int move_checker(int x1, int y1, int x2, int y2, int player_turn);
int check_jump(int x1, int y1, int x2, int y2, int player_turn);
int check_win();
void play_game();

int main(){
    init_board();
    play_game();
    return 0;
}

void init_board(){
    memset(board,'-',sizeof(board));
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if( (i+j)%2 == 1 && i<size/2-1 ) board[i][j]='X'; //player1 checkers
            if( (i+j)%2 == 1 && i>size/2 ) board[i][j]='O'; //player2 checkers
        }
    }
}

void print_board(){
    printf("    0 1 2 3 4 5 6 7\n");
    for(int i=0; i<size; i++){
        printf("%d | ", i);
        for(int j=0; j<size; j++){
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
}

//returns 1 if move is valid, otherwise 0.
int move_checker(int x1, int y1, int x2, int y2, int player_turn){
    if( x1<0 || x1>=size || y1<0 || y1>=size || x2<0 || x2>=size || y2<0 || y2>=size ) return 0; //check if indexes are out of range
    if( board[x1][y1]=='-' || board[x2][y2]!='-' ) return 0; //check if starting point has checker and destination is empty square
    if( (x1+y1)%2 != 1 || (x2+y2)%2 != 1 ) return 0; //check if the move is valid according to the checker board pattern
    if( player_turn==0 && board[x1][y1]!='X' ) return 0; //check if it is player1's turn and the checker belongs to player1
    if( player_turn==1 && board[x1][y1]!='O' ) return 0; //check if it is player2's turn and the checker belongs to player2

    //normal move for player1 checkers
    if( board[x1][y1]=='X' && x2==x1+1 && (y2==y1+1 || y2==y1-1) ) {
        board[x1][y1] = '-';
        board[x2][y2] = 'X';
        return 1;
    }
    //normal move for player2 checkers
    if( board[x1][y1]=='O' && x2==x1-1 && (y2==y1+1 || y2==y1-1) ) {
        board[x1][y1] = '-';
        board[x2][y2] = 'O';
        return 1;
    }
    //jump move for player1 checkers
    if( board[x1][y1]=='X' && x2==x1+2 && (y2==y1+2 || y2==y1-2) && board[(x1+x2)/2][(y1+y2)/2]=='O' ) {
        board[x1][y1] = '-';
        board[x2][y2] = 'X';
        board[(x1+x2)/2][(y1+y2)/2] = '-';
        return 1;
    }
    //jump move for player2 checkers
    if( board[x1][y1]=='O' && x2==x1-2 && (y2==y1+2 || y2==y1-2) && board[(x1+x2)/2][(y1+y2)/2]=='X' ) {
        board[x1][y1] = '-';
        board[x2][y2] = 'O';
        board[(x1+x2)/2][(y1+y2)/2] = '-';
        return 1;
    }

    return 0;
}

//returns 1 if jump is possible, otherwise 0
int check_jump(int x1, int y1, int x2, int y2, int player_turn){
    if( x1<0 || x1>=size || y1<0 || y1>=size || x2<0 || x2>=size || y2<0 || y2>=size ) return 0; //check if indexes are out of range
    if( board[x1][y1]=='-' || board[x2][y2]!='-' ) return 0; //check if starting point has checker and destination is empty square
    if( (x1+y1)%2 != 1 || (x2+y2)%2 != 1 ) return 0; //check if the move is valid according to the checker board pattern
    if( player_turn==0 && board[x1][y1]!='X' ) return 0; //check if it is player1's turn and the checker belongs to player1
    if( player_turn==1 && board[x1][y1]!='O' ) return 0; //check if it is player2's turn and the checker belongs to player2

    //jump move for player1 checkers
    if( board[x1][y1]=='X' && x2==x1+2 && (y2==y1+2 || y2==y1-2) && board[(x1+x2)/2][(y1+y2)/2]=='O' ) {
        return 1;
    }
    //jump move for player2 checkers
    if( board[x1][y1]=='O' && x2==x1-2 && (y2==y1+2 || y2==y1-2) && board[(x1+x2)/2][(y1+y2)/2]=='X' ) {
        return 1;
    }

    return 0;
}

//returns 1 if a player has won, otherwise 0
int check_win(){
    int count_X=0, count_O=0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if( board[i][j]=='X' || board[i][j]=='K' ) count_X++;
            if( board[i][j]=='O' || board[i][j]=='Q' ) count_O++;
        }
    }
    if( count_X==0 ) return 2;
    if( count_O==0 ) return 1;
    return 0;
}

void play_game(){
    int x1, y1, x2, y2, valid_move;
    while(1){
        printf("\n");
        print_board();
        if( turn==0 ) printf("\nPlayer 1 (X) turn.\n");
        else printf("\nPlayer 2 (O) turn.\n");
        printf("Enter starting point (x, y): ");
        scanf("%d%d", &x1, &y1);
        printf("Enter destination point (x, y): ");
        scanf("%d%d", &x2, &y2);
        valid_move = move_checker(x1, y1, x2, y2, turn);
        if( valid_move ){
            turn_count++;
            if( check_jump(x2, y2, x2+2, y2+2, turn) || check_jump(x2, y2, x2+2, y2-2, turn) ||
                check_jump(x2, y2, x2-2, y2+2, turn) || check_jump(x2, y2, x2-2, y2-2, turn) ){
                printf("\nJump Available. \n");
            } else {
                turn ^= 1; //toggle the turn
            }
        } else {
            printf("\nInvalid Move. Try Again. \n");
        }
        int winner = check_win();
        if( winner ){
            printf("\n");
            print_board();
            switch(winner){
                case 1: printf("\nPlayer 1 (X) Wins! \n"); break;
                case 2: printf("\nPlayer 2 (O) Wins! \n"); break;
            }
            printf("Total Turns: %d \n", turn_count);
            break;
        }
    }
}