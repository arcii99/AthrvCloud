//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3]; //game board
int player; //current player, 0 or 1

void init(){  //function to initialise the game board with empty spaces
    
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
}

void draw(){ //function to draw the game board
    
    int i;
    printf("\n\n     Tic Tac Toe\n\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n", board[0][0], board[0][1], board[0][2]);
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n", board[1][0], board[1][1], board[1][2]);
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n", board[2][0], board[2][1], board[2][2]);
    printf("       |       |       \n\n");
}

int check_win(){  //function to check if there is a winner
    
    if(board[0][0]!= ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return 1;
    else if(board[1][0]!= ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return 1;
    else if(board[2][0]!= ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return 1;
    else if(board[0][0]!= ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return 1;
    else if(board[0][1]!= ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return 1;
    else if(board[0][2]!= ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return 1;
    else if(board[0][0]!= ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    else if(board[0][2]!= ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    else if(board[0][0] !=' ' && board[0][1] !=' ' && board[0][2] !=' ' && board[1][0] !=' ' && board[1][1] !=' ' && board[1][2] !=' ' && board[2][0] !=' ' && board[2][1] !=' ' && board[2][2] !=' ')
        return -1;
    else
        return 0;

}


int minimax(int depth, int ismax){ //function implementing the minimax algorithm

    int score= check_win();
    if (score == 1) return score-depth;
    if (score == -1) return 0;
    if (score == 0 && depth == 8) return 0;

    int i, j;
    int bestscore;
    if(ismax){
        bestscore = -1000;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(board[i][j] == ' '){
                    board[i][j] = 'X';
                    bestscore = (bestscore > minimax(depth+1, !ismax))? bestscore:minimax(depth+1, !ismax);
                    board[i][j] = ' ';
                }
            }
        }
    }
    else{
        bestscore = 1000;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(board[i][j] == ' '){
                    board[i][j] = 'O';
                    bestscore = (bestscore < minimax(depth+1, !ismax))? bestscore:minimax(depth+1, !ismax);
                    board[i][j] = ' ';
                }
            }
        }
    }
    return bestscore;
}

void computer_turn(){  //function for the computer's turn, using the minimax algorithm

    int bestmovei=-1, bestmovej=-1, bestscore= -1000;
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[i][j] == ' '){
                board[i][j] = 'X';
                int score= minimax(0,0);
                board[i][j] = ' ';
                if(score>bestscore){
                    bestscore = score;
                    bestmovei = i;
                    bestmovej = j;
                }
            }
        }
    }
    board[bestmovei][bestmovej] = 'X';
}

void player_turn(){ //function for the player's turn
    
    int x, y;
    do{
        printf("Enter row and column: ");
        scanf("%d%d", &x, &y);
        x--;y--;
    }while(board[x][y] != ' ');
    board[x][y] = 'O';
}

int main(){

    int turn;
    init();
    srand(time(NULL));
    printf("Who will go first? Enter 0 for player and 1 for computer: ");
    scanf("%d", &turn);
    draw();
    while(check_win() == 0){
        if((turn==0 && check_win()==0) || (turn==1 && check_win()==0)){
            player_turn();
            draw();
            turn=1;
        }
        if((turn==1 && check_win()==0) || (turn==0 && check_win()==0)){
            printf("Computer's turn.\n");
            computer_turn();
            draw();
            turn=0;
        }
    }
    if(check_win()==1 && turn==0){
        printf("\nComputer wins!\n");
    }
    else if(check_win()==1 && turn==1){
        printf("\nPlayer wins!\n");
    }
    else{
        printf("\nDraw!\n");
    }

    return 0;
}