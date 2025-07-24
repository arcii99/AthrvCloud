//FormAI DATASET v1.0 Category: Dice Roller ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void roll_dice(int num_dice, int num_sides){
    int i, total=0, roll_value;
    printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);
    for(i=0;i<num_dice;i++){
        roll_value = (rand() % num_sides) + 1;
        printf("Dice %d: %d\n", (i+1), roll_value);
        total += roll_value;
    }
    printf("Total: %d\n", total);
}

int main(){
    int num_dice, num_sides;
    srand(time(NULL));
    printf("Welcome to the Dice Roller program!\n");
    printf("Please enter the number of dice to roll: ");
    scanf("%d", &num_dice);
    printf("Please enter the number of sides per die: ");
    scanf("%d", &num_sides);
    roll_dice(num_dice, num_sides);
    return 0;
}