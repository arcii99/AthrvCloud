//FormAI DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the maximum and minimum values for the dice */
#define MAX_DICE 6
#define MIN_DICE 1

/* Define the number of rolls to be performed per trial */
#define NUM_ROLLS 10

/* Define the number of trials to be performed */
#define NUM_TRIALS 5

/* Function to simulate the roll of a single die */
int roll_dice() {
    return rand() % MAX_DICE + MIN_DICE;
}

/* Function to display the results of a single trial */
void print_trial(int trial_num, int rolls[]) {
    printf("Trial %d: ", trial_num);
    for (int i = 0; i < NUM_ROLLS; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

int main() {
    /* Seed the random number generator */
    srand(time(NULL));

    /* Loop through each trial */
    for (int trial_num = 1; trial_num <= NUM_TRIALS; trial_num++) {
        int rolls[NUM_ROLLS];

        /* Roll the dice NUM_ROLLS times */
        for (int i = 0; i < NUM_ROLLS; i++) {
            rolls[i] = roll_dice();
        }

        /* Display the results of the trial */
        print_trial(trial_num, rolls);
    }

    return 0;
}