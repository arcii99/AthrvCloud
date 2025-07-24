//FormAI DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate random number between min and max(inclusive)
int getRandomNumber(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){
    int dices, sides, i;
    int total = 0;
    
    printf("Welcome to the C Dice Roller\n");
    printf("How many dices do you want to roll? ");
    scanf("%d", &dices);
    printf("How many sides does each dice have? ");
    scanf("%d", &sides);
    
    //initialize random seed
    srand(time(NULL));
    
    printf("\nYou rolled: ");

    for(i = 0; i < dices; i++){
        int roll = getRandomNumber(1, sides);
        total += roll;
        printf("%d ", roll);
    }
    
    printf("\nTotal: %d\n", total);
    
    return 0;
}