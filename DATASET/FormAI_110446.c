//FormAI DATASET v1.0 Category: Dice Roller ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int sides, numRolls, i, j, total=0;
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &sides);

    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    srand((unsigned) time(NULL)); //seeding the random number generator with current time

    printf("Rolling %d %d-sided dice...\n", numRolls, sides);

    for(i=1; i<=numRolls; i++){
        printf("Roll %d: [ ", i);

        int val = rand() % sides + 1; // generating random number between 1 and sides

        printf("%d ", val); // printing the value of current roll

        total += val; // adding current roll to total

        // printing remaining rolls in the same line
        for(j=2; j<=sides; j++){
            val = rand() % sides + 1;
            printf("%d ", val);
            total += val;
        }

        printf("] = %d\n", total); // printing the sum of all rolls in current line

        total = 0; // resetting the total for next line
    }

    return 0; // indicating a successful execution of program
}