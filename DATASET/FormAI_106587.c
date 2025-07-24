//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j, temp;
    int count = 0;
    int bingo[5][5]; //bingo card 5x5

    //Generate random numbers and populate bingo card
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if((i == 2)&&(j == 2)) //middle spot is free
                bingo[i][j] = 0;
            else //generate random number between 1 and 75
                bingo[i][j] = (rand() % 75) + 1;
        }
    }

    //Print out bingo card before game starts
    printf("B I N G O\n");
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("%d ", bingo[i][j]);
        }
        printf("\n");
    }

    //Play the game
    srand(time(0));
    while(count < 24){ //24 numbers called for a full card
        printf("Press Enter to call a number: ");
        getchar();

        //generate random number
        int numberCalled = (rand() % 75) + 1;
        printf("Number called: %d\n", numberCalled);

        //mark the number on the card if it exists
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(bingo[i][j] == numberCalled){
                    bingo[i][j] = 0;
                    printf("Marked %d on the card!\n", numberCalled);
                }
            }
        }

        //check for bingo
        temp = 0;
        //rows
        for(i=0; i<5; i++){
            temp = 0;
            for(j=0; j<5; j++){
                temp += bingo[i][j];
            }
            if(temp == 0){
                printf("BINGO! Row %d!\n", i+1);
                count++;
            }
        }
        //columns
        for(j=0; j<5; j++){
            temp = 0;
            for(i=0; i<5; i++){
                temp += bingo[i][j];
            }
            if(temp == 0){
                printf("BINGO! Column %d!\n", j+1);
                count++;
            }
        }
        //diagonals
        if((bingo[0][0]+bingo[1][1]+bingo[2][2]+bingo[3][3]+bingo[4][4]) == 0){
            printf("BINGO! Diagonal from top left to bottom right!\n");
            count++;
        }
        if((bingo[0][4]+bingo[1][3]+bingo[2][2]+bingo[3][1]+bingo[4][0]) == 0){
            printf("BINGO! Diagonal from top right to bottom left!\n");
            count++;
        }

    }

    printf("\nCongratulations! You got BINGO!\n");

    return 0;
}