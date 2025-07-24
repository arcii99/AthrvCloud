//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void gameBoard(char board[5][5]){
    for(int i=0;i<5;i++){
        printf("\n");
        for(int j=0;j<5;j++){
            printf("%c ",board[i][j]);
        }
    }
    printf("\n");
}
int main(){   
    printf("\n********************************************************************");
    printf("\n*         Welcome to Romeo and Juliet Space Invaders Game!           *");
    printf("\n********************************************************************");
    char board[5][5]={{'1','1','1','1','1'},
                      {'0','1','1','1','0'},
                      {'0','0','1','0','0'},
                      {'0','1','1','1','0'},
                      {'1','0','1','0','1'}};
    gameBoard(board);
    int score=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(board[i][j]=='1'){
                int random=rand()%2;
                usleep(100000);
                if(random==1){
                    board[i][j]='0';
                    score++;
                    system("clear");//For Unix/Linux systems only
                    printf("Romeo destroyed the enemy at (%d,%d) %c\nScore=%d\n",i,j,board[i][j],score);
                    gameBoard(board);
                }
                else{
                    system("clear");//For Unix/Linux systems only
                    printf("The enemy at (%d,%d) %c dodged Romeo's attack!\nScore=%d\n",i,j,board[i][j],score);
                    gameBoard(board);
                }
            }
            else{
                continue;
            }

        }
    }
    printf("Game Over!\nFinal Score=%d\n",score);
    
    return 0;
}