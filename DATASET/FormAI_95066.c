//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define HEIGHT 20
#define WIDTH 30

void drawBoard(char board[HEIGHT][WIDTH], int playerY, int computerY){
    int i, j;
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            if(j==0 || j==WIDTH-1){
                board[i][j] = '|';
            }
            else if(i==playerY){
                board[i][j] = '-';
            }
            else if(i==computerY){
                board[i][j] = '=';
            }
            else{
                board[i][j] = ' ';
            }
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void movePlayerUp(int *playerY){
    if(*playerY>1){
        (*playerY)--;
    }
}

void movePlayerDown(int *playerY){
    if(*playerY<HEIGHT-2){
        (*playerY)++;
    }
}

void moveComputer(char board[HEIGHT][WIDTH], int *computerY, int ballY){
    if(*computerY < ballY-1 && *computerY<HEIGHT-2){
        (*computerY)++;
    }
    else if(*computerY > ballY+1 && *computerY>1){
        (*computerY)--;
    }
}

void moveBall(char board[HEIGHT][WIDTH], int *ballX, int *ballY, int *ballDX, int *ballDY, int *playerY, int *computerY, int *playerScore, int *computerScore){
    board[*ballY][*ballX] = ' ';

    if(*ballY==0 || *ballY==HEIGHT-1){
        *ballDY = -(*ballDY);
    }
    if(*ballX==1){
        if(*ballY>=*playerY && *ballY<=*playerY+2){
            *ballDX=1;
        }
        else{
            *computerScore += 1;
            *ballX = WIDTH/2;
            *ballY = HEIGHT/2;
            *ballDY = (rand()%3)-1;
            *ballDX = (rand()%2)?1:-1;
            *playerY = HEIGHT/2-1;
            *computerY = HEIGHT/2-1;
            printf("\n\nComputer Scored!!\n\n");
        }
    }
    if(*ballX==WIDTH-2){
        if(*ballY>=*computerY && *ballY<=*computerY+2){
            *ballDX=-1;
        }
        else{
            *playerScore += 1;
            *ballX = WIDTH/2;
            *ballY = HEIGHT/2;
            *ballDY = (rand()%3)-1;
            *ballDX = (rand()%2)?1:-1;
            *playerY = HEIGHT/2-1;
            *computerY = HEIGHT/2-1;
            printf("\n\nPlayer Scored!!\n\n");
        }
    }
    if(board[*ballY+(*ballDY)][*ballX+(*ballDX)] != ' '){
        *ballDX = -(*ballDX);
    }

    *ballX += *ballDX;
    *ballY += *ballDY;

    board[*ballY][*ballX] = '*';
}

int main(){
    char board[HEIGHT][WIDTH];
    int playerY = HEIGHT/2-1;
    int computerY = HEIGHT/2-1;
    int ballX = WIDTH/2;
    int ballY = HEIGHT/2;
    int ballDX = (rand()%2)?1:-1;
    int ballDY = (rand()%3)-1;
    int playerScore = 0;
    int computerScore = 0;
    char input;

    srand(time(NULL));

    while(playerScore<5 && computerScore<5){
        system("cls");

        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t Player Score: %d\n", playerScore);
        printf("\t\t\t\t\t\t Computer Score: %d\n\n\n", computerScore);

        drawBoard(board, playerY, computerY);

        moveComputer(board, &computerY, ballY);

        if(ballDX == 1){
            movePlayerDown(&playerY);
        }
        else{
            movePlayerUp(&playerY);
        }

        moveBall(board, &ballX, &ballY, &ballDX, &ballDY, &playerY, &computerY, &playerScore, &computerScore);

        printf("\n\nPress Q to quit\n\n");
        printf("Enter your move: ");
        scanf(" %c", &input);
        if(input == 'q' || input == 'Q'){
            break;
        }
    }

    if(playerScore == 5){
        printf("\n\nYou Won!!\n\n");
    }
    else{
        printf("\n\nYou Lost!!\n\n");
    }

    return 0;
}