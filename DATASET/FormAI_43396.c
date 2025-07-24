//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); //Initialize random seed
    int probability = rand() % 101; //Generate a random number from 0 to 100
    int day = 1; //Initialize the day counter
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("************************************\n\n");
    printf("Welcome to the alien invasion probability calculator!\n\n");
    printf("Today is day %d.\n\n", day);
    printf("The current probability of an alien invasion is %d%%.\n\n", probability);
    while(probability < 95) {
        printf("Day %d:\n", ++day);
        probability += rand() % 11 - 5; //Increase/decrease probability by a random value from -5 to 5
        if(probability < 0) {
            probability = 0; //Probability cannot be negative
        }
        printf("The current probability of an alien invasion is %d%%.\n\n", probability);
    }
    printf("Day %d:\n", ++day); //Increment day counter and print for final result
    printf("The current probability of an alien invasion is %d%%.\n\n", probability);
    printf("WARNING: The probability has exceeded 95%%.\n"); 
    printf("Prepare for an alien invasion!\n");
    return 0;
}