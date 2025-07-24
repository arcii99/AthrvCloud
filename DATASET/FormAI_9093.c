//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int board[3][3];

void print_board()
{
    printf("   1  2  3\n");
    for(int i=0;i<3;i++){
        printf("%d ",i+1);
        for(int j=0;j<3;j++){
            if(board[i][j]==-1){
                printf(" _ ");
            }else if(board[i][j]==0){
                printf(" O ");
            }else if(board[i][j]==1){
                printf(" X ");
            }
        }
        printf("\n");
    }
}

int check_win(){
    //check rows
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=-1){
            return board[i][0];
        }
    }

    //check columns
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=-1){
            return board[0][i];
        }
    }

    //check diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=-1){
        return board[0][0];
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=-1){
        return board[0][2];
    }

    //check draw
    int draw_flag=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==-1){
                draw_flag=0;
            }
         }
    }
    if(draw_flag==1){
        return 2;
    }

    return -1;
}

int get_valid_move(){
    int x,y;
    while(1){
        printf("Enter your move (row,col): ");
        scanf("%d,%d",&x,&y);
        x-=1;
        y-=1;
        if(x<0 || x>2 || y<0 || y>2){
            printf("Invalid input. Try again.\n");
        }else if(board[x][y]!=-1){
            printf("That spot is already taken. Try again.\n");
        }else{
            break;
        }
    }
    return x*3+y;
}

int get_ai_move(int player)
{
    int best_score=-2;
    int best_move=-1;

    for(int i=0;i<9;i++){
        if(board[i/3][i%3]==-1){
            board[i/3][i%3]=player;
            int score=minimax(1-player);
            board[i/3][i%3]=-1;
            if(score>best_score){
                best_score=score;
                best_move=i;
            }
        }
    }
    return best_move;
}

int minimax(int player)
{
    int winner=check_win();
    if(winner!=-1){
        if(winner==2){
            return 0;
        }else if(winner==player){
            return 1;
        }else{
            return -1;
        }
    }

    int best_score=-2;
    for(int i=0;i<9;i++){
        if(board[i/3][i%3]==-1){
            board[i/3][i%3]=player;
            int score=minimax(1-player);
            board[i/3][i%3]=-1;
            if(score>best_score){
                best_score=score;
            }
        }
    }
    if(best_score==-2){
        return 0;
    }
    return -best_score;
}

int main(void) {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=-1;
        }
    }
    printf("Welcome to Tic Tac Toe!\n");
    print_board();
    int player=0;

    while(check_win()==-1){
        if(player==0){
            int move=get_valid_move();
            board[move/3][move%3]=0;
            player=1;
        }else{
            int move=get_ai_move(1);
            printf("The AI played at %d,%d.\n",(move/3)+1,(move%3)+1);
            board[move/3][move%3]=1;
            player=0;
        }
        print_board();
    }

    int winner=check_win();
    if(winner==0){
        printf("You won!\n");
    }else if(winner==1){
        printf("The AI won!\n");
    }else{
        printf("It's a draw!\n");
    }
    return 0;
}