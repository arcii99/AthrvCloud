//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    printf("Welcome to our new and exciting game: Boredom Buster\n");
    printf("Get ready to battle boredom by playing this fun filled game full of surprises and excitement!\n");
    printf("Instructions:\n");
    printf("You will start in the center of the game board. You must navigate to the other side while avoiding obstacles and collecting coins along the way.\n");

    int boardSize = 10;
    int playerPosition = boardSize/2;

    char gameBoard[boardSize][boardSize];
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(i==playerPosition && j==0){
                gameBoard[i][j] = 'O';
            }
            else if(i==0 || i==boardSize-1){
                gameBoard[i][j] = '-';
            }
            else{
                gameBoard[i][j] = ' ';
            }
        }
    }

    int obstaclePositions[boardSize];
    int coinPositions[boardSize];
    for(int i=0;i<boardSize;i++){
        obstaclePositions[i] = rand() % boardSize;
        coinPositions[i] = rand() % boardSize;
    }

    int score = 0;
    printf("Press any key to start!\n");
    getchar();

    while(playerPosition!=boardSize-1){

        system("clear");

        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                if(i==playerPosition && j==0){
                    gameBoard[i][j] = 'O';
                }
                else if(i==0 || i==boardSize-1){
                    gameBoard[i][j] = '-';
                }
                else if(i==obstaclePositions[i] && j==i){
                    gameBoard[i][j] = 'X';
                }
                else if(i==coinPositions[i] && j==i){
                    gameBoard[i][j] = '$';
                }
                else{
                    gameBoard[i][j] = ' ';
                }
                printf("%c ",gameBoard[i][j]);
            }
            printf("\n");
        }

        printf("Score: %d\n",score);
        printf("Use 'W' and 'S' to move up and down.\n");
        printf("Avoid the obstacles and collect the coins!\n");

        char input;
        scanf("%c",&input);

        if(input == 'w'){
            if(playerPosition > 1){
                playerPosition -= 1;
            }
        }
        else if(input == 's'){
            if(playerPosition < boardSize-2){
                playerPosition += 1;
            }
        }
        for(int i=0;i<boardSize;i++){
            if(obstaclePositions[i] == playerPosition && i<boardSize-1){
                score -= 1;
                obstaclePositions[i] = rand() % boardSize;
            }
            if(coinPositions[i] == playerPosition && i<boardSize-1){
                score += 1;
                coinPositions[i] = rand() % boardSize;
            }
        }

    }

    printf("Congratulations! You have reached the other side of the board!\n");
    printf("Final Score: %d\n",score);

    return 0;

}