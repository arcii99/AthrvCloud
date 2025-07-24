//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

void shapeshiftingGame(int level);//function declaration

int main(){
    int level;
    printf("Welcome to the Shape Shifting Game!\n");
    printf("Enter the level of the game (1 - 5): ");
    scanf("%d",&level);
    shapeshiftingGame(level);//calling function
    printf("\n\nCongratulations, You have completed Level %d!\n",level);
    return 0;
}

void shapeshiftingGame(int level){
    int i,correct, randomNumber, input, score=0;
    char shape[]={'C','T','S','-',':'};//array of shape characters
    srand(time(NULL));
    for(i=1;i<=10;i++){//10 rounds in each level of the game
        correct=rand()%5;//generating random number to select a correct shape
        printf("\n\nRound %d",i);
        printf("\nWhich Shape is correct?\n");
        for(int j=0;j<5;j++){//printing shapes with respective indexes
            printf("%d - %c    ",j+1,shape[j]);
        }
        printf("\nEnter the index of chosen Shape: ");
        scanf("%d",&input);
        input--;//reducing one to match the array index
        if(input==correct){
            printf("\nCongratulations, You are correct!");
            score++;
        }
        else{
            printf("\nSorry, You are incorrect!");
        }
    }
    printf("\n\nTotal Score: %d/10",score);//print final score
}