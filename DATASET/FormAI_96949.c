//FormAI DATASET v1.0 Category: Checkers Game ; Style: interoperable
#include<stdio.h>

/* Definition of the checkerboard */
#define BOARD_SIZE 8
char board[BOARD_SIZE][BOARD_SIZE];

/* Declaration of functions */
void initialize(); // Initializes the board with starting positions
void draw_board(); // Draws the checkerboard with current positions
int move(int from_x, int from_y, int to_x, int to_y); // Checks validity of move and moves piece
int check_winner(); // Checks for a winner

/* Main function */
int main(){
    int x1, y1, x2, y2;
    int player = 1;
    int status = -1;
    initialize();
    while(status==-1){
        draw_board();
        printf("\nPlayer %d's turn:",player);
        printf("\nEnter the current x and y coordinates of your piece:");
        scanf("%d %d",&x1,&y1);
        printf("\nEnter the destination x and y coordinates:");
        scanf("%d %d",&x2,&y2);
        status = move(x1,y1,x2,y2);
        if(status==1){
            printf("\n\nCongratulations! Player %d has won!",player);
            break;
        }
        player = player * -1;
    }
    draw_board();
    return 0;
}

/* Function Definitions */
void initialize(){
    int i,j;
    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            if((i+j)%2==0 && i<3){
                board[i][j] = '1';
            }
            else if((i+j)%2==0 && i>4){
                board[i][j] = '2';
            }
            else{
                board[i][j] = ' ';
            }
        }
    }
}

void draw_board(){
    int i,j;
    for(i=0;i<BOARD_SIZE;i++){
        printf("\n+---+---+---+---+---+---+---+---+");
        for(j=0;j<BOARD_SIZE;j++){
            printf("\n| %c ",board[i][j]);
        }
        printf("|\n");
    }
    printf("+---+---+---+---+---+---+---+---+\n");
}

int move(int from_x, int from_y, int to_x, int to_y){
    if(board[to_x][to_y]!=' '){
        printf("\nInvalid move! Destination already occupied!\n");
        return -1;
    }
    if(board[from_x][from_y]==' '){
        printf("\nInvalid move! No piece at source!\n");
        return -1;
    }
    if(from_x<0 || from_x>=BOARD_SIZE || from_y<0 || from_y>=BOARD_SIZE || to_x<0 || to_x>=BOARD_SIZE || to_y<0 || to_y>=BOARD_SIZE){
        printf("\nInvalid move! Out of board index!\n");
        return -1;
    }
    if(board[from_x][from_y] == '1'){
        if((to_x == from_x-1) && (to_y == from_y-1 || to_y == from_y+1)){
            board[to_x][to_y] = board[from_x][from_y];
            board[from_x][from_y] = ' ';
            if(to_x == 0){
                board[to_x][to_y] = 'K';
            }
            return check_winner();
        }
        else if((to_x == from_x-2) && (to_y == from_y-2 || to_y == from_y+2)){
            if(board[(from_x+to_x)/2][(from_y+to_y)/2] == '2'){
                board[to_x][to_y] = board[from_x][from_y];
                board[from_x][from_y] = ' ';
                board[(from_x+to_x)/2][(from_y+to_y)/2] = ' ';
                if(to_x == 0){
                    board[to_x][to_y] = 'K';
                }
                return check_winner();
            }
            else{
                printf("\nInvalid move! No enemy to jump over!\n");
                return -1;
            }
        }
        else{
            printf("\nInvalid move! Can only move diagonally by one or jump diagonally by two!\n");
            return -1;
        }
    }
    else if(board[from_x][from_y] == '2'){
        if((to_x == from_x+1) && (to_y == from_y-1 || to_y == from_y+1)){
            board[to_x][to_y] = board[from_x][from_y];
            board[from_x][from_y] = ' ';
            if(to_x == BOARD_SIZE-1){
                board[to_x][to_y] = 'K';
            }
            return check_winner();
        }
        else if((to_x == from_x+2) && (to_y == from_y-2 || to_y == from_y+2)){
            if(board[(from_x+to_x)/2][(from_y+to_y)/2] == '1'){
                board[to_x][to_y] = board[from_x][from_y];
                board[from_x][from_y] = ' ';
                board[(from_x+to_x)/2][(from_y+to_y)/2] = ' ';
                if(to_x == BOARD_SIZE-1){
                    board[to_x][to_y] = 'K';
                }
                return check_winner();
            }
            else{
                printf("\nInvalid move! No enemy to jump over!\n");
                return -1;
            }
        }
        else{
            printf("\nInvalid move! Can only move diagonally by one or jump diagonally by two!\n");
            return -1;
        }
    }
    else if(board[from_x][from_y] == 'K'){
        int dx = to_x - from_x;
        int dy = to_y - from_y;
        if((dx == dy || dx == -dy) && (dx>0 || dy>0)){
            int i;
            for(i=1;i<dx;i++){
                if(dx>0 && dy>0 && board[from_x+i][from_y+i]!=' '){
                    printf("\nInvalid move! Cannot pass through someone!\n");
                    return -1;
                }
                if(dx>0 && dy<0 && board[from_x+i][from_y-i]!=' '){
                    printf("\nInvalid move! Cannot pass through someone!\n");
                    return -1;
                }
                if(dx<0 && dy>0 && board[from_x-i][from_y+i]!=' '){
                    printf("\nInvalid move! Cannot pass through someone!\n");
                    return -1;
                }
                if(dx<0 && dy<0 && board[from_x-i][from_y-i]!=' '){
                    printf("\nInvalid move! Cannot pass through someone!\n");
                    return -1;
                }
            }
            if(board[to_x][to_y]!=' '){
                printf("\nInvalid move! Cannot jump over someone!\n");
                return -1;
            }
            else{
                board[to_x][to_y] = board[from_x][from_y];
                board[from_x][from_y] = ' ';
                return check_winner();
            }
        }
        else{
            printf("\nInvalid move! King can only move diagonally and any number of squares!\n");
            return -1;
        }
    }
}

int check_winner(){
    int i,j;
    int p1_count = 0, p2_count = 0;
    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            if(board[i][j] == '1' || board[i][j] == 'K'){
                p1_count++;
            }
            else if(board[i][j] == '2' || board[i][j] == 'k'){
                p2_count++;
            }
        }
    }
    if(p1_count == 0 || p2_count == 0){
        return 1;
    }
    else{
        return -1;
    }
}