//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include<stdio.h>

int main() {

    int steps = 0, calories = 0, time = 0;

    printf("Welcome to C Fitness Tracker\n");

    while(1) {

        printf("\nEnter the number of steps taken: ");
        scanf("%d", &steps);

        printf("Enter the amount of time spent walking (in minutes): ");
        scanf("%d", &time);

        calories = steps * 0.05;

        printf("You have burned %d calories by taking %d steps in %d minutes\n", calories, steps, time);

        if(time >= 30) {
            printf("You have been walking for %d minutes, take a break and rest your legs!\n", time);
        }
    }

    return 0;
}