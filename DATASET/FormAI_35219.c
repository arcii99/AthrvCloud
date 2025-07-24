//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n, roll, i, sum=0;
    srand(time(0)); // Initializing the random number generator with current time
    
    printf("Enter the number of dice to roll: ");
    scanf("%d", &n);
    
    printf("\nYou have chosen to roll %d dice.\n", n);
    printf("Rolling the dice...\n");
    
    for(i=0; i<n; i++){
        roll = rand() % 6 + 1; // Generating a random number between 1 and 6
        printf("Roll %d: %d\n", i+1, roll);
        sum += roll; // Adding the roll to the total sum
    }
    
    printf("\nTotal sum of all rolls: %d\n", sum);
    
    return 0;
}