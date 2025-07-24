//FormAI DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int sides, rolls, result, total = 0;
    
    srand(time(NULL)); // seed the random number generator with system time
    
    printf("Welcome to the Dice Roller\n");
    printf("------------------------\n");
    
    // get number of sides on the dice
    printf("Enter the number of sides on the dice (e.g. 6 for a standard six-sided die): ");
    scanf("%d", &sides);
    
    // get number of times to roll the dice
    printf("Enter the number of times to roll the dice: ");
    scanf("%d", &rolls);
    
    // roll the dice the specified number of times and output the results
    printf("\nRolling the dice...\n");
    
    for(int i = 1; i <= rolls; i++){
        result = (rand() % sides) + 1;
        printf("Roll %d: %d\n", i, result);
        total += result;
    }
    
    // output the total of all rolls
    printf("\nTotal: %d\n", total);
    
    return 0;
}