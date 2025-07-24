//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to my Cryptic Dice Roller!\n");
    printf("Please enter the number of sides on your dice: ");
    int sides;
    scanf("%d", &sides);
    printf("How many times would you like to roll the dice? ");
    int rolls;
    scanf("%d", &rolls);
    printf("Rolling the dice %d times with %d sides...\n", rolls, sides);
    srand(time(0)); //seeds random number generator with current time
    int total = 0;
    for (int i = 1; i <= rolls; i++){
        int roll = rand() % sides + 1;
        printf("Roll %d: ", i);
        if (roll == 1){
            printf("The eternal gatekeeper opens upon a vast emptiness, your roll is %d.\n", roll);
        } else if (roll == sides){
            printf("The universe reveals its deepest secrets to you, your roll is the maximum possible of %d.\n", roll);
        } else if ((roll+sides)%2 == 0){
            printf("The shadows dance around you as you roll a %d.\n", roll);
        } else {
            printf("The light shines in your favor as you roll a %d.\n", roll);
        }
        total += roll;
    }
    printf("The total of all your rolls is: %d\n", total);
    printf("Thank you for using my Cryptic Dice Roller! May the odds ever be in your favor.\n");
    return 0;
}