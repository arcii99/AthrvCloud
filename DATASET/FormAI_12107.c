//FormAI DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Using current time as seed for random generator
    
    int numRolls;
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &numRolls);
    
    int sides;
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &sides);
    
    int i;
    for(i = 0; i < numRolls; i++) {
        int result = rand() % sides + 1; // Generating random number between 1 and number of sides on the dice 
        printf("Roll %d: %d\n", i+1, result);
    }
    
    return 0;
}