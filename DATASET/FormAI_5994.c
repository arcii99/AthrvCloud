//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayInstructions(int numOfDisks, int numOfPoles){
    printf("Welcome to the Cyberpunk Tower of Hanoi Simulation!\n");
    printf("In this simulation, you will be solving the Tower of Hanoi Problem.\n");
    printf("You have %d disks and %d poles. Your goal is to move all of the disks from the first pole to the third pole.\n", numOfDisks, numOfPoles);
    printf("Remember, each disk must be placed on a larger disk or an empty pole.\n");
    printf("Let's get started!\n\n");
}

void displayPoles(int poles[][15], int numOfDisks, int numOfPoles){
    for(int i = 0; i < numOfPoles; i++){
        printf("Pole %d: ", i+1);
        for(int j = 0; j < numOfDisks; j++){
            if(poles[i][j]){
                printf("%d ", poles[i][j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

bool checkWin(int poles[][15], int numOfDisks, int numOfPoles){
    for(int i = 0; i < numOfPoles; i++){
        for(int j = 0; j < numOfDisks; j++){
            if(poles[i][j] != j+1 && poles[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

void moveDisk(int poles[][15], int fromPole, int toPole, int numOfDisks){
    for(int i = 0; i < numOfDisks; i++){
        if(poles[fromPole][i] != 0){
            for(int j = numOfDisks-1; j >= 0; j--){
                if(poles[toPole][j] == 0){
                    poles[toPole][j] = poles[fromPole][i];
                    poles[fromPole][i] = 0;
                    break;
                }
            }
            break;
        }
    }
}

void playCyberpunkTowerOfHanoi(int numOfPoles, int numOfDisks){
    int poles[3][15] = {0};
    for(int i = 0; i < numOfDisks; i++){
        poles[0][i] = i+1;
    }

    displayInstructions(numOfDisks, numOfPoles);
    displayPoles(poles, numOfDisks, numOfPoles);

    int turnCount = 0;
    while(!checkWin(poles, numOfDisks, numOfPoles)){
        turnCount++;

        int fromPole, toPole;
        printf("Turn #%d: Enter the pole number you would like to move from: ", turnCount);
        scanf("%d", &fromPole);
        printf("Enter the pole number you would like to move to: ");
        scanf("%d",&toPole);
        printf("\n");

        if(fromPole > 0 && fromPole <= numOfPoles && toPole > 0 && toPole <= numOfPoles && fromPole != toPole){
            moveDisk(poles, fromPole-1, toPole-1, numOfDisks);
            displayPoles(poles, numOfDisks, numOfPoles);
        } else {
            printf("***Invalid Input!***\n");
        }
    }

    printf("Congratulations! You have won the Cyberpunk Tower of Hanoi Simulation!\n");
    printf("It took you %d turns.\n", turnCount);
}

int main(){
    playCyberpunkTowerOfHanoi(3,4);
    return 0;
}