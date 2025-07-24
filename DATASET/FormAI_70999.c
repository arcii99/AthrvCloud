//FormAI DATASET v1.0 Category: Recursive ; Style: puzzling
#include <stdio.h>

void recursive(int num) {
    if (num == 0) {
        printf("\nYou have reached 0! Congrats!\n");
        return;
    }
    
    printf("Enter %d puzzles in front of you: ", num);
    int input;
    scanf("%d", &input);
    
    if (input < num) {
        printf("You didn't enter enough puzzles!\n");
        recursive(num - input);
    } else if (input > num) {
        printf("You entered too many puzzles!\n");
        recursive(num);
    } else {
        printf("You entered the correct number of puzzles. Moving on!\n");
        recursive(num - 1); // We've solved one puzzle, move on to the next one
    }
}

int main() {
    printf("Welcome to the puzzling recursive program!\n");
    printf("How many puzzles do you have in front of you? ");
    int num;
    scanf("%d", &num);
    
    recursive(num);
    
    printf("\nCongratulations on solving the puzzles!\n");
    return 0;
}