//FormAI DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    int rolls, i, face;
    int freq[6] = {0};

    // Get input from user for number of rolls
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &rolls);

    // Seed the random generator
    srand(time(NULL));

    // Roll the dice and record the face value
    for (i = 1; i <= rolls; i++) {
        face = rollDice();
        freq[face-1]++;
    }

    // Display the frequency of each face value
    for (i = 0; i < 6; i++) {
        printf("Face value %d appeared %d times.\n", i+1, freq[i]);
    }

    return 0;
}