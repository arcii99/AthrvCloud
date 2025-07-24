//FormAI DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int n)
{
    // This function simulates the rolling of "n" dice and returns the sum of their outcomes.
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        sum += rand() % 6 + 1; // Roll a fair six-sided die.
    }
    return sum;
}

int main()
{
    srand(time(NULL)); // Seed the random number generator.
    
    int num_dice, num_rolls;
    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);
    printf("Enter the number of times to roll the dice: ");
    scanf("%d", &num_rolls);
    
    // Allocate memory for the frequency table.
    int* freq_table = calloc(num_dice * 6 + 1, sizeof(int));
    if (freq_table == NULL) {
        fprintf(stderr, "Error: could not allocate memory\n");
        exit(EXIT_FAILURE);
    }
    
    int i;
    for (i = 0; i < num_rolls; i++) {
        int sum = roll_dice(num_dice);
        freq_table[sum]++;
    }
    
    // Print the frequency table.
    printf("Results:\n");
    for (i = num_dice; i <= num_dice * 6; i++) {
        printf("%2d: %6d\n", i, freq_table[i]);
    }
    
    free(freq_table); // Deallocate memory.
    return 0;
}