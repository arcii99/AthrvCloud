//FormAI DATASET v1.0 Category: Dice Roller ; Style: artistic
// A unique dice roller program by the artist in me
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milli_seconds) 
{ 
    // Store start time 
    clock_t start_time = clock(); 
 
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds); 
} 

int main() 
{
    int dice, i, roll, players, num_rolls;
    
    // Set seed for random number generation
    srand(time(NULL));
    
    // Print introduction
    printf("Welcome to the Ultimate Dice Roller!\n\n");
    printf("How many players will be rolling?\n");
    scanf("%d", &players);
    
    // Let user choose number of rolls
    printf("\nHow many times will each player roll?\n");
    scanf("%d", &num_rolls);
    
    // Start rolling
    for(i = 1; i <= players; i++)
    {
        printf("\nPlayer %d, get ready to roll!\n\n", i);
        delay(1000); // Delay for dramatic effect
        for(roll = 1; roll <= num_rolls; roll++)
        {
            printf("Roll number %d: ", roll);
            dice = rand() % 6 + 1; // Generate random number from 1 to 6
            printf("%d\n", dice);
            delay(500); // Delay between rolls
        }
        printf("\n"); // Space between players
    }
    
    printf("Thank you for playing!");
    
    return 0;
}