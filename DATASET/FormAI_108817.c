//FormAI DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rolls, sides;
    printf("How many dice would you like to roll? ");
    scanf("%d", &rolls);
    printf("How many sides on each dice? ");
    scanf("%d", &sides);
    printf("\nRolling %d %d-sided dice...\n\n", rolls, sides);
    srand(time(NULL)); //Seed for random number generator
    int total = 0; //Variable for storing total sum of rolls

    for(int i=1; i<=rolls; i++) {
        int roll = rand() % sides + 1; //Random roll between 1 and number of sides
        printf("Die %d: %d\n", i, roll);
        total += roll; //Add roll to total sum
    }

    printf("\nTotal: %d\n", total); //Print total sum of rolls

    return 0;
}