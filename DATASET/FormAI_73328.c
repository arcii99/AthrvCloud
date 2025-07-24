//FormAI DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_dice(int* dice1, int* dice2){
    srand(time(NULL));
    *dice1 = (rand() % 6) + 1;
    *dice2 = (rand() % 6) + 1;
}

int main(){
    int dice1, dice2;
    char answer;

    do{
        roll_dice(&dice1, &dice2);
        printf("You rolled %d & %d\n", dice1, dice2);
        printf("Roll again? (y/n): ");
        scanf(" %c", &answer);

    }while(answer == 'y' || answer == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}