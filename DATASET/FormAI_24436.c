//FormAI DATASET v1.0 Category: Dice Roller ; Style: scientific
#include <stdio.h> // to include input and output operations
#include <stdlib.h> // to seed the random number generator
#include <time.h> // to get the current time for the seed

int main()
{
    srand(time(NULL)); // seed the random number generator

    int n; // number of dice
    int m; // number of sides

    // prompt user for number of dice and number of sides
    printf("Enter the number of dice: ");
    scanf("%d", &n);
    printf("Enter the number of sides: ");
    scanf("%d", &m);

    int rolls[n]; // array to hold the rolls

    // roll the dice
    for(int i = 0; i < n; i++) {
        rolls[i] = rand() % m + 1; // generate a random number between 1 and m
    }

    // print out the rolls
    printf("You rolled: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");

    return 0;
}