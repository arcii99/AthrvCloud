//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>

int main() {
    int steps = 0; 
    float distance = 0; 
    int calories = 0; 
    int goal = 10000; 
    int input;

    printf("Welcome to Our Fitness Tracker!\n");
    printf("Please enter your steps taken today: ");
    scanf("%d", &input);

    steps += input;
    distance = (steps * 0.0005);
    calories = (steps * 0.05);

    printf("You've walked %.2f miles today!\n", distance);
    printf("You've burned %d calories today!\n", calories);

    if (steps < goal) {
        printf("You're %d steps away from your goal!\n", goal - steps);
    }
    else {
        printf("Congratulations! You've reached your step goal for today!\n");
    }

    return 0;
}