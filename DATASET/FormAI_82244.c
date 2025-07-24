//FormAI DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>

#define MAX_ROLLS 100

int main() {
    int rolls[MAX_ROLLS];
    int num_rolls = 0, i;
    double avg_roll = 0;
    
    printf("Enter the number of dice rolls: ");
    scanf("%d", &num_rolls);
    
    if(num_rolls <= 0 || num_rolls > MAX_ROLLS) {
        printf("Invalid number of rolls entered.\n");
        return 1;
    }
    
    printf("Enter the %d dice rolls separated by spaces: ", num_rolls);
    
    for(i = 0; i < num_rolls; i++) {
        scanf("%d", &rolls[i]);
        avg_roll += rolls[i];
    }
    
    // Calculate average roll
    avg_roll /= num_rolls;
    
    // Find minimum and maximum rolls
    int min_roll = rolls[0], max_roll = rolls[0];
    
    for(i = 1; i < num_rolls; i++) {
        if(rolls[i] < min_roll) {
            min_roll = rolls[i];
        }
        if(rolls[i] > max_roll) {
            max_roll = rolls[i];
        }
    }
    
    printf("\nResults:\n");
    printf("Number of rolls: %d\n", num_rolls);
    printf("Average roll: %.2f\n", avg_roll);
    printf("Minimum roll: %d\n", min_roll);
    printf("Maximum roll: %d\n", max_roll);
    
    return 0;
}