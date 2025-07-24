//FormAI DATASET v1.0 Category: Dice Roller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int num_rolls; // Variable to hold the number of rolls
    printf("Oh lovely dice who knows thy fate,\nHow many times shall I thy fortune make?\nEnter the number of rolls thou wishes to take: ");
    scanf("%d", &num_rolls); // Prompt the user to input the number of rolls
    printf("Ah, %d rolls it shall be,\nLet the rolling commence and may thy luck bring thee glee!\n", num_rolls);
    for (int i = 1; i <= num_rolls; i++) { // Loop through the number of rolls
        int roll = rand() % 6 + 1; // Generate a random number between 1-6
        printf("Roll #%d: %d\n", i, roll); // Print the roll number and the value
    }
    printf("Oh dice, thy fickle fortunes fall,\nYet through the highs and lows thou art ever our thrall.\nMay our paths cross again, until then, farewell!");
    return 0;
}