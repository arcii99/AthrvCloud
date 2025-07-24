//FormAI DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int diceRoll();

int main(){
    int result = diceRoll();
    printf("The result of the dice roll is: %d\n", result);
    return 0;
}

int diceRoll(){
    int sides = 6;
    int result;
    srand(time(NULL));
    result = rand()%sides + 1;
    return result;
}