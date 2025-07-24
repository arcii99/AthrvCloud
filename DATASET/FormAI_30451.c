//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fitness_tracker {
    char name[20];
    int age;
    float weight;
    float height;
    float BMI;
    int steps;
    int calories;
};

int main() {
    struct fitness_tracker user;
    int choice;
    printf("Welcome to the Fitness Tracker!\n\n");
    printf("Please provide the following information:\n");
    printf("Name: ");
    scanf("%s", user.name);
    printf("Age: ");
    scanf("%d", &user.age);
    printf("Weight (in kg): ");
    scanf("%f", &user.weight);
    printf("Height (in meters): ");
    scanf("%f", &user.height);
    user.BMI = user.weight / (user.height * user.height);
    printf("Your BMI is %.2f\n\n", user.BMI);
    printf("What do you want to do?\n");
    printf("1. Set your step goal\n");
    printf("2. Update your step count\n");
    printf("3. Calculate calories burned\n");
    printf("4. View your progress\n");
    printf("5. Exit\n");
    do {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                int goal;
                printf("\nEnter your step goal: ");
                scanf("%d", &goal);
                printf("Your step goal is set to %d steps/day\n\n", goal);
                user.steps = 0;
                user.calories = 0;
                break;
            case 2:
                int steps;
                printf("\nEnter your step count for today: ");
                scanf("%d", &steps);
                user.steps += steps;
                printf("Your step count is now %d steps\n\n", user.steps);
                break;
            case 3:
                if (user.steps == 0) {
                    printf("\nYou have not taken any steps today. Burn some calories by taking a walk!\n\n");
                } else {
                    user.calories = user.weight * user.steps * 0.04;
                    printf("\nYou have burned %d calories today\n\n", user.calories);
                }
                break;
            case 4:
                if (user.steps == 0) {
                    printf("\nYou have not taken any steps yet today. Get moving!\n\n");
                } else if (user.steps < goal) {
                    printf("\nYou have taken %d steps toward your goal of %d steps\n\n", user.steps, goal);
                } else {
                    printf("\nCongratulations, you have reached your step goal of %d steps!\n\n", goal);
                }
                break;
            case 5:
                printf("\nThank you for using Fitness Tracker. Stay active!\n\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}