//FormAI DATASET v1.0 Category: Dice Roller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int num_sides) {
    return rand() % num_sides + 1;
}

int main() {
    int num_dice, num_sides, total = 0;
    srand(time(NULL));
    
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides per die: ");
    scanf("%d", &num_sides);
    
    printf("\nRolling %d %d-sided dice...\n", num_dice, num_sides);
    
    for (int i = 0; i < num_dice; i++) {
        int roll = roll_dice(num_sides);
        printf("Die #%d: %d\n", i+1, roll);
        total += roll;
    }
    
    printf("\nTotal: %d\n", total);
    
    return 0;
}