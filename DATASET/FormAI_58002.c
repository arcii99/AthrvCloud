//FormAI DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h> // Include standard I/O header file for input/output operations
#include <stdlib.h> // Include standard library header file for rand() function

/* This function generates a random number between 1 and 6 and returns it */
int roll_dice() {
    return rand() % 6 + 1;
}

/* This function takes in the number of rolls to perform and prints the result */
void roll_multiple_dice(int num_rolls) {
    int i, curr_roll;
    
    printf("%d dice rolls:\n", num_rolls);
    
    for(i=1; i<=num_rolls; i++) {
        curr_roll = roll_dice();
        printf("Roll %d: %d\n", i, curr_roll);
    }
}

/* Main function - entry point for program execution */
int main() {
    int num_rolls;
    
    printf("Welcome to the Dice Roller program!\n");
    printf("Please enter the number of rolls: ");
    scanf("%d", &num_rolls);
    
    roll_multiple_dice(num_rolls); // Call function to perform dice rolls
    
    printf("Thank you for using the Dice Roller program.\n");
    
    return 0;
}